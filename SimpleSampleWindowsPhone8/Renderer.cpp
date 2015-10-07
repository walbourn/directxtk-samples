//--------------------------------------------------------------------------------------
// File: Renderer.cpp
//
// This is a simple Windows Store app showing use of DirectXTK
//
// http://go.microsoft.com/fwlink/?LinkId=248929
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "Renderer.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::Graphics::Display;

Renderer::Renderer()
{
}

void Renderer::CreateDeviceResources()
{
	Direct3DBase::CreateDeviceResources();

    // Create DirectXTK objects
    auto device = m_d3dDevice.Get();
    m_states.reset( new CommonStates( device ) );

    auto fx = new EffectFactory( device );
    fx->SetDirectory( L"Assets" );
    m_fxFactory.reset( fx );

    auto context = m_d3dContext.Get();
    m_sprites.reset( new SpriteBatch( context ) );
    m_batch.reset( new PrimitiveBatch<VertexPositionColor>( context ) );

    m_batchEffect.reset( new BasicEffect( device ) );
    m_batchEffect->SetVertexColorEnabled(true);

    {
        void const* shaderByteCode;
        size_t byteCodeLength;

        m_batchEffect->GetVertexShaderBytecode( &shaderByteCode, &byteCodeLength );

        DX::ThrowIfFailed(
            device->CreateInputLayout( VertexPositionColor::InputElements,
                                        VertexPositionColor::InputElementCount,
                                        shaderByteCode, byteCodeLength,
                                        m_batchInputLayout.ReleaseAndGetAddressOf() ) 
                         );
    }

    m_font.reset( new SpriteFont( device, L"assets\\italic.spritefont" ) );

    m_shape = GeometricPrimitive::CreateTeapot( context, 4.f, 8 );

    // SDKMESH has to use clockwise winding with right-handed coordinates, so textures are flipped in U
    m_model = Model::CreateFromSDKMESH( device, L"assets\\tiny.sdkmesh", *m_fxFactory );

    // Load textures
    DX::ThrowIfFailed(
        CreateDDSTextureFromFile( device, L"assets\\seafloor.dds", nullptr, m_texture1.ReleaseAndGetAddressOf() )
                     );

    DX::ThrowIfFailed(
        CreateDDSTextureFromFile( device, L"assets\\windowslogo.dds", nullptr, m_texture2.ReleaseAndGetAddressOf() )
                     );
}

void Renderer::CreateWindowSizeDependentResources()
{
	Direct3DBase::CreateWindowSizeDependentResources();

    float aspectRatio = m_orientedScreenSize.Width / m_orientedScreenSize.Height;
	float fovAngleY = 70.0f * XM_PI / 180.0f;

	// Note that the m_orientationTransform3D matrix is post-multiplied here
	// in order to correctly orient the scene to match the display orientation.
	// This post-multiplication step is required for any draw calls that are
	// made to the swap chain render target. For draw calls to other targets,
	// this transform should not be applied.

    Matrix perspectiveMatrix = Matrix::CreatePerspectiveFieldOfView(
        fovAngleY,
        aspectRatio,
        0.01f,
        100.0f
        );

    Matrix orientationMatrix = m_orientationTransform3D;

    m_projection = perspectiveMatrix * orientationMatrix;

    m_batchEffect->SetProjection(m_projection);

    DXGI_MODE_ROTATION rotation = DXGI_MODE_ROTATION_UNSPECIFIED;
    switch (m_orientation)
    {
    case DisplayOrientations::Portrait:
        rotation = DXGI_MODE_ROTATION_IDENTITY;
        break;

    case DisplayOrientations::Landscape:
        rotation = DXGI_MODE_ROTATION_ROTATE90;
        break;

    case DisplayOrientations::PortraitFlipped:
        rotation = DXGI_MODE_ROTATION_ROTATE180;
        break;

    case DisplayOrientations::LandscapeFlipped:
        rotation = DXGI_MODE_ROTATION_ROTATE270;
        break;
    }

    m_sprites->SetRotation(rotation);

    // Create DirectXTK for Audio objects
    AUDIO_ENGINE_FLAGS eflags = AudioEngine_Default;
#ifdef _DEBUG
    eflags = eflags | AudioEngine_Debug;
#endif
    m_audEngine.reset(new AudioEngine(eflags));

    m_audioEvent = 0;
    m_audioTimerAcc = 10.f;
    m_retryDefault = false;

    m_waveBank.reset(new WaveBank(m_audEngine.get(), L"assets\\adpcmdroid.xwb"));
    m_soundEffect.reset(new SoundEffect(m_audEngine.get(), L"assets\\MusicMono_adpcm.wav"));
    m_effect1 = m_soundEffect->CreateInstance();
    m_effect2 = m_waveBank->CreateInstance(10);

    m_effect1->Play(true);
    m_effect2->Play();
}

