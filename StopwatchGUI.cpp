#include <windows.h>
#include <string>
using namespace std;

// ---------- Global state (same variables as your console version) ----------
int hours = 0, minute = 0, seconds = 0;
bool running = false;

// Control IDs
#define ID_EDIT_HOURS   101
#define ID_EDIT_MIN     102
#define ID_EDIT_SEC     103
#define ID_BTN_START    104
#define ID_LABEL_DISPLAY 105
#define ID_TIMER        1

HWND hEditHours, hEditMin, hEditSec, hLabelDisplay, hBtnStart;

// ---------- Updates the on-screen time display ----------
void UpdateDisplay(HWND hwnd) {
    string text = "";
    if (hours < 10) text += "0";
    text += to_string(hours) + ":";
    if (minute < 10) text += "0";
    text += to_string(minute) + ":";
    if (seconds < 10) text += "0";
    text += to_string(seconds);

    SetWindowTextA(hLabelDisplay, text.c_str());
}

// ---------- Same decrement logic as your console for-loop, called every tick ----------
void Tick(HWND hwnd) {
    if (hours == 0 && minute == 0 && seconds == 0) {
        KillTimer(hwnd, ID_TIMER);
        running = false;
        SetWindowTextA(hLabelDisplay, "Time Out");
        SetWindowTextA(hBtnStart, "Start");
        return;
    }

    if (minute == 0 && seconds == 0) {
        hours--;
        minute = 59;
        seconds = 59;
    } else if (seconds == 0) {
        minute--;
        seconds = 59;
    } else {
        seconds--;
    }

    UpdateDisplay(hwnd);
}

// ---------- Reads hours/min/sec from the input boxes ----------
void ReadInputs() {
    char buffer[10];
    GetWindowTextA(hEditHours, buffer, 10);
    hours = atoi(buffer);
    GetWindowTextA(hEditMin, buffer, 10);
    minute = atoi(buffer);
    GetWindowTextA(hEditSec, buffer, 10);
    seconds = atoi(buffer);
}

// ---------- Window procedure: handles all events (button clicks, timer ticks) ----------
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            CreateWindowA("STATIC", "Hours:", WS_VISIBLE | WS_CHILD, 20, 20, 60, 20, hwnd, NULL, NULL, NULL);
            hEditHours = CreateWindowA("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 20, 50, 20, hwnd, (HMENU)ID_EDIT_HOURS, NULL, NULL);

            CreateWindowA("STATIC", "Minutes:", WS_VISIBLE | WS_CHILD, 160, 20, 60, 20, hwnd, NULL, NULL, NULL);
            hEditMin = CreateWindowA("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 230, 20, 50, 20, hwnd, (HMENU)ID_EDIT_MIN, NULL, NULL);

            CreateWindowA("STATIC", "Seconds:", WS_VISIBLE | WS_CHILD, 20, 60, 60, 20, hwnd, NULL, NULL, NULL);
            hEditSec = CreateWindowA("EDIT", "0", WS_VISIBLE | WS_CHILD | WS_BORDER, 90, 60, 50, 20, hwnd, (HMENU)ID_EDIT_SEC, NULL, NULL);

            hBtnStart = CreateWindowA("BUTTON", "Start", WS_VISIBLE | WS_CHILD, 160, 60, 100, 25, hwnd, (HMENU)ID_BTN_START, NULL, NULL);

            hLabelDisplay = CreateWindowA("STATIC", "00:00:00", WS_VISIBLE | WS_CHILD | SS_CENTER,
                                           20, 110, 260, 40, hwnd, (HMENU)ID_LABEL_DISPLAY, NULL, NULL);
            break;
        }

        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_BTN_START) {
                if (!running) {
                    ReadInputs();
                    if (hours == 0 && minute == 0 && seconds == 0) {
                        MessageBoxA(hwnd, "Enter a valid time.", "Error", MB_OK | MB_ICONWARNING);
                        break;
                    }
                    UpdateDisplay(hwnd);
                    running = true;
                    SetWindowTextA(hBtnStart, "Stop");
                    SetTimer(hwnd, ID_TIMER, 1000, NULL); // fires WM_TIMER every 1000ms
                } else {
                    KillTimer(hwnd, ID_TIMER);
                    running = false;
                    SetWindowTextA(hBtnStart, "Start");
                }
            }
            break;
        }

        case WM_TIMER: {
            if (wParam == ID_TIMER) {
                Tick(hwnd);
            }
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// ---------- Entry point ----------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "StopwatchWindowClass";

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(
        0, CLASS_NAME, "Stopwatch", WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 320, 220,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
