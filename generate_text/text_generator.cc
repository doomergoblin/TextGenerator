//
// Created by sarin on 12/01/2024.
//
#include "text_generator.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


namespace doomergoblin {

    std::unordered_map<std::string, ListNode> GenerateNodes(std::vector<std::string> text_elems) {
        std::unordered_map<std::string, ListNode> nodes;
        std::string last_elem = text_elems[0];
        nodes.insert({last_elem, ListNode{text_elems[0]}});
        for (int i = 1; i < text_elems.size(); ++i) {
            std::string current = text_elems[i];
            nodes[last_elem].following.push_back(current);
            if (auto search = nodes.find(current); search == nodes.end()) {
                nodes.insert({current, ListNode{current}});
            }
            last_elem = current;
        }
        return nodes;
    }

    std::string GenerateText(std::unordered_map<std::string, ListNode> &nodes) {
        std::string result;
        std::string prior_elem = ".";
        while (nodes.size() > 0) {
            auto pos = (&nodes[prior_elem].following);
            if (pos->size() == 0) {
                break;
            }
            int pos_size = pos->size();
            std::srand(std::time(nullptr));
            int rand_pos = 0 + (std::rand() % pos_size);
            std::string current = (*pos)[rand_pos];
            pos->erase(std::next(pos->begin(), rand_pos));
            if (pos->size() == 0) {
                nodes.erase(prior_elem);
            }
            result += " " + current;
            prior_elem = current;
        }
        return result;
    }
}