#pragma once

#if defined(DEBUG) | defined(_DEBUG)
#ifndef D3D_DEBUG_INFO
#define D3D_DEBUG_INFO
#endif
#endif

/*Include all Direct3D headers we'll need*/

// Direct3D9 headers.
#include <d3d9.h>
#include <d3dx9.h>



// Direct3D11.
#include <D3D11.h>
#include <D3DX11.h>

// Include stack to handle IUnknown interfaces.
#include <stack>
#pragma comment(lib,"d3d9.lib")
#if defined(DEBUG) | defined(_DEBUG)
#include <DxErr.h>
#pragma comment(lib,"d3dx9d.lib")
#pragma comment(lib,"d3dx11d.lib")
#pragma comment(lib,"dxerr.lib")
#else
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"dxgi.lib")
#endif

// typedef stack as an interface stack.
typedef std::stack<IUnknown*> IUnknownInterface;

// Define a function that releases interfaces.
#define ReleaseInterface(x) { if(x){ x->Release(); x=0; } }
