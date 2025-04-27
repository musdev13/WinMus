#include "WinMus.h"

namespace fs = std::filesystem;

class Group {
public:
    std::string name;
    std::vector<std::string> ext;
};

void SaveSettings(const fs::path& rootPath, const std::vector<Group>& groups) {
    fs::path settingsFile = rootPath / "wmsort";

    std::ofstream out(settingsFile);
    if (!out.is_open()) {
        std::cerr << "Failed to open file for saving settings: " << settingsFile << "\n";
        return;
    }

    out << rootPath.string() << "\n";
    out << groups.size() << "\n";

    for (const auto& group : groups) {
        out << group.name << "\n";
        out << group.ext.size() << "\n";
        for (const auto& ext : group.ext) {
            out << ext << " ";
        }
        out << "\n";
    }
}

bool LoadSettings(fs::path& rootPath, std::vector<Group>& groups) {
    fs::path settingsFile = rootPath / "wmsort";

    std::ifstream in(settingsFile);
    if (!in.is_open()) {
        // Файл не найден - создаём с начальными пустыми данными
        groups.clear();
        SaveSettings(rootPath, groups); // создаём файл с пустыми настройками
        std::cout << "Settings file not found. Created new default settings file at " << settingsFile << "\n";
        return false;
    }

    std::string line;

    if (!std::getline(in, line)) return false;
    rootPath = line;

    if (!std::getline(in, line)) return false;
    size_t groupCount = std::stoul(line);

    groups.clear();

    for (size_t i = 0; i < groupCount; ++i) {
        Group group;

        if (!std::getline(in, group.name)) return false;

        if (!std::getline(in, line)) return false;
        size_t extCount = std::stoul(line);

        if (!std::getline(in, line)) return false;
        std::istringstream iss(line);
        std::string ext;
        for (size_t j = 0; j < extCount; ++j) {
            if (!(iss >> ext)) return false;
            group.ext.push_back(ext);
        }

        groups.push_back(group);
    }

    return true;
}

void ChangePatch(fs::path* root, std::vector<Group>* groups) {
    system("cls");
    std::cout << "Path: ";
    std::cin >> *root;

    // Загружаем настройки из новой папки
    LoadSettings(*root, *groups);
}

void AddGroup(std::vector<Group>* groups) {
    Group group;
    std::string ext;
    std::string line;

    system("cls");
    std::cout << "Group name: ";
    std::cin >> group.name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Type file extensions (e.g. txt png): ";
    std::getline(std::cin, line);
    std::istringstream iss(line);
    while (iss >> ext) {
        group.ext.push_back(ext);
    }
    groups->push_back(group);
}

void ListGroups(const std::vector<Group>& groups) {
    system("cls");
    for (const Group& group : groups) {
        std::cout << group.name << ":\n";
        for (const std::string& ext : group.ext) {
            std::cout << ext << " ";
        }
        std::cout << "\n";
    }
    system("pause");
}

void RemoveGroup(std::vector<Group>* groups) {
    system("cls");
    std::cout << "Group name: ";
    std::string ch;
    std::cin >> ch;

    for (auto it = groups->begin(); it != groups->end();) {
        if (it->name == ch) {
            it = groups->erase(it);
            return;
        }
        else {
            ++it;
        }
    }
}

void SortFiles(fs::path* root, std::vector<Group>* groups) {
    if (!fs::exists(*root) || !fs::is_directory(*root)) {
        std::cerr << "Path does not exist or is not a directory\n";
        return;
    }

    for (const auto& group : *groups) {
        fs::path groupPath = *root / group.name;
        if (!fs::exists(groupPath)) {
            fs::create_directory(groupPath);
        }

        for (const auto& entry : fs::directory_iterator(*root)) {
            if (entry.is_regular_file()) {
                fs::path filePath = entry.path();
                std::string fileExt = filePath.extension().string();

                if (!fileExt.empty() && fileExt[0] == '.') {
                    fileExt = fileExt.substr(1);
                }

                for (const auto& ext : group.ext) {
                    if (fileExt == ext) {
                        fs::path destPath = groupPath / filePath.filename();

                        try {
                            fs::rename(filePath, destPath);
                            std::cout << "Moved file " << filePath.filename() << " to " << group.name << "\n";
                        }
                        catch (const fs::filesystem_error& e) {
                            std::cerr << "Error moving file " << filePath << ": " << e.what() << "\n";
                        }
                        break;
                    }
                }
            }
        }
    }
}

void sortFilesMenu(fs::path* root) {
    bool running = true;
    std::vector<Group> groups;

    LoadSettings(*root, groups);

    while (running) {
        system("cls");
        std::cout << "┌────────────────────┐\n";
        std::cout << "│     Sort Files     │\n";
        std::cout << "└────────────────────┘\n\n";
        std::cout << "Path: " << root->string() << "\n";
        std::cout << "1. Change Path\n2. Add Group\n3. List Groups\n4. Remove Group\n5. Sort Files\nx. Back\n";

        std::cout << "Choice: ";
        std::string ch;
        std::cin >> ch;

        if (ch == "1") ChangePatch(root, &groups);
        else if (ch == "2") AddGroup(&groups);
        else if (ch == "3") ListGroups(groups);
        else if (ch == "4") RemoveGroup(&groups);
        else if (ch == "5") SortFiles(root, &groups);
        else if (ch == "x") running = false;

        SaveSettings(*root, groups);
    }
}

void sortFilesUTIL() {
    system("cls");
    std::cout << "┌────────────────────┐\n";
    std::cout << "│     Sort Files     │\n";
    std::cout << "└────────────────────┘\n\n";
    std::cout << "Put folder with files for sorting:\n";
    fs::path root;
    std::cin >> root;
    sortFilesMenu(&root);
}
