#include"pch.h"
#include"TesseractFrameworkRendererD3D9.h"

namespace TesseractFramework
{
	TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::TesseractFrameworkRendererD3D9()
		: TesseractFrameworkRenderer()
	{
		this->m_pD3D9 = nullptr;
		this->m_pD3DDevice9 = nullptr;
		this->m_pPresetParameters = {};
	}

	TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::~TesseractFrameworkRendererD3D9()
	{
	}

	bool TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::initializeRenderer()
	{
		m_pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);
		if (m_pD3D9 == NULL)
		{
			MessageBox(NULL, "Could not initialize Direct3D9", "Something went wrong.", MB_OK | MB_ICONINFORMATION);
			return false;
		}
		// Add the interface to the stack.
		m_pInterfaces.push(m_pD3D9);
		return TesseractFrameworkRenderer::initializeRenderer();
	}

	bool TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::configureRenderer(const RendererProperties& properties)
	{
		this->m_pRenderProperties = properties;

		D3DDISPLAYMODE dispMode = {};
		m_pD3D9->GetAdapterDisplayMode(0, &dispMode);
		// Set present parameters.
		m_pPresetParameters.BackBufferCount = m_pRenderProperties.backbufferCount;
		// Check whether in fullscreen.
		if (m_pRenderProperties.fullScreen)
		{
			m_pPresetParameters.BackBufferWidth = dispMode.Width;
			m_pPresetParameters.BackBufferHeight = dispMode.Height;
			m_pPresetParameters.BackBufferFormat = dispMode.Format;
			m_pPresetParameters.FullScreen_RefreshRateInHz = dispMode.RefreshRate;
		}
		else
		{
			m_pPresetParameters.BackBufferWidth = m_pRenderProperties.backbufferWinWidth;
			m_pPresetParameters.BackBufferHeight = m_pRenderProperties.backbufferWinHeight;
			m_pPresetParameters.BackBufferFormat = D3DFMT_A8R8G8B8;
			m_pPresetParameters.FullScreen_RefreshRateInHz = 0;
		}
		if (m_pRenderProperties.stencil)
		{
			m_pPresetParameters.EnableAutoDepthStencil = true;
			m_pPresetParameters.AutoDepthStencilFormat = D3DFMT_D24S8;
		}
		// turn on vSync and switch the level.
		if (m_pRenderProperties.vSync.bVerticalSync)
		{
			switch (m_pRenderProperties.vSync.vSyncLevel)
			{
			case 0:
			case 1:
				m_pPresetParameters.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
				break;
			case 2:
				m_pPresetParameters.PresentationInterval = D3DPRESENT_INTERVAL_TWO;
				break;
			case 3:
				m_pPresetParameters.PresentationInterval = D3DPRESENT_INTERVAL_THREE;
				break;
			case 4:
				m_pPresetParameters.PresentationInterval = D3DPRESENT_INTERVAL_FOUR;
				break;
			case 5:
				m_pPresetParameters.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
				break;
			default:
				m_pPresetParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
				break;
			}
		}
		// multisamples.
		switch (m_pRenderProperties.multiSamples.multiSamples)
		{
		case 0:
		case 1:
		case 2:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_2_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 3:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_3_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 4:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_4_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 5:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_5_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 6:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_6_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 7:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_7_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 8:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_8_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 9:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_9_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 10:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_10_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 11:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_11_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 12:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_12_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 13:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_13_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 14:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_14_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 15:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_15_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		case 16:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_16_SAMPLES;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality;
			break;
		default:
			m_pPresetParameters.MultiSampleType = D3DMULTISAMPLE_NONE;
			m_pPresetParameters.MultiSampleQuality = m_pRenderProperties.multiSamples.multiSamplesQuality = 0;
			break;
		}
		m_pPresetParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
		m_pPresetParameters.Windowed = (!m_pRenderProperties.fullScreen);
		m_pPresetParameters.hDeviceWindow = m_pRenderProperties.winHandle;

		HRESULT hr = m_pD3D9->CreateDevice(0, D3DDEVTYPE_HAL,
			m_pRenderProperties.winHandle,
			D3DCREATE_HARDWARE_VERTEXPROCESSING,
			&m_pPresetParameters,
			&m_pD3DDevice9);

		if (FAILED(hr))
		{
			const char* error = DXGetErrorDescription(hr);
			MessageBox(NULL, error, "Could not create device.", MB_OK | MB_ICONERROR);
			return false;
		}
		m_pInterfaces.push(m_pD3DDevice9);
		return TesseractFrameworkRenderer::configureRenderer(properties);
	}

	bool TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::configureRenderer(HWND hWnd,
		unsigned int backbufferCount,
		unsigned int backbufferWidth,
		unsigned int backbufferHeight,
		bool fullscreen)
	{
		return TesseractFrameworkRenderer::configureRenderer(hWnd, backbufferCount, backbufferWidth, backbufferHeight, fullscreen);
	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::clear(float alpha, float red, float green, float blue)
	{
		D3DXCOLOR color = {};
		m_pColor[0] = alpha;
		m_pColor[1] = red;
		m_pColor[2] = green;
		m_pColor[3] = blue;
		color.a = m_pColor[0];
		color.r = m_pColor[1];
		color.g = m_pColor[2];
		color.b = m_pColor[3];
		m_pD3DDevice9->Clear(0, 0, D3DCLEAR_TARGET, color, 1.0f, 1);
	}
	void TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::begin()
	{
		m_pD3DDevice9->BeginScene();
	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::end()
	{
		m_pD3DDevice9->EndScene();
	}
	void TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9::present()
	{
		m_pD3DDevice9->Present(0, 0, 0, 0);
	}
}