void Renderer::Update(float timeTotal, float timeDelta)
{
    UNREFERENCED_PARAMETER( timeDelta );

    Vector3 eye(0.0f, 0.7f, 1.5f);
    Vector3 at(0.0f, -0.1f, 0.0f);

    m_view = Matrix::CreateLookAt(eye, at, Vector3::UnitY);

    m_world = Matrix::CreateRotationY(timeTotal * XM_PIDIV4);

    m_batchEffect->SetView(m_view);
    m_batchEffect->SetWorld(Matrix::Identity);

    m_audioTimerAcc -= timeDelta;
    if (m_audioTimerAcc < 0)
    {
        if (m_retryDefault)
        {
            m_retryDefault = false;
            if (m_audEngine->Reset())
            {
                // Restart looping audio
                m_effect1->Play(true);
            }
        }
        else
        {
            m_audioTimerAcc = 4.f;

            m_waveBank->Play(m_audioEvent++);

            if (m_audioEvent >= 11)
                m_audioEvent = 0;
        }
    }

    if (!m_audEngine->IsCriticalError() && m_audEngine->Update())
    {
        // Setup a retry in 1 second (can happen when transitioning to and from a BlueTooth audio connection)
        m_audioTimerAcc = 1.f;
        m_retryDefault = true;
    }
}

void Renderer::DrawGrid( FXMVECTOR xAxis, FXMVECTOR yAxis, FXMVECTOR origin, size_t xdivs, size_t ydivs, GXMVECTOR color )
{
    auto context = m_d3dContext.Get();
    context->OMSetBlendState(m_states->Opaque(), nullptr, 0xFFFFFFFF);
    context->OMSetDepthStencilState(m_states->DepthNone(), 0);
    context->RSSetState(m_states->CullCounterClockwise());

    m_batchEffect->Apply( context );

    context->IASetInputLayout( m_batchInputLayout.Get() );

    m_batch->Begin();

    xdivs = std::max<size_t>( 1, xdivs );
    ydivs = std::max<size_t>( 1, ydivs );

    for( size_t i = 0; i <= xdivs; ++i )
    {
        float fPercent = float(i) / float(xdivs);
        fPercent = ( fPercent * 2.0f ) - 1.0f;
        XMVECTOR vScale = XMVectorScale( xAxis, fPercent );
        vScale = XMVectorAdd( vScale, origin );

        VertexPositionColor v1( XMVectorSubtract( vScale, yAxis ), color );
        VertexPositionColor v2( XMVectorAdd( vScale, yAxis ), color );
        m_batch->DrawLine( v1, v2 );
    }

    for( size_t i = 0; i <= ydivs; i++ )
    {
        FLOAT fPercent = float(i) / float(ydivs);
        fPercent = ( fPercent * 2.0f ) - 1.0f;
        XMVECTOR vScale = XMVectorScale( yAxis, fPercent );
        vScale = XMVectorAdd( vScale, origin );

        VertexPositionColor v1( XMVectorSubtract( vScale, xAxis ), color );
        VertexPositionColor v2( XMVectorAdd( vScale, xAxis ), color );
        m_batch->DrawLine( v1, v2 );
    }

    m_batch->End();
}

void Renderer::Render()
{
	m_d3dContext->ClearRenderTargetView(
		m_renderTargetView.Get(),
		Colors::MidnightBlue
		);

	m_d3dContext->ClearDepthStencilView(
		m_depthStencilView.Get(),
		D3D11_CLEAR_DEPTH,
		1.0f,
		0
		);

	m_d3dContext->OMSetRenderTargets(
		1,
		m_renderTargetView.GetAddressOf(),
		m_depthStencilView.Get()
		);

    // Draw procedurally generated dynamic grid
    const XMVECTORF32 xaxis = { 20.f, 0.f, 0.f };
    const XMVECTORF32 yaxis = { 0.f, 0.f, 20.f };
    DrawGrid( xaxis, yaxis, g_XMZero, 20, 20, Colors::Gray );

    // Draw sprite
    m_sprites->Begin();
    m_sprites->Draw( m_texture2.Get(), XMFLOAT2(10,75), nullptr, Colors::White );

    m_font->DrawString( m_sprites.get(), L"DirectXTK Simple Sample", XMFLOAT2( 10, 10 ), Colors::Yellow );
    m_sprites->End();

    // Draw 3D object
    XMMATRIX local = m_world * Matrix::CreateTranslation(-2.f, -2.f, -4.f);
    m_shape->Draw(local, m_view, m_projection, Colors::White, m_texture1.Get());

    const XMVECTORF32 scale = { 0.01f, 0.01f, 0.01f };
    const XMVECTORF32 translate = { 3.f, -2.f, -4.f };
    XMVECTOR rotate = Quaternion::CreateFromYawPitchRoll(XM_PI / 2.f, 0.f, -XM_PI / 2.f);
    local = m_world * XMMatrixTransformation(g_XMZero, Quaternion::Identity, scale, g_XMZero, rotate, translate);
    m_model->Draw(m_d3dContext.Get(), *m_states, local, m_view, m_projection);
}
