//--------------------------------------------------------------------------------------
// File: SimpleSampleMain.h
//
// This is a simple Windows Store app for Windows 8.1 Preview showing use of DirectXTK
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

#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\DirectXTK3DSceneRenderer.h"

// Renders Direct2D and 3D content on the screen.
namespace SimpleSample
{
	class SimpleSampleMain : public DX::IDeviceNotify
	{
	public:
		SimpleSampleMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~SimpleSampleMain();
		void CreateWindowSizeDependentResources();
		void Update();
		bool Render();

        // Signals a new audio device is available
        void NewAudioDevice();

		// IDeviceNotify
		virtual void OnDeviceLost();
        virtual void OnDeviceRestored();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		std::unique_ptr<DirectXTK3DSceneRenderer> m_sceneRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;
	};
}