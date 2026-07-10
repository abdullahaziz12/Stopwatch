# ⏱️ Stopwatch (Countdown Timer) — C++

A countdown timer written in C++, available in two versions: a console-based version and a native Windows GUI version. Enter a duration in hours, minutes, and seconds, and watch it count down live to zero in `HH:MM:SS` format.

## 🚀 Overview
This project takes a user-defined duration and counts it down second by second until it reaches `00:00:00`, at which point it displays a "Time Out" message. It started as a console program and was later rebuilt as a native Windows GUI application, with the core countdown logic kept unchanged between both versions.

## 📁 What's Inside
| File | Description |
|---|---|
| `Stopwatch.cpp` | Console-based version — text output in the terminal |
| `StopwatchGUI.cpp` | Windows GUI version — built with the native Win32 API, with input fields and a Start/Stop button |

## ⚙️ Features
- Accepts custom hours, minutes, and seconds as input
- Live countdown display, updating every second
- Clean `HH:MM:SS` formatted output
- "Time Out" message when the countdown finishes
- **GUI version only:** Start/Stop toggle button, input validation, dedicated window

## 🧠 Concepts Used
**Console version**
- Loops and conditional logic
- Time calculations (converting HH:MM:SS to total seconds and back)
- `Sleep()` for timed delays
- `system("cls")` for console screen refresh

**GUI version**
- Win32 API window creation and message handling
- Event-driven programming (`WM_TIMER`, `WM_COMMAND`)
- `SetTimer` for non-blocking, repeating countdown ticks
- Win32 controls (`EDIT`, `BUTTON`, `STATIC`) for input and display

## 💻 Requirements
- C++ compiler (MinGW, Dev C++, or Visual Studio)
- Windows OS (both versions rely on Windows-specific APIs)

## 🛠️ How to Run

**Console version**
```
g++ Stopwatch.cpp -o Stopwatch.exe
./Stopwatch.exe
```
Enter the hours, minutes, and seconds when prompted, and watch the countdown run in the console.

**GUI version**
```
g++ StopwatchGUI.cpp -o StopwatchGUI.exe -mwindows
./StopwatchGUI.exe
```
The `-mwindows` flag is required — without it, a console window opens alongside the GUI.

**Run online (console version only, no installation needed):**
Try it directly in your browser via [OnlineGDB](https://www.onlinegdb.com/kDLipqIlso#).

## 📋 Example (Console Version)
```
Enter hours: 0
Enter minutes: 0
Enter seconds: 10

Time Remaining: 00:00:10
Time Remaining: 00:00:09
...
Time Remaining: 00:00:00
Time Out!
```

## 🧭 Console vs GUI — What Changed
| Console Version | GUI Version |
|---|---|
| `for` loop drives the countdown | `SetTimer` fires a `WM_TIMER` event every 1000ms |
| `Sleep(1000)` blocks execution | Timer runs without blocking the UI thread |
| `system("cls")` + reprint | `SetWindowTextA` updates a single label |
| `cin >>` for input | Win32 `EDIT` controls read via `GetWindowTextA` |
| Decrement logic | Unchanged — same algorithm, now inside a `Tick()` function called on each timer event |

## ⚠️ Limitations
- Windows-only (both versions rely on Windows-specific APIs)
- No pause/resume functionality
- No sound/alarm on completion

## 🔥 Future Improvements
- Add pause and resume controls
- Add a sound alert when the countdown ends
- Make the console version cross-platform (replace Windows-specific calls)
- Add progress bar / visual styling to the GUI version

## 👤 Author
Abdullah Aziz
