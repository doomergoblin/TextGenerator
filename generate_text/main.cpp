#include <iostream>
#include <numeric>
#include "text_generator.h"
#include <iostream>
#include <numeric>
#include <string_view>
#include <vector>
#include <optional>
#include <fstream>
#include <regex>

using ::doomergoblin::GenerateNodes;
using ::doomergoblin::GenerateText;

std::vector<std::string> SplitText(std::string text) {
    std::vector<std::string> words;
    //Source: https://stackoverflow.com/questions/27706443/c-spliting-string-by-delimiters-and-keeping-the-delimiters-in-result
    std::regex split_pattern(R"(\s|'|(?!^)\b)");
    std::sregex_token_iterator iterator(text.begin(), text.end(), split_pattern, -1);
    std::sregex_token_iterator iterator_end;

    while (iterator != iterator_end) {
        if (!iterator->str().empty()) {
            words.push_back(iterator->str());
        }
        ++iterator;
    }
    return words;
}

std::optional<std::string> MaybeGetWords(const char *const path) {
    std::ifstream file;
    file.open(path);

    if (!file.is_open()) {
        return std::nullopt;
    }

    std::string file_content;
    std::string line;
    while (!file.eof()) {
        std::getline(file, line);
        file_content += line;
    }
    return file_content;
}

std::vector<std::string> TextArray(const char *const file_path) {
    std::optional<std::string> file_content = MaybeGetWords(file_path);
    return SplitText(file_content.value());
}

int main() {
    auto nodes = GenerateNodes(TextArray("C:\\spare-time-coding\\doomergoblin\\generate_text\\text.txt"));
    std::string new_text = GenerateText(nodes);

    std::cout << new_text << std::endl;
    return 0;
}
