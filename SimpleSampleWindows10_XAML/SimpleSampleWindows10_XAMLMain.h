#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Content\DirectXTK3DSceneRenderer.h"

// Renders Direct2D and 3D content on the screen.
namespace SimpleSampleWindows10_XAML
{
	class SimpleSampleWindows10_XAMLMain : public DX::IDeviceNotify
	{
	public:
		SimpleSampleWindows10_XAMLMain(const std::shared_ptr<DX::DeviceResources>& deviceResources);
		~SimpleSampleWindows10_XAMLMain();
		void CreateWindowSizeDependentResources();
		void StartTracking() { m_sceneRenderer->StartTracking(); }
		void TrackingUpdate(float positionX) { m_pointerLocationX = positionX; }
		void StopTracking() { m_sceneRenderer->StopTracking(); }
		bool IsTracking() { return m_sceneRenderer->IsTracking(); }
        void StartRenderLoop();
		void StopRenderLoop();
		Concurrency::critical_section& GetCriticalSection() { return m_criticalSection; }

		// IDeviceNotify
		virtual void OnDeviceLost();
		virtual void OnDeviceRestored();

	private:
		void ProcessInput();
		void Update();
		bool Render();

		// Cached pointer to device resources.
		std::shared_ptr<DX::DeviceResources> m_deviceResources;

		// TODO: Replace with your own content renderers.
        std::unique_ptr<DirectXTK3DSceneRenderer> m_sceneRenderer;

		Windows::Foundation::IAsyncAction^ m_renderLoopWorker;
		Concurrency::critical_section m_criticalSection;

		// Rendering loop timer.
		DX::StepTimer m_timer;

		// Track current input pointer position.
		float m_pointerLocationX;
	};
}