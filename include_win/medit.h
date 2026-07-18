#ifndef MEDIT_H
#define MEDIT_H

#include <windows.h>

enum Key
{
    Up = 1,
    Down = 2,
    Right = 3,
    Left = 4,
    Enter = 5,
    Space = 6,
    Esc = 7,
    Start_Key = 8,
    F1 = 9,
    Ctrl = 10,
    Tab = 11,
    Shift = 12,
    Caps_Lock = 13,
    Left_Click = 14,
    Right_Click = 15
};

inline bool GetKey(int key)
{
    HWND CurrentWindow = GetForegroundWindow();
    HWND ConsoleWindow = GetConsoleWindow();

    if (CurrentWindow != ConsoleWindow)
    {
        return false;
    }
    
    int vkCode = 0;

    switch(key)
    {
        case Key::Up: vkCode = VK_UP; break;
        case Key::Down: vkCode = VK_DOWN; break;
        case Key::Right: vkCode = VK_RIGHT; break;
        case Key::Left: vkCode = VK_LEFT; break;
        case Key::Enter: vkCode = VK_RETURN; break;
        case Key::Space: vkCode = VK_SPACE; break;
        case Key::Esc: vkCode = VK_ESCAPE; break;
        case Key::Start_Key: vkCode = VK_LWIN; break;
        case Key::F1: vkCode = VK_F1; break;
        case Key::Ctrl: vkCode = VK_CONTROL; break;
        case Key::Tab: vkCode = VK_TAB; break;
        case Key::Shift: vkCode = VK_SHIFT; break;
        case Key::Caps_Lock: vkCode = VK_CAPITAL; break;
        case Key::Left_Click: vkCode = VK_LBUTTON; break;
        case Key::Right_Click: vkCode = VK_RBUTTON; break;
        default: return false;
    }

    return (GetAsyncKeyState(vkCode) & 0x8000) != 0;
}

inline bool GetKeyEverywhere(int key)
{
    int vkCode = 0;

    switch(key)
    {
        case Key::Up: vkCode = VK_UP; break;
        case Key::Down: vkCode = VK_DOWN; break;
        case Key::Right: vkCode = VK_RIGHT; break;
        case Key::Left: vkCode = VK_LEFT; break;
        case Key::Enter: vkCode = VK_RETURN; break;
        case Key::Space: vkCode = VK_SPACE; break;
        case Key::Esc: vkCode = VK_ESCAPE; break;
        case Key::Start_Key: vkCode = VK_LWIN; break;
        case Key::F1: vkCode = VK_F1; break;
        case Key::Ctrl: vkCode = VK_CONTROL; break;
        case Key::Tab: vkCode = VK_TAB; break;
        case Key::Shift: vkCode = VK_SHIFT; break;
        case Key::Caps_Lock: vkCode = VK_CAPITAL; break;
        case Key::Left_Click: vkCode = VK_LBUTTON; break;
        case Key::Right_Click: vkCode = VK_RBUTTON; break;
        default: return false;
    }

    return (GetAsyncKeyState(vkCode) & 0x8000) != 0; 
}

enum Colors
{
    Red = 1,
    Blue = 2,
    Green = 3,
    White = 4,
    Reset = 5
};

inline bool SetColor(int color)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color)
    {
        case Colors::Red: SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_INTENSITY); break;
        case Colors::Blue: SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_INTENSITY); break;
        case Colors::Green: SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY); break;
        case Colors::White: SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); break;
        case Colors::Reset: SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); break;
        default: return false;
    }

    return true;
}

inline void ClearScreen()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    const char* Escape = "\x1b[2J\x1b[H";
    DWORD bytesWritten;

    WriteConsoleA(console, Escape, 8, &bytesWritten, NULL);
}

inline void EnableEscapeCodes()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode;

    GetConsoleMode(console, &mode);
    SetConsoleMode(console, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

inline void ShowConsoleCursor(bool show)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(console, &cursorInfo);
}

inline int CountFrom(int count, int inter, int m)
{
    for (int i = 0; i < inter; i++)
    {
        count++;
        Sleep(m);
    }

    return count;
}

inline int CountDown(int count, int m)
{
    while (count > 0)
    {
        count--;
        Sleep(m);
    }

    return count;
}

inline void PrintToConsole(const char* text)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    int length = 0;
    while (text[length] != '\0')
    {
        length++;
    }

    DWORD bytesWritten;

    WriteConsoleA(console, text, length, &bytesWritten, NULL);
}

inline void GetFromConsole(char* buffer, int size)
{
    HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
    DWORD read;

    ReadConsoleA(console, buffer, size - 1, &read, NULL);

    if (read > 0 && buffer[read - 1] == '\n') read--;
    if (read > 0 && buffer[read - 1] == '\r') read--;
    buffer[read] = '\0';
}

inline bool StringToInteger(const char* text)
{
    int i = 0;


    if (text == nullptr || text[0] == '\0')
    {
        return false;
    }

    if (text[0] == '-')
    {
        if (text[1] == '\0') return false;
        i = 1;
    }

    while (text[i] != '\0')
    {
        if (text[i] < '0' || text[i] > '9')
        {
            return false;
        }

        i++;
    }

    return true;
}

inline void SleepFor(int m)
{
    Sleep(m);
}

#endif