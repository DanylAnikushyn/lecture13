#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Graph
{
public:
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::vector<std::string> get_edge(const std::string& edge) const;
    void add_edge(const std::string& edge, std::vector<std::string>& neighbors);
    void remove_edge(const std::string& edge);
    static Graph* parse_from_file(const std::string& filename);
};
