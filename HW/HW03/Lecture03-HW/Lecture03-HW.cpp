#include <stdio.h>
#include <sstream>
#include <iostream>

#ifdef _WIN32
#include <windows.h> 
#endif

#ifdef _WIN32
enum ForeColour {
    Default = 0x0008,
    Black = 0x0000,
    Blue = 0x0001,
    Green = 0x0002,
    Cyan = 0x0003,
    Red = 0x0004,
    Magenta = 0x0005,
    Yellow = 0x0006,
    White = 0x0007,
};
#else
enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};
#endif

void PrintConsole(const char* lpszText, short nColor)
{
#ifdef _WIN32
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, nColor | 0x0008);
#else
    std::ostringstream oss;
    oss << "\033[1;" << nColor << "m";
    std::cout << oss.str();
#endif

    std::cout << lpszText;

#ifdef _WIN32
    SetConsoleTextAttribute(hConsole, 0x0008);
#else
    std::cout << "\033[0m";
#endif
}

int main()
{
    PrintConsole("Black", ForeColour::Black);
    PrintConsole("Red", ForeColour::Red);
    PrintConsole("Green", ForeColour::Green);
    PrintConsole("Yellow", ForeColour::Yellow);
    PrintConsole("Blue", ForeColour::Blue);
    PrintConsole("Magenta", ForeColour::Magenta);
    PrintConsole("Cyan", ForeColour::Cyan);
    PrintConsole("White", ForeColour::White);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Black | 0x0008);
    return 0;
}