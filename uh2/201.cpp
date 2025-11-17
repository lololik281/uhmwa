#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream fin("201 RAW.txt");
    std::ofstream fout("201 ready.txt");
    
    if (!fin.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл '201 RAW.txt'" << std::endl;
        return 1;
    }
    
    if (!fout.is_open()) {
        std::cerr << "Ошибка: не удалось создать файл '201 ready.txt'" << std::endl;
        return 1;
    }
    
    std::string line;
    std::vector<std::pair<std::string, std::string>> addresses;
    
    while (std::getline(fin, line)) {
        if (line.empty()) continue;
        
        std::istringstream iss(line);
        std::string ip, mac;
        
        if (iss >> ip >> mac) {
            addresses.push_back({ip, mac});
        }
    }
    
    for (const auto& addr : addresses) {
        fout << addr.second << "\t\t" << addr.first << std::endl;
    }
    
    fin.close();
    fout.close();
    
    std::cout << "Файл '201 ready.txt' успешно создан!" << std::endl;
    std::cout << "Обработано " << addresses.size() << " строк." << std::endl;
    
    return 0;
}