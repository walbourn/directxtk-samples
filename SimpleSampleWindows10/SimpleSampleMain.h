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

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
		std::unique_ptr<DirectXTK3DSceneRenderer> m_sceneRenderer;

		// Rendering loop timer.
		DX::StepTimer m_timer;
	};
}