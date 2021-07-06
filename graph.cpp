#include "graph.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::string> Graph::get_edge(const std::string& edge) const
{
    return graph.at(edge); 
}
void Graph::add_edge(const std::string& edge, std::vector<std::string>& neighbors)
{
    graph[edge] = neighbors;
}
void Graph::remove_edge(const std::string& edge)
{
    graph.erase(edge);
}
Graph* Graph::parse_from_file(const std::string& filename)
{
    std::ifstream in(filename);
    
    if (!in)
    {
        std::cerr << "Cannot open the file: " << filename << std::endl;
        return nullptr;
    }

    auto graph = new Graph;

    std::string row;
    std::vector<std::string> neighbors;
    std::string neighbor;
    std::string edge;
    while (std::getline(in, row))
    {
        std::stringstream str_stream(row);
        if (!std::getline(str_stream, edge, ' ')) {
            return graph;
        }
        while (std::getline(str_stream, neighbor, ' ')) 
        {
            neighbors.push_back(neighbor);
        }
        graph->add_edge(edge, neighbors);
        neighbors.clear();
    }

    in.close();
    return graph;
}