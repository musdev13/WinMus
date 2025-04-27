#include "WinMus.h"

namespace fs = std::filesystem;

class Group {
public:
    std::string name;
    std::vector<int> ext;
};

void sortFilesMenu(fs::path* root){
    bool running = true;
    std::vector<Group> groups;
    while (running)
    {
        system("cls");
        printf("┌────────────────────┐\n");
        printf("│     Sort Files     │\n");
        printf("└────────────────────┘\n\n");
        printf("Path: %s\n", root->string().c_str());
        printf("1. Change Path\n2. Add Group\n3. List Groups\n4. Remove Group\n");
        printf("\nx. Back\n");
        printf("Choice: ");
        system("pause");
    }
    
}
void sortFilesUTIL(){
    system("cls");
    printf("┌────────────────────┐\n");
    printf("│     Sort Files     │\n");
    printf("└────────────────────┘\n\n");
    printf("Put folder with files for sorting:\n");
    fs::path root; std::cin >> root;
    // for (const auto& l: fs::directory_iterator(root)) {
    //     printf("%s - %s - %s\n", l.path().filename().string().c_str(), (l.is_directory() ? "Dir":"File"), l.path().extension().string().c_str());
    // }
    sortFilesMenu(&root);
    system("pause");
}