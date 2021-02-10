#include "stdafx.h"
#include "UiRenderer.h"

#include "RendererFactory.h"
#include "IDiligentRenderingHost.h"

#include <stdexcept>


IUIRender* UiRenderer::_instance;

UiRenderer::UiRenderer(class IDiligentRenderingHost* dev)
{
	device = dev;
}

IUIRender* UiRenderer::Instance()
{
	if (_instance == nullptr)
	{
		IDiligentRenderingHost* host = ((RendererFactory*)RendererFactory::Instance())->GetRendererDevice();
		_instance = new UiRenderer(host);
	}

	return _instance;
}

void UiRenderer::CreateUIGeom()
{
	Diligent::IRenderDevice* dev = device->dilGetDevice();
	
	Diligent::BufferDesc vertexBufferDesc;
	vertexBufferDesc.Name = "UI Geometry Vertex Buffer";
	vertexBufferDesc.Usage = Diligent::USAGE::USAGE_DEFAULT;
	vertexBufferDesc.BindFlags = Diligent::BIND_FLAGS::BIND_VERTEX_BUFFER;
	//vertexBufferDesc.CPUAccessFlags = Diligent::CPU_ACCESS_FLAGS::CPU_ACCESS_READ | Diligent::CPU_ACCESS_FLAGS::CPU_ACCESS_WRITE;
	vertexBufferDesc.Mode = Diligent::BUFFER_MODE::BUFFER_MODE_RAW;
	vertexBufferDesc.uiSizeInBytes = sizeof(float) * 2 * 4;		// Float2 x 4 verts (screen quad)
	vertexBufferDesc.ElementByteStride = 2 * sizeof(float);

	Diligent::BufferData bdata;
	bdata.DataSize = sizeof(float) * 2 * 4;
	bdata.pData = (void*) new float[2 * 4]{
		-1.f, -1.f,
		1.f, -1.f,
		-1.f, 1.f,
		1.f, 1.f
	};

	dev->CreateBuffer(vertexBufferDesc, &bdata, &uiVertexBuffer);
}

void UiRenderer::DestroyUIGeom()
{
	uiVertexBuffer->Release();
}

void UiRenderer::SetShader(IUIShader& shader)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::SetAlphaRef(int aref)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::SetScissor(Irect* rect /*= NULL*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::GetActiveTextureResolution(Fvector2& res)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::PushPoint(float x, float y, float z, u32 C, float u, float v)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::StartPrimitive(u32 iMaxVerts, ePrimitiveType primType, ePointType pointType)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::FlushPrimitive()
{
	throw std::logic_error("The method or operation is not implemented.");
}

LPCSTR UiRenderer::UpdateShaderName(LPCSTR tex_name, LPCSTR sh_name)
{
	return sh_name;
}

void UiRenderer::CacheSetXformWorld(const Fmatrix& M)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void UiRenderer::CacheSetCullMode(CullMode)
{
	throw std::logic_error("The method or operation is not implemented.");
}
