#include "stdafx.h"
#include "DrawUtilites.h"
#include <stdexcept>

void __stdcall DrawUtilites::DrawCross(const Fvector& p, float szx1, float szy1, float szz1, float szx2, float szy2, float szz2, u32 clr, BOOL bRot45 /*= false*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawCross(const Fvector& p, float sz, u32 clr, BOOL bRot45 /*= false*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawFlag(const Fvector& p, float heading, float height, float sz, float sz_fl, u32 clr, BOOL bDrawEntity)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawRomboid(const Fvector& p, float radius, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawJoint(const Fvector& p, float radius, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSpotLight(const Fvector& p, const Fvector& d, float range, float phi, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawDirectionalLight(const Fvector& p, const Fvector& d, float radius, float range, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawPointLight(const Fvector& p, float radius, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSound(const Fvector& p, float radius, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawLineSphere(const Fvector& p, float radius, u32 clr, BOOL bCross)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::dbgDrawPlacement(const Fvector& p, int sz, u32 clr, LPCSTR caption /*= 0*/, u32 clr_font /*= 0xffffffff*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::dbgDrawVert(const Fvector& p0, u32 clr, LPCSTR caption /*= 0*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::dbgDrawEdge(const Fvector& p0, const Fvector& p1, u32 clr, LPCSTR caption /*= 0*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::dbgDrawFace(const Fvector& p0, const Fvector& p1, const Fvector& p2, u32 clr, LPCSTR caption /*= 0*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawFace(const Fvector& p0, const Fvector& p1, const Fvector& p2, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawLine(const Fvector& p0, const Fvector& p1, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawLink(const Fvector& p0, const Fvector& p1, float sz, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawFaceNormal(const Fvector& p0, const Fvector& p1, const Fvector& p2, float size, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawFaceNormal(const Fvector* p, float size, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawFaceNormal(const Fvector& C, const Fvector& N, float size, u32 clr)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSelectionBox(const Fvector& center, const Fvector& size, u32* c /*= 0*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSelectionBoxB(const Fbox& box, u32* c /*= 0*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawIdentSphere(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawIdentSpherePart(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawIdentCone(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawIdentCylinder(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawIdentBox(BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawBox(const Fvector& offs, const Fvector& Size, BOOL bSolid, BOOL bWire, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawAABB(const Fvector& p0, const Fvector& p1, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawAABB(const Fmatrix& parent, const Fvector& center, const Fvector& size, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawOBB(const Fmatrix& parent, const Fobb& box, u32 clr_s, u32 clr_w)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSphere(const Fmatrix& parent, const Fvector& center, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSphere(const Fmatrix& parent, const Fsphere& S, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawCylinder(const Fmatrix& parent, const Fvector& center, const Fvector& dir, float height, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawCone(const Fmatrix& parent, const Fvector& apex, const Fvector& dir, float height, float radius, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawPlane(const Fvector& center, const Fvector2& scale, const Fvector& rotate, u32 clr_s, u32 clr_w, BOOL bCull, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawPlane(const Fvector& p, const Fvector& n, const Fvector2& scale, u32 clr_s, u32 clr_w, BOOL bCull, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawRectangle(const Fvector& o, const Fvector& u, const Fvector& v, u32 clr_s, u32 clr_w, BOOL bSolid, BOOL bWire)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawGrid()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawPivot(const Fvector& pos, float sz /*= 5.f*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawAxis(const Fmatrix& T)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawObjectAxis(const Fmatrix& T, float sz, BOOL sel)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawSelectionRect(const Ivector2& m_SelStart, const Ivector2& m_SelEnd)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::DrawIndexedPrimitive(int prim_type, u32 pc, const Fvector& pos, const Fvector* vb, const u32& vb_size, const u32* ib, const u32& ib_size, const u32& clr_argb, float scale /*= 1.0f*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::OutText(const Fvector& pos, LPCSTR text, u32 color /*= 0xFF000000*/, u32 shadow_color /*= 0xFF909090*/)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void __stdcall DrawUtilites::OnDeviceDestroy()
{
	throw std::logic_error("The method or operation is not implemented.");
}
