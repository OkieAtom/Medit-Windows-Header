#include "include_win/medit.h"

int main()
{
    int selected = 0;

    EnableEscapeCodes();
    ShowConsoleCursor(false);

    while (true)
    {
        ClearScreen();

        if (selected == 0)
        {
            SetColor(Colors::Green);
            PrintToConsole("> Start\n");
            SetColor(Colors::Reset);
        }
        else
        {
            PrintToConsole("  Start\n");
        }

        if (selected == 1)
        {
            SetColor(Colors::Green);
            PrintToConsole("> Exit\n");
            SetColor(Colors::Reset);
        }
        else
        {
            PrintToConsole("  Exit\n");
        }

        if (GetKey(Key::Up))
        {
            selected--;
        }
        else if (GetKey(Key::Down))
        {
            selected++;
        }
        else if (GetKey(Key::Enter))
        {
            if (selected == 1)
            {
                ClearScreen();
                break;
            }
            else if (selected == 0)
            {
                ClearScreen();
                PrintToConsole("You selected Start!");
                SleepFor(2000);
                break;
            }
        }

        if (selected > 1)
            selected = 0;
        else if (selected < 0)
            selected = 1;

        SleepFor(100);
    }

    ShowConsoleCursor(true);
    return 0;
}