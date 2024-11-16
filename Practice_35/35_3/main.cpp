#include <iostream>
#include <filesystem>

auto recursiveGetFileNamesByExtension =
        [](std::filesystem::path path, const std::string extension){
            for(auto& p: std::filesystem::recursive_directory_iterator(path)) {
                if (p.is_directory()) break;
                if (p.path().extension().compare(extension)){
                    std::cout << p.path().filename() << '\n';
                }
            }
};

int main() {
    std::cout << "\nTask  #3\n" << std::endl;

    std::string filePath;
    std::cout << "Enter file path: ";
    std::getline(std::cin, filePath);
    std::filesystem::path path(filePath);

    recursiveGetFileNamesByExtension(path, "txt");

    return 0;
}
