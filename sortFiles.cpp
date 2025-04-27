#include "WinMus.h"

namespace fs = std::filesystem;

class Group {
public:
    std::string name;
    std::vector<std::string> ext;
};

void ChangePatch(fs::path* root){
    system("cls");
    printf("Path: "); std::cin >> *root;
}

void AddGroup(std::vector<Group>* groups){
    Group group;
    std::string ext;
    std::string line;

    system("cls");
    printf("Group name: "); std::cin >> group.name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    printf("Type file extensions(txt png): ");
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> ext)
    {
        group.ext.push_back(ext);
    }
    groups->push_back(group);
}

void ListGroups(std::vector<Group> groups){
    system("cls");
    for (Group group : groups){
        printf("%s:\n", group.name.c_str());
        for (std::string ext : group.ext){
            printf("%s ",ext.c_str());
        } printf("\n");
    }
    system("pause");
}

void RemoveGroup(std::vector<Group>* groups){
    system("cls");
    printf("Group name: "); std::string ch; std::cin >> ch;
    
    for (auto it = groups->begin(); it != groups->end();) {
        if (it->name == ch) {
            it = groups->erase(it);
            return;
        } else {
            ++it;
        }
    }
}

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
        
        printf("Choice: "); std::string ch; std::cin >> ch;
        if (ch == "1") ChangePatch(root);
        else if (ch == "2") AddGroup(&groups);
        else if (ch == "3") ListGroups(groups);
        else if (ch == "4") RemoveGroup(&groups);
        else if (ch == "x") running = false;
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