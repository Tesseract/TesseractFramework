#pragma once

#include "Direct3DIncludes.h"
#include "FrameworkExport.h"
#include <windef.h>
#include<string>

namespace TesseractFramework
{
	typedef struct VerticalSync {
		bool bVerticalSync;
		unsigned int vSyncLevel;
	} VerticalSync, *LPVerticalSync;

	typedef struct MultiSamples {
		unsigned int multiSamples;
		unsigned long int multiSamplesQuality;
	}MultiSamples, *LPMultiSamples;
	typedef struct RendererProperties {
		HWND winHandle;
		unsigned int backbufferCount;
		unsigned int backbufferWinWidth;
		unsigned int backbufferWinHeight;
		bool fullScreen;
		bool stencil;
		VerticalSync vSync;
		MultiSamples multiSamples;
	} RendererProperties, *LPRendererProperties;

	class TESSERACTFRAMEWORK_API TesseractFrameworkRenderer
	{
	protected:
		IUnknownInterface m_pInterfaces;
		RendererProperties m_pRenderProperties;
		float m_pColor[4];
	public:
		TesseractFrameworkRenderer();

		~TesseractFrameworkRenderer();

		virtual bool initializeRenderer() = 0;

		virtual bool configureRenderer(const RendererProperties& properties) = 0;

		virtual bool configureRenderer(HWND hWnd,
			unsigned int backbufferCount,
			unsigned int backbufferWidth,
			unsigned int backbufferHeight,
			bool fullscreen) = 0;

		virtual void clear(float alpha, float red, float green, float blue) = 0;

		virtual void begin() = 0;

		virtual void end() = 0;

		virtual void present() = 0;
		
		void release();
	};
}