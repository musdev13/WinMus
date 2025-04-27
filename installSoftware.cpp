#include "WinMus.h"
#include "choco.h"

bool ChoicePackageManager(){
    while (true)
    {
        system("cls");
        printf("Choice Package Manager:\n");
        printf("1. Choco\n2. Winget\n");
        printf("\nChoice: ");

        int ch; std::cin >> ch;
        if (ch == 1) return true;
        else if (ch == 2) return false;
    }
}

void wingetMenu(){
    system("cls");
    printf("i didn't make this at this moment\n");
    system("pause");
}

void InstallSoftwareMenu(){
    bool pckgm = ChoicePackageManager();
    if (pckgm) chocoMenu();
    else wingetMenu();
}