#include "include_win/medit.h"

int main()
{
    char name[256];

    PrintToConsole("Name: ");
    GetFromConsole(name, 256);

    SetColor(Colors::Green);
    PrintToConsole("Hello, ");
    PrintToConsole(name);
    PrintToConsole("!\n");

    SleepFor(2000);
    return 0;
}