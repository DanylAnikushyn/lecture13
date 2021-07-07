#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Graph
{
public:
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::vector<std::string> get_edge(const std::string& edge) const;
    void add_edge(const std::string& edge, std::vector<std::string>& neighbors);
    void remove_edge(const std::string& edge);
    std::unordered_map<std::string, std::string>
    search(const std::string& start, const std::string& goal);
    static std::unique_ptr<Graph> parse_from_file(const std::string& filename);
};
