#include <list.hpp>
#include <iostream>
#include <gtest/gtest.h>


TEST(ListTest, can_insert_elem) {
    EXPECT_EQ(5, 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}