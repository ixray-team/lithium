#pragma once

#include "../xrEngine/Render.h"

class Renderer : public IRender_interface
{
private:
	static IRender_interface* _instance;

protected:
	Renderer() {};

public:
	static IRender_interface* Instance() {
		if (_instance == nullptr)
		{
			_instance = new Renderer();
		}

		return _instance;
	}

public:
	GenerationLevel get_generation() override;
	bool is_sun_static() override;
	DWORD get_dx_level() override;

	void create() override;
	void destroy() override;

	void reset_begin() override;
	void reset_end() override;


	void level_Load(IReader* r) override;
	void level_Unload() override;

	HRESULT shader_compile(LPCSTR name, DWORD const* pSrcData, UINT SrcDataLen, LPCSTR pFunctionName, LPCSTR pTarget, DWORD Flags, void*& result) override;

	LPCSTR getShaderPath() override;

	IRender_Sector* getSector(int id) override;
	IRender_Sector* detectSector(const Fvector& P) override;

	void add_Visual(IRenderVisual* V) override;
	IRenderVisual* getVisual(int id) override;

	void add_Geometry(IRenderVisual* V) override;

	IRender_Target* getTarget() override;

	void set_Transform(Fmatrix* M) override;

	BOOL get_HUD() override;
	void set_HUD(BOOL V) override;

	void set_Invisible(BOOL V) override;

	void flush() override;

	void set_Object(IRenderable* O) override;

	void add_Occluder(Fbox2& bb_screenspace) override;

	void add_StaticWallmark(const wm_shader& S, const Fvector& P, float s, CDB::TRI* T, Fvector* V) override;
	void add_StaticWallmark(IWallMarkArray* pArray, const Fvector& P, float s, CDB::TRI* T, Fvector* V) override;

	void clear_static_wallmarks() override;

	void add_SkeletonWallmark(const Fmatrix* xf, IKinematics* obj, IWallMarkArray* pArray, const Fvector& start, const Fvector& dir, float size) override;

	IRender_ObjectSpecific* ros_create(IRenderable* parent) override;
	void ros_destroy(IRender_ObjectSpecific*&) override;

	IRender_Light* light_create() override;

	IRender_Glow* glow_create() override;

	IRenderVisual* model_CreateParticles(LPCSTR name) override;

	IRenderVisual* model_Create(LPCSTR name, IReader* data = 0) override;
	IRenderVisual* model_CreateChild(LPCSTR name, IReader* data) override;
	IRenderVisual* model_Duplicate(IRenderVisual* V) override;
	void model_Delete(IRenderVisual*& V, BOOL bDiscard = FALSE) override;
	void model_Logging(BOOL bEnable) override;

	void models_Prefetch() override;
	void models_Clear(BOOL b_complete) override;

	BOOL occ_visible(vis_data& V) override;
	BOOL occ_visible(Fbox& B) override;
	BOOL occ_visible(sPoly& P) override;

	void Calculate() override;
	void Render() override;

	void Screenshot(ScreenshotMode mode = SM_NORMAL, LPCSTR name = 0) override;
	void Screenshot(ScreenshotMode mode, CMemoryWriter& memory_writer) override;

	void ScreenshotAsyncBegin() override;
	void ScreenshotAsyncEnd(CMemoryWriter& memory_writer) override;


	void rmNear() override;
	void rmNormal() override;
	void rmFar() override;

	u32 memory_usage() override;

protected:
	void ScreenshotImpl(ScreenshotMode mode, LPCSTR name, CMemoryWriter* memory_writer) override;
};

