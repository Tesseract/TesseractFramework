#pragma once

#include "TesseractFrameworkRenderer.h"

namespace TesseractFramework
{
	class TesseractFrameworkRendererD3D9 : public TesseractFrameworkRenderer
	{
	protected:
		IDirect3D9* m_pD3D9;
		IDirect3DDevice9* m_pD3DDevice9;
		D3DPRESENT_PARAMETERS m_pPresetParameters;
	public:
		TESSERACTFRAMEWORK_API TesseractFrameworkRendererD3D9();

		TESSERACTFRAMEWORK_API ~TesseractFrameworkRendererD3D9();

		bool TESSERACTFRAMEWORK_API initializeRenderer();

		bool TESSERACTFRAMEWORK_API configureRenderer(const RendererProperties& properties);

		bool TESSERACTFRAMEWORK_API configureRenderer(HWND hWnd,
			unsigned int backbufferCount,
			unsigned int backbufferWidth,
			unsigned int backbufferHeight,
			bool fullscreen);

		void TESSERACTFRAMEWORK_API setViewport(unsigned int xLeft, unsigned int yTop, unsigned int xWidth, unsigned int yHeight,float minZ, float maxZ);

		void TESSERACTFRAMEWORK_API clear(float alpha, float red, float green, float blue);

		void TESSERACTFRAMEWORK_API begin();

		void TESSERACTFRAMEWORK_API end();

		void TESSERACTFRAMEWORK_API present();

		TESSERACTFRAMEWORK_API IDirect3D9* getD3D9() const;

		TESSERACTFRAMEWORK_API IDirect3DDevice9* getD3DDevice9() const;
	};
}