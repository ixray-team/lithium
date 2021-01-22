#include "stdafx.h"
#include "DamnKeysFilter.h"

damn_keys_filter::damn_keys_filter()
{
	bScreenSaverState = FALSE;

	SystemParametersInfo(SPI_GETSCREENSAVEACTIVE, 0, (PVOID)&bScreenSaverState, 0);

	if (bScreenSaverState)
		SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, FALSE, NULL, 0);

	dwStickyKeysFlags = 0;
	dwFilterKeysFlags = 0;
	dwToggleKeysFlags = 0;

	ZeroMemory(&StickyKeysStruct, dwStickyKeysStructSize);
	ZeroMemory(&FilterKeysStruct, dwFilterKeysStructSize);
	ZeroMemory(&ToggleKeysStruct, dwToggleKeysStructSize);

	StickyKeysStruct.cbSize = dwStickyKeysStructSize;
	FilterKeysStruct.cbSize = dwFilterKeysStructSize;
	ToggleKeysStruct.cbSize = dwToggleKeysStructSize;

	// Saving current state
	SystemParametersInfo(SPI_GETSTICKYKEYS, dwStickyKeysStructSize, (PVOID)&StickyKeysStruct, 0);
	SystemParametersInfo(SPI_GETFILTERKEYS, dwFilterKeysStructSize, (PVOID)&FilterKeysStruct, 0);
	SystemParametersInfo(SPI_GETTOGGLEKEYS, dwToggleKeysStructSize, (PVOID)&ToggleKeysStruct, 0);

	if (StickyKeysStruct.dwFlags & SKF_AVAILABLE)
	{
		dwStickyKeysFlags = StickyKeysStruct.dwFlags;
		StickyKeysStruct.dwFlags = 0;
		SystemParametersInfo(SPI_SETSTICKYKEYS, dwStickyKeysStructSize, (PVOID)&StickyKeysStruct, 0);
	}

	if (FilterKeysStruct.dwFlags & FKF_AVAILABLE)
	{
		dwFilterKeysFlags = FilterKeysStruct.dwFlags;
		FilterKeysStruct.dwFlags = 0;
		SystemParametersInfo(SPI_SETFILTERKEYS, dwFilterKeysStructSize, (PVOID)&FilterKeysStruct, 0);
	}

	if (ToggleKeysStruct.dwFlags & TKF_AVAILABLE)
	{
		dwToggleKeysFlags = ToggleKeysStruct.dwFlags;
		ToggleKeysStruct.dwFlags = 0;
		SystemParametersInfo(SPI_SETTOGGLEKEYS, dwToggleKeysStructSize, (PVOID)&ToggleKeysStruct, 0);
	}
}

damn_keys_filter::~damn_keys_filter()
{
	if (bScreenSaverState)
		SystemParametersInfo(SPI_SETSCREENSAVEACTIVE, TRUE, NULL, 0);

	if (dwStickyKeysFlags)
	{
		StickyKeysStruct.dwFlags = dwStickyKeysFlags;
		SystemParametersInfo(SPI_SETSTICKYKEYS, dwStickyKeysStructSize, (PVOID)&StickyKeysStruct, 0);
	}

	if (dwFilterKeysFlags)
	{
		FilterKeysStruct.dwFlags = dwFilterKeysFlags;
		SystemParametersInfo(SPI_SETFILTERKEYS, dwFilterKeysStructSize, (PVOID)&FilterKeysStruct, 0);
	}

	if (dwToggleKeysFlags)
	{
		ToggleKeysStruct.dwFlags = dwToggleKeysFlags;
		SystemParametersInfo(SPI_SETTOGGLEKEYS, dwToggleKeysStructSize, (PVOID)&ToggleKeysStruct, 0);
	}
}
