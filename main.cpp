#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1:
            // wall hack
            break;

        case 2:
            // radar hack
            break;

        case 3:
            // aimbot
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    const char CLASS_NAME[] = "MyWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc   = WndProc;          // ❗ было WindowProc
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Simple Window",
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    // Надпись "hello"
    CreateWindow(
        "STATIC",
        "hello",
        WS_VISIBLE | WS_CHILD,
        50, 30, 100, 20,
        hwnd,
        nullptr,
        hInstance,
        nullptr
    );

    // Заголовок
    CreateWindow(
        "STATIC",
        "Phanton Sense - project of Sergiusz Salasinski",
        WS_VISIBLE | WS_CHILD,
        50, 55, 350, 20,
        hwnd,
        nullptr,
        hInstance,
        nullptr
    );

    // Checkbox: Wall Hack
    CreateWindow(
        "BUTTON",
        "Wall Hack",
        WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
        50, 90, 150, 25,
        hwnd,
        (HMENU)1,
        hInstance,
        nullptr
    );

    // Checkbox: Radar Hack
    CreateWindow(
        "BUTTON",
        "Radar Hack",
        WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
        50, 125, 150, 25,
        hwnd,
        (HMENU)2,
        hInstance,
        nullptr
    );

    // Checkbox: Aimbot
    CreateWindow(
        "BUTTON",
        "Aimbot",
        WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
        50, 160, 150, 25,
        hwnd,
        (HMENU)3,
        hInstance,
        nullptr
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
