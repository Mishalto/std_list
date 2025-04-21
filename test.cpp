#include <list.hpp>
#include <iostream>
#include <gtest/gtest.h>

TEST(MyList, default_constuctor) {
    List<int> list;

    ASSERT_EQ(list.is_empty(), true);
}

TEST(MyList, constructor_with_obj) {
    List<int> list(1);

    ASSERT_EQ(list.front(), 1);
    ASSERT_FALSE(list.is_empty());
}

TEST(MyList, check_push_back) {
    List<int> list;
    list.push_back(4);
    ASSERT_EQ(list.back(), 4);

    list.push_back(2);
    ASSERT_EQ(list.back(), 2);
    ASSERT_EQ(list.front(), 4);
}

TEST(MyList, check_front) {
    List<int> list;
    EXPECT_THROW(list.front(), std::out_of_range);

    list.push_back(1);
    ASSERT_EQ(list.front(), 1);
}

TEST(MyList, check_back) {
    List<int> list;
    EXPECT_THROW(list.back(), std::out_of_range);

    list.push_back(1);
    ASSERT_EQ(list.back(), 1);
}

TEST(MyList, check_empty) {
    List<int> list;
    ASSERT_EQ(list.is_empty(), true);
}

TEST(MyList, check_tail) {
    List<int> list(1);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 1);

    list.push_back(2);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 2);

    list.push_back(3);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 3);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}