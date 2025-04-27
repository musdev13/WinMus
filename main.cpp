#include "WinMus.h"

void ResizeConsole() {
    HWND hwnd = GetConsoleWindow();
    Sleep(10);
    HWND owner = GetWindow(hwnd, GW_OWNER);

    if (owner == NULL) {
        SetWindowPos(hwnd, nullptr, 0, 0, 50, 50, SWP_NOZORDER | SWP_NOMOVE);
    } else {
        SetWindowPos(owner, nullptr, 0, 0, 0, 500, SWP_NOZORDER | SWP_NOMOVE);
    }
}

void printMenu() {
    const char* items[] = {
        "Sort Files",
        "Install Software",
        "Delete Temp Files"
    };
    const int size = sizeof(items) / sizeof(items[0]);

    printf("┌──────────────────────────┐\n");
    printf("│     WinMus by Mus :3     │\n");
    printf("└──────────────────────────┘\n\n");

    for (int i = 0; i < size; i++)
        printf("%d. %s\n", i+1, items[i]);
    printf("\nx. Exit\n");
    printf("Choice(1-9): ");
}

void selectChoice(bool* running){
    std::string ch; std::cin >> ch;
    if (ch == "x") exit(0);
    else if (ch == "1") sortFilesUTIL();
    else if (ch == "2") InstallSoftwareMenu();
    else if (ch == "3") deleteTempFiles();
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    system("title WinMus");
    ResizeConsole();

    bool running = true;
    while (running)
    {
        system("cls");
        printMenu();
        selectChoice(&running);
    }
    system("pause");
    return 0;
}