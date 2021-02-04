#include "stdafx.h"
#include "UISeqVideoItem.h"

void UISeqVideoItem::Copy(IUISequenceVideoItem& _in)
{
}

bool UISeqVideoItem::HasTexture()
{
	return true;
}

void UISeqVideoItem::CaptureTexture()
{
}

void UISeqVideoItem::ResetTexture()
{
}

BOOL UISeqVideoItem::video_IsPlaying()
{
	return TRUE;
}

void UISeqVideoItem::video_Sync(u32 _time)
{
}

void UISeqVideoItem::video_Play(BOOL looped, u32 _time /*= 0xFFFFFFFF*/)
{
}

void UISeqVideoItem::video_Stop()
{
}

UISeqVideoItem::UISeqVideoItem(IDiligentRenderingHost* dev)
{
	device = dev;
}
