#include <stdio.h>
#include <windows.h>

HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

void teksBiruTua()
    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);

void teksBiruTerang()
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_BLUE);

void teksHijauTua()
    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);

void teksHijauTerang()
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_GREEN);

void teksMerahTua()
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);

void teksMerahTerang()
    SetConsoleTextAttribute(hConsole,FOREGROUND_INTENSITY | FOREGROUND_RED);

void kembalikanWarna()
    SetConsoleTextAttribute(hConsole, saved_attributes);

int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    teksBiruTua();
    printf("Tulisan ini akan berwarna BLUE");

    teksMerahTerang();
    printf("Tulisan ini akan berwarna merah terang");

    kembalikanWarna();
    return 0;
}
