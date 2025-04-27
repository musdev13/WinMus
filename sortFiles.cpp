#include "WinMus.h"

namespace fs = std::filesystem;

void sortFilesUTIL(){
    system("cls");
    printf("┌────────────────────┐\n");
    printf("│     Sort Files     │\n");
    printf("└────────────────────┘\n\n");
    printf("Put folder with files for sorting:\n");
    fs::path root; std::cin >> root;
    for (const auto& l: fs::directory_iterator(root)) {
        printf("%s - %s - %s\n", l.path().filename().string().c_str(), (l.is_directory() ? "Dir":"File"), l.path().extension().string().c_str());
    }
    system("pause");
}