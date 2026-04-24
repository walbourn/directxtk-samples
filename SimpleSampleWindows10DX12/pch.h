//
// pch.h
// Header for standard system include files.
//

#pragma once

// Use the C++ standard templated min/max
#define NOMINMAX

#include <wrl.h>

#include <d3d12.h>
#include <dxgi1_6.h>

#include <DirectXMath.h>
#include <DirectXColors.h>

#include "d3dx12.h"

#include <algorithm>
#include <atomic>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <exception>
#include <future>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <system_error>
#include <tuple>

// To use graphics and CPU markup events with the latest version of PIX, change this to include <pix3.h>
// then add the NuGet package WinPixEventRuntime to the project.
#include <pix.h>

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include "directxtk12/Audio.h"
#include "directxtk12/CommonStates.h"
#include "directxtk12/DirectXHelpers.h"
#include "directxtk12/DDSTextureLoader.h"
#include "directxtk12/DescriptorHeap.h"
#include "directxtk12/Effects.h"
#include "directxtk12/GamePad.h"
#include "directxtk12/GeometricPrimitive.h"
#include "directxtk12/GraphicsMemory.h"
#include "directxtk12/Keyboard.h"
#include "directxtk12/Model.h"
#include "directxtk12/Mouse.h"
#include "directxtk12/PrimitiveBatch.h"
#include "directxtk12/ResourceUploadBatch.h"
#include "directxtk12/RenderTargetState.h"
#include "directxtk12/SimpleMath.h"
#include "directxtk12/SpriteBatch.h"
#include "directxtk12/SpriteFont.h"
#include "directxtk12/VertexTypes.h"

namespace DX
{
    // Helper class for COM exceptions
    class com_exception : public std::exception
    {
    public:
        com_exception(HRESULT hr) noexcept : result(hr) {}

        const char* what() const override
        {
            static char s_str[64] = {};
            sprintf_s(s_str, "Failure with HRESULT of %08X", static_cast<unsigned int>(result));
            return s_str;
        }

    private:
        HRESULT result;
    };

    // Helper utility converts D3D API failures into exceptions.
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            throw com_exception(hr);
        }
    }
}