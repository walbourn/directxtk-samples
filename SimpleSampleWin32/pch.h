//
// pch.h
// Header for standard system include files.
//

#pragma once

#include <winsdkver.h>
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0603
#endif
#include <sdkddkver.h>

// Use the C++ standard templated min/max
#define NOMINMAX

// DirectX apps don't need GDI
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// Include <mcx.h> if you need this
#define NOMCX

// Include <winsvc.h> if you need this
#define NOSERVICE

// WinHelp is deprecated
#define NOHELP

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <wrl/client.h>

#include <d3d11_1.h>
#include <dxgi1_6.h>

#include <DirectXMath.h>
#include <DirectXColors.h>

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
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <system_error>
#include <tuple>

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#include "directxtk/Audio.h"
#include "directxtk/CommonStates.h"
#include "directxtk/DDSTextureLoader.h"
#include "directxtk/DirectXHelpers.h"
#include "directxtk/Effects.h"
#include "directxtk/GamePad.h"
#include "directxtk/GeometricPrimitive.h"
#include "directxtk/Keyboard.h"
#include "directxtk/Model.h"
#include "directxtk/Mouse.h"
#include "directxtk/PrimitiveBatch.h"
#include "directxtk/SimpleMath.h"
#include "directxtk/SpriteBatch.h"
#include "directxtk/SpriteFont.h"
#include "directxtk/VertexTypes.h"

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
