#include "wordList.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::string> loadWordList(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return words;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            words.push_back(line);
        }
    }

    return words;
}
