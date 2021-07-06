#include <gtest/gtest.h>
#include "graph.hpp"

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

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}