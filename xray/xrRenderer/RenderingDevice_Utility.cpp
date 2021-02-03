#include "stdafx.h"

#include "RenderingDevice.h"

Diligent::float4x4 RenderingDevice::GetAdjustedProjectionMatrix(float FOV, float NearPlane, float FarPlane) const
{
	using namespace Diligent;

	const auto& SCDesc = dilSwapChain->GetDesc();

	float AspectRatio = static_cast<float>(SCDesc.Width) / static_cast<float>(SCDesc.Height);
	float XScale, YScale;
	if (SCDesc.PreTransform == SURFACE_TRANSFORM_ROTATE_90 ||
		SCDesc.PreTransform == SURFACE_TRANSFORM_ROTATE_270 ||
		SCDesc.PreTransform == SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90 ||
		SCDesc.PreTransform == SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270)
	{
		XScale = 1.f / std::tan(FOV / 2.f);
		YScale = XScale * AspectRatio;
	}
	else
	{
		YScale = 1.f / std::tan(FOV / 2.f);
		XScale = YScale / AspectRatio;
	}

	float4x4 Proj;
	Proj._11 = XScale;
	Proj._22 = YScale;
	Proj.SetNearFarClipPlanes(NearPlane, FarPlane, dilDevice->GetDeviceCaps().IsGLDevice());
	return Proj;
}

Diligent::float4x4 RenderingDevice::GetSurfacePretransformMatrix(const Diligent::float3& f3CameraViewAxis) const
{
	using namespace Diligent;

	const auto& SCDesc = dilSwapChain->GetDesc();
	switch (SCDesc.PreTransform)
	{
	case SURFACE_TRANSFORM_ROTATE_90:
		return float4x4::RotationArbitrary(f3CameraViewAxis, -PI_F / 2.f);
	case SURFACE_TRANSFORM_ROTATE_180:
		return float4x4::RotationArbitrary(f3CameraViewAxis, -PI_F);
	case SURFACE_TRANSFORM_ROTATE_270:
		return float4x4::RotationArbitrary(f3CameraViewAxis, -PI_F * 3.f / 2.f);
	case SURFACE_TRANSFORM_OPTIMAL:
		return float4x4::Identity();

	case SURFACE_TRANSFORM_HORIZONTAL_MIRROR:
	case SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90:
	case SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180:
	case SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270:
		return float4x4::Identity();

	default:
		return float4x4::Identity();
	}
}