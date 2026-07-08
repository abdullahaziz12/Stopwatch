# ⏱️ Stopwatch (Countdown Timer) — C++

A simple console-based countdown timer written in C++. Enter a duration in hours, minutes, and seconds, and watch it count down live to zero in a clean `HH:MM:SS` format.

## 🚀 Overview

This program takes a user-defined duration and counts down second by second, refreshing the console display until it reaches `00:00:00`, at which point it shows a **"Time Out"** message.

It's a lightweight beginner-friendly project focused on practicing:
- Basic I/O and input validation
- Time formatting and arithmetic
- Console manipulation (clearing screen, timed updates)
- Simple loop-driven program logic

## ⚙️ Features

- Accepts custom hours, minutes, and seconds as input
- Live countdown display, updating every second
- Clean `HH:MM:SS` formatted output
- "Time Out" message when the countdown finishes

## 🧠 Concepts Used

- Loops and conditional logic
- Time calculations (converting HH:MM:SS to total seconds and back)
- `Sleep()` for timed delays
- `system("cls")` for console screen refresh

## 💻 Requirements

- C++ compiler (MinGW, Dev C++, or Visual Studio)
- Windows OS *(required — uses `Sleep()` and `system("cls")`, both Windows-specific)*

## 🛠️ How to Run

**Option 1: Compile locally**

```bash
g++ stopwatch.cpp -o stopwatch.exe
./stopwatch.exe
```

Then enter the hours, minutes, and seconds when prompted, and watch the countdown run in your console.

**Option 2: Run online (no installation needed)**

Try it directly in your browser via [OnlineGDB](https://www.onlinegdb.com/kDLipqIlso#).

## 📋 Example

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

## ⚠️ Limitations

- Windows-only (relies on `Sleep()` and `system("cls")`)
- No pause/resume functionality
- No sound/alarm on completion
- Console-based only (no GUI)

## 🔥 Future Improvements

- Add pause and resume controls
- Add a sound alert when the countdown ends
- Make it cross-platform (replace Windows-specific calls)
- Add a GUI version (Qt / Windows Forms)

## 👤 Author

Abdullah Aziz
