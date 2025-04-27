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

int printMenu(int selected, bool ret) {
    const char* items[] = {
        "Sort Files",
        "exit",
    };

    const int size = sizeof(items) / sizeof(items[0]);

    if (ret) return size;

    printf("┌──────────────────────────┐\n");
    printf("│     WinMus by Mus :3     │\n");
    printf("└──────────────────────────┘\n\n");

    for (int i = 0; i < size; i++)
    {
        if (i == selected) printf("\u2192 %s\n", items[i]);
        else printf("  %s\n", items[i]);
    }
    printf("\n\u2191/\u2193 | Enter: \n");
    return 0;
}

void useThis(int select, bool* running);

void selectChoice(int* select, bool* running){
    int ch = _getch();
    switch (ch)
    {
    case 72:
        if (*select > 0) (*select)--;
        break;
    case 80:
        if (*select < printMenu(*select, true)-1) (*select)++;
        break;

    case 13:
        useThis(*select, running);
        break;
    
    default:
        break;
    }
}

void useThis(int select, bool* running){
    const int last = printMenu(select, true)-1;
    if (select == last) {
        exit(0);
    }
    else if (select == 0) {
        sortFilesUTIL();
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    ResizeConsole();

    bool running = true;
    int select = 0;
    while (running)
    {
        system("cls");
        printMenu(select, false);
        selectChoice(&select, &running);
    }
    system("pause");
    return 0;
}