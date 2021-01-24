#pragma once

#include "stdafx.h"

#include "Include/DrawUtils.h"

class DrawUtilites : public CDUInterface
{
private:
	static CDUInterface* _instance;

protected:
	DrawUtilites() {};

public:
	static CDUInterface* Instance() {
		if (_instance == nullptr)
		{
			_instance = new DrawUtilites();
		}

		return _instance;
	}

public:
	void __stdcall DrawCross(const Fvector& p, float szx1, float szy1, float szz1, float szx2, float szy2, float szz2, u32 clr, BOOL bRot45 = false) override;
	void __stdcall DrawCross(const Fvector& p, float sz, u32 clr, BOOL bRot45 = false) override;

	void __stdcall DrawFlag(const Fvector& p, float heading, float height, float sz, float sz_fl, u32 clr, BOOL bDrawEntity) override;
	void __stdcall DrawRomboid(const Fvector& p, float radius, u32 clr) override;
	void __stdcall DrawJoint(const Fvector& p, float radius, u32 clr) override;

	void __stdcall DrawSpotLight(const Fvector& p, const Fvector& d, float range, float phi, u32 clr) override;
	void __stdcall DrawDirectionalLight(const Fvector& p, const Fvector& d, float radius, float range, u32 clr) override;
	void __stdcall DrawPointLight(const Fvector& p, float radius, u32 clr) override;

	void __stdcall DrawSound(const Fvector& p, float radius, u32 clr) override;

	void __stdcall DrawLineSphere(const Fvector& p, float radius, u32 clr, BOOL bCross) override;
	void __stdcall dbgDrawPlacement(const Fvector& p, int sz, u32 clr, LPCSTR caption = 0, u32 clr_font = 0xffffffff) override;

	void __stdcall dbgDrawVert(const Fvector& p0, u32 clr, LPCSTR caption = 0) override;

	void __stdcall dbgDrawEdge(const Fvector& p0, const Fvector& p1, u32 clr, LPCSTR caption = 0) override;

	void __stdcall dbgDrawFace(const Fvector& p0, const Fvector& p1, const Fvector& p2, u32 clr, LPCSTR caption = 0) override;
	void __stdcall DrawFace(const Fvector& p0, const Fvector& p1, const Fvector& p2, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;

	void __stdcall DrawLine(const Fvector& p0, const Fvector& p1, u32 clr) override;
	void __stdcall DrawLink(const Fvector& p0, const Fvector& p1, float sz, u32 clr) override;

	void __stdcall DrawFaceNormal(const Fvector& p0, const Fvector& p1, const Fvector& p2, float size, u32 clr) override;
	void __stdcall DrawFaceNormal(const Fvector* p, float size, u32 clr) override;
	void __stdcall DrawFaceNormal(const Fvector& C, const Fvector& N, float size, u32 clr) override;

	void __stdcall DrawSelectionBox(const Fvector& center, const Fvector& size, u32* c = 0) override;
	void __stdcall DrawSelectionBoxB(const Fbox& box, u32* c = 0) override;
	void __stdcall DrawIdentSphere(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w) override;
	void __stdcall DrawIdentSpherePart(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w) override;
	void __stdcall DrawIdentCone(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w) override;
	void __stdcall DrawCone(const Fmatrix& parent, const Fvector& apex, const Fvector& dir, float height, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;
	void __stdcall DrawIdentCylinder(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w) override;
	void __stdcall DrawCylinder(const Fmatrix& parent, const Fvector& center, const Fvector& dir, float height, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;
	void __stdcall DrawIdentBox(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w) override;
	void __stdcall DrawBox(const Fvector& offs, const Fvector& Size, BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w) override;

	void __stdcall DrawAABB(const Fvector& p0, const Fvector& p1, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;
	void __stdcall DrawAABB(const Fmatrix& parent, const Fvector& center, const Fvector& size, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;

	void __stdcall DrawOBB(const Fmatrix& parent, const Fobb& box, u32 clr_s, u32 clr_w) override;

	void __stdcall DrawSphere(const Fmatrix& parent, const Fvector& center, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;
	void __stdcall DrawSphere(const Fmatrix& parent, const Fsphere& S, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;

	void __stdcall DrawPlane(const Fvector& center, const Fvector2& scale, const Fvector& rotate, u32 clr_s, u32 clr_w, BOOL bCull, BOOL bSolid, BOOL bWire) override;
	void __stdcall DrawPlane(const Fvector& p, const Fvector& n, const Fvector2& scale, u32 clr_s, u32 clr_w, BOOL bCull, BOOL bSolid, BOOL bWire) override;

	void __stdcall DrawRectangle(const Fvector& o, const Fvector& u, const Fvector& v, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire) override;

	void __stdcall DrawGrid() override;
	void __stdcall DrawPivot(const Fvector& pos, float sz = 5.f) override;
	void __stdcall DrawAxis(const Fmatrix& T) override;
	void __stdcall DrawObjectAxis(const Fmatrix& T, float sz, BOOL sel) override;
	void __stdcall DrawSelectionRect(const Ivector2& m_SelStart, const Ivector2& m_SelEnd) override;
	void __stdcall DrawIndexedPrimitive(int prim_type, u32 pc, const Fvector& pos, const Fvector* vb, const u32& vb_size, const u32* ib, const u32& ib_size, const u32& clr_argb, float scale = 1.0f) override;

	void __stdcall OutText(const Fvector& pos, LPCSTR text, u32 color = 0xFF000000, u32 shadow_color = 0xFF909090) override;

	void __stdcall OnDeviceDestroy() override;
};

