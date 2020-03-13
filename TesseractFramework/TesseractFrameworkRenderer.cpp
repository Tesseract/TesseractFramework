#include "pch.h"
#include "TesseractFrameworkRenderer.h"

namespace TesseractFramework
{
	TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::TesseractFrameworkRenderer()
	{
		this->m_pInterfaces = {};
		this->m_pRenderProperties = {};
	}

	TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::~TesseractFrameworkRenderer()
	{
		this->release();
	}

	bool TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::initializeRenderer()
	{
		return true;
	}

	bool TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::configureRenderer(const RendererProperties& properties)
	{
		return true;
	}

	bool TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::configureRenderer(HWND hWnd,
		unsigned int backbufferCount,
		unsigned int backbufferWidth,
		unsigned int backbufferHeight,
		bool fullscreen)
	{
		return true;
	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::clear(float alpha, float red, float green, float blue)
	{

	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::begin()
	{

	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::end()
	{

	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::present()
	{

	}

	void TESSERACTFRAMEWORK_API TesseractFrameworkRenderer::release()
	{
		while (!m_pInterfaces.empty())
		{
			IUnknown* inter = m_pInterfaces.top();
			ReleaseInterface(inter);
			m_pInterfaces.pop();
		}
	}
}