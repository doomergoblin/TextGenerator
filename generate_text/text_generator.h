//
// Created by sarin on 12/01/2024.
//

#ifndef TEXT_GENERATION_TEXT_GENERATOR_H
#define TEXT_GENERATION_TEXT_GENERATOR_H

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <unordered_map>

namespace doomergoblin {
    struct ListNode {
        std::string value;
        std::vector<std::string> following = {};
    };

    std::string GenerateText(std::unordered_map<std::string, ListNode> &nodes);

    std::unordered_map<std::string, ListNode> GenerateNodes(std::vector<std::string> text_elems);
}

#endif //TEXT_GENERATION_TEXT_GENERATOR_H
