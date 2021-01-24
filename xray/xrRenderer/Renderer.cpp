#include "stdafx.h"
#include "Renderer.h"

#include <stdexcept>

IRender_interface::GenerationLevel Renderer::get_generation()
{
	return IRender_interface::GENERATION_R2;
}

bool Renderer::is_sun_static()
{
	return false;
}

DWORD Renderer::get_dx_level()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::create()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::destroy()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::reset_begin()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::reset_end()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::level_Load(IReader*)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::level_Unload()
{
	throw std::logic_error("The method or operation is not implemented.");
}

HRESULT Renderer::shader_compile(LPCSTR name, DWORD const* pSrcData, UINT SrcDataLen, LPCSTR pFunctionName, LPCSTR pTarget, DWORD Flags, void*& result)
{
	throw std::logic_error("The method or operation is not implemented.");
}

LPCSTR Renderer::getShaderPath()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRender_Sector* Renderer::getSector(int id)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRenderVisual* Renderer::getVisual(int id)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRender_Sector* Renderer::detectSector(const Fvector& P)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRender_Target* Renderer::getTarget()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::set_Transform(Fmatrix* M)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::set_HUD(BOOL V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

BOOL Renderer::get_HUD()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::set_Invisible(BOOL V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::flush()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::set_Object(IRenderable* O)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::add_Occluder(Fbox2& bb_screenspace)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::add_Visual(IRenderVisual* V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::add_Geometry(IRenderVisual* V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::add_StaticWallmark(const wm_shader& S, const Fvector& P, float s, CDB::TRI* T, Fvector* V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::add_StaticWallmark(IWallMarkArray* pArray, const Fvector& P, float s, CDB::TRI* T, Fvector* V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::clear_static_wallmarks()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::add_SkeletonWallmark(const Fmatrix* xf, IKinematics* obj, IWallMarkArray* pArray, const Fvector& start, const Fvector& dir, float size)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRender_ObjectSpecific* Renderer::ros_create(IRenderable* parent)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::ros_destroy(IRender_ObjectSpecific*&)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRender_Light* Renderer::light_create()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRender_Glow* Renderer::glow_create()
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRenderVisual* Renderer::model_CreateParticles(LPCSTR name)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRenderVisual* IRender_interface::model_Create(LPCSTR name, IReader* data /*= 0*/)
{

}

IRenderVisual* Renderer::model_CreateChild(LPCSTR name, IReader* data)
{
	throw std::logic_error("The method or operation is not implemented.");
}

IRenderVisual* Renderer::model_Duplicate(IRenderVisual* V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::model_Delete(IRenderVisual*& V, BOOL bDiscard /*= FALSE*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::model_Logging(BOOL bEnable)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::models_Prefetch()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::models_Clear(BOOL b_complete)
{
	throw std::logic_error("The method or operation is not implemented.");
}

BOOL Renderer::occ_visible(vis_data& V)
{
	throw std::logic_error("The method or operation is not implemented.");
}

BOOL Renderer::occ_visible(Fbox& B)
{
	throw std::logic_error("The method or operation is not implemented.");
}

BOOL Renderer::occ_visible(sPoly& P)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::Calculate()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::Render()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::Screenshot(ScreenshotMode mode /*= SM_NORMAL*/, LPCSTR name /*= 0*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::Screenshot(ScreenshotMode mode, CMemoryWriter& memory_writer)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::ScreenshotAsyncBegin()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::ScreenshotAsyncEnd(CMemoryWriter& memory_writer)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::rmNear()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::rmFar()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::rmNormal()
{
	throw std::logic_error("The method or operation is not implemented.");
}

u32 Renderer::memory_usage()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Renderer::ScreenshotImpl(ScreenshotMode mode, LPCSTR name, CMemoryWriter* memory_writer)
{
	throw std::logic_error("The method or operation is not implemented.");
}
