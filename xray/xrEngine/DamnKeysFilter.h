#pragma once

struct damn_keys_filter 
{
	const unsigned long dwStickyKeysStructSize = sizeof(STICKYKEYS);
	const unsigned long dwFilterKeysStructSize = sizeof(FILTERKEYS);
	const unsigned long dwToggleKeysStructSize = sizeof(TOGGLEKEYS);

	BOOL bScreenSaverState;

	STICKYKEYS StickyKeysStruct;
	FILTERKEYS FilterKeysStruct;
	TOGGLEKEYS ToggleKeysStruct;

	DWORD dwStickyKeysFlags;
	DWORD dwFilterKeysFlags;
	DWORD dwToggleKeysFlags;

	damn_keys_filter();
	~damn_keys_filter();
};