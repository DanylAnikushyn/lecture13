#include <gtest/gtest.h>
#include "graph.hpp"

#include <iostream>
#include <stdexcept>

TEST(graph, graph)
{
    Graph graph;
    auto neighbors1 = std::vector<std::string>{"E2", "E3"};
    auto neighbors2 = std::vector<std::string>{"E3"};
    auto neighbors3 = std::vector<std::string>{"E1"};
    graph.add_edge("E1", neighbors1);
    graph.add_edge("E2", neighbors2);
    graph.add_edge("E3", neighbors3);
    GTEST_ASSERT_EQ(neighbors1, graph.get_edge("E1"));
    GTEST_ASSERT_EQ(neighbors2, graph.get_edge("E2"));
    GTEST_ASSERT_EQ(neighbors3, graph.get_edge("E3"));
    graph.remove_edge("E1");
    ASSERT_THROW(graph.get_edge("E1"), std::out_of_range);
    graph.remove_edge("E2");
    ASSERT_THROW(graph.get_edge("E2"), std::out_of_range);
    graph.remove_edge("E3");
    ASSERT_THROW(graph.get_edge("E3"), std::out_of_range);
}

TEST(graph, parsing)
{
    auto graph = Graph::parse_from_file("../test1.txt");
    
    auto neighbors1 = std::vector<std::string>{"E2", "E3"};
    auto neighbors2 = std::vector<std::string>{"E3"};
    auto neighbors3 = std::vector<std::string>{"E1"};

    GTEST_ASSERT_EQ(neighbors1, graph->get_edge("E1"));
    GTEST_ASSERT_EQ(neighbors2, graph->get_edge("E2"));
    GTEST_ASSERT_EQ(neighbors3, graph->get_edge("E3"));
}

TEST(graph, search)
{
    auto graph = Graph::parse_from_file("../test2.txt");

    auto result1 = graph->search("E1", "E6");
    GTEST_ASSERT_EQ(result1.at("E1"), "E1");
    GTEST_ASSERT_EQ(result1.at("E2"), "E1");
    GTEST_ASSERT_EQ(result1.at("E3"), "E2");
    GTEST_ASSERT_EQ(result1.at("E4"), "E2");
    GTEST_ASSERT_EQ(result1.at("E5"), "E4");
    GTEST_ASSERT_EQ(result1.at("E6"), "E5");
    
    auto result2 = graph->search("E3", "E1");
    GTEST_ASSERT_EQ(result2.at("E3"), "E3");
    ASSERT_THROW(result2.at("E1"), std::out_of_range);
    ASSERT_THROW(result2.at("E2"), std::out_of_range);
    ASSERT_THROW(result2.at("E4"), std::out_of_range);
    ASSERT_THROW(result2.at("E5"), std::out_of_range);
    ASSERT_THROW(result2.at("E6"), std::out_of_range);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
