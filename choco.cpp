#include "choco.h"

void choco::Search(){
    system("cls");
    printf("Search by name: ");
    std::string pckg; std::cin >> pckg;
    std::string command = "choco search " + pckg;
    system(command.c_str());
    system("pause");
}

void choco::Install() {
    system("cls");
    printf("Packages names(firefox git): ");
    std::string pckgs; std::cin >> pckgs;
    std::string command = "/c choco install -y "+pckgs;
    ShellExecuteA(NULL, "runas", "cmd.exe", command.c_str(), NULL, SW_SHOWNORMAL);
    system("pause");
}

void choco::List(){
    system("cls");system("choco list");system("pause");
}

void choco::Uninstall(){
    system("cls");
    printf("Packages names(firefox git): ");
    std::string pckgs; std::cin >> pckgs;
    std::string command = "/c choco uninstall -y "+pckgs;
    ShellExecuteA(NULL, "runas", "cmd.exe", command.c_str(), NULL, SW_SHOWNORMAL);
    system("pause");
}

void choco::InstallChoco(){
    system("cls");
    printf("!It'll use powershell as admin to install choco!\n");
    system("pause");
    const char* powershellCmd =
        "-NoProfile -ExecutionPolicy Bypass -Command \""
        "Set-ExecutionPolicy Bypass -Scope Process -Force; "
        "[System.Net.ServicePointManager]::SecurityProtocol = "
        "[System.Net.ServicePointManager]::SecurityProtocol -bor 3072; "
        "iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1')); "
        "Read-Host -Prompt 'Нажмите Enter для выхода'\"";
    ShellExecuteA(NULL, "runas", "powershell.exe", powershellCmd, NULL, SW_SHOWNORMAL);
    printf("I think that it was install\n");
    system("pause");
}

void chocoMenu(){
    bool running = true;
    choco choco;
    while (running)
    {
        system("cls");
        printf("Choco\n");
        for (int i = 0; i < 20; i++) printf("-");
        printf("\n1. Search Packages\n");
        printf("2. Install Package\n");
        printf("3. List\n");
        printf("4. Uninstall\n");
        printf("\ni. Install choco\nx. Back\n");
        
        printf("Choice: ");
        std::string ch; std::cin >> ch;

        if (ch == "x") running = false;
        else if (ch == "i") choco.InstallChoco();
        else if (ch == "1") choco.Search();
        else if (ch == "2") choco.Install();
        else if (ch == "3") choco.List();
        else if (ch == "4") choco.Uninstall();
    }
}