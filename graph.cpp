#include "graph.hpp"

std::vector<std::string> Graph::get_edge(const std::string& edge) const
{
    return graph.at(edge); 
}
void Graph::add_edge(const std::string& edge, std::vector<std::string>& neighbors)
{
    graph[edge] = neighbors;
}
void Graph:: remove_edge(const std::string& edge)
{
    graph.erase(edge);
}