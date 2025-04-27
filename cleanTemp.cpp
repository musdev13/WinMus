#include "WinMus.h"

bool RunCommandAsAdmin(const char* command) {
    std::string params = "/c ";
    params += command;

    SHELLEXECUTEINFOA sei = { sizeof(sei) };
    sei.lpVerb = "runas";
    sei.lpFile = "cmd.exe";
    sei.lpParameters = params.c_str();
    sei.nShow = SW_HIDE;
    sei.fMask = SEE_MASK_NOCLOSEPROCESS;

    if (!ShellExecuteExA(&sei)) {
        DWORD err = GetLastError();
        if (err == ERROR_CANCELLED) {
            printf("User cancelled the admin rights request.\n");
        } else {
            printf("Error launching command as admin. Error code: %lu\n", err);
        }
        return false;
    }

    WaitForSingleObject(sei.hProcess, INFINITE);
    CloseHandle(sei.hProcess);

    return true;
}

void deleteTempFiles() {
    system("cls");

    printf("Cleaning %%TEMP%%...\n");
    if (!RunCommandAsAdmin("rd /s /q \"%TEMP%\" && mkdir \"%TEMP%\"")) {
        printf("Error while cleaning %%TEMP%%\n");
    } else {
        printf("%%TEMP%% was cleaned\n");
    }

    printf("Cleaning C:\\Windows\\Temp...\n");
    if (!RunCommandAsAdmin("rd /s /q \"C:\\Windows\\Temp\" && mkdir \"C:\\Windows\\Temp\"")) {
        printf("Error while cleaning C:\\Windows\\Temp\n");
    } else {
        printf("C:\\Windows\\Temp was cleaned\n");
    }

    system("pause");
}