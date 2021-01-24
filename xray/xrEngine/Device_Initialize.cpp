#include "stdafx.h"
#include "resource.h"
#include "dedicated_server_only.h"

extern LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

PROTECT_API void CRenderDevice::Initialize			()
{
	Log("Initializing Engine...");
	TimerGlobal.Start			();
	TimerMM.Start				();

	// Unless a substitute hWnd has been specified, create a window to render into
    if( m_hWnd == NULL)
    {
		const char*	wndclass ="_XRAY_1.5";

        // Register the windows class
		HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(0);
        WNDCLASS wndClass = { 0, WndProc, 0, 0, hInstance,
                              LoadIcon( hInstance, MAKEINTRESOURCE(IDI_ICON1) ),
                              LoadCursor( NULL, IDC_ARROW ),
                              (HBRUSH)GetStockObject(BLACK_BRUSH),
                              NULL, wndclass };
        RegisterClass( &wndClass );

        // Set the window's initial style
        m_dwWindowStyle = WS_BORDER | WS_DLGFRAME;

        // Set the window's initial width
        RECT rc;
        SetRect			( &rc, 0, 0, 640, 480 );
        AdjustWindowRect( &rc, m_dwWindowStyle, FALSE );

        // Create the render window
		m_hWnd = CreateWindowEx( WS_EX_TOPMOST, 
								wndclass, "S.T.A.L.K.E.R.: Call of Pripyat", m_dwWindowStyle,
                               CW_USEDEFAULT, CW_USEDEFAULT,
                               (rc.right-rc.left), (rc.bottom-rc.top), 0L,
                               0, hInstance, 0L );
    }

    m_dwWindowStyle = GetWindowLong( m_hWnd, GWL_STYLE );
    GetWindowRect	( m_hWnd, &m_rcWindowBounds );
    GetClientRect	( m_hWnd, &m_rcWindowClient );
}

