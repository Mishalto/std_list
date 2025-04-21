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

TEST(MyList, clear) {
    List<int> list(1);
    list.push_back(2);
    list.clear();
    ASSERT_TRUE(list.is_empty());
    ASSERT_EQ(list.size(), 0);
}

TEST(MyList, push_back) {
    List<int> list;
    list.push_back(4);
    ASSERT_EQ(list.back(), 4);

    list.push_back(2);  // list: 2 4
    ASSERT_EQ(list.back(), 2);
    ASSERT_EQ(list.front(), 4);
}

TEST(MyList, pop_back) {
    List<int> list;
    ASSERT_THROW(list.pop_back(), std::out_of_range);

    list.push_back(1);
    list.pop_back();    // Empty
    ASSERT_TRUE(list.is_empty());

    list.push_back(1);
    list.push_back(2);
    list.pop_back();    // list: 1
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.back(), 1);

    list.push_back(2);
    list.push_back(3);
    list.pop_back();    // list: 1 2
    ASSERT_EQ(list.back(), 2);
}

TEST(MyList, push_front) {
    List<int> list;
    list.push_front(1);
    ASSERT_EQ(list.front(), 1);
    ASSERT_EQ(list.back(), 1);

    list.push_front(2);
    ASSERT_EQ(list.front(), 2);

    list.push_front(3);
    ASSERT_EQ(list.front(), 3);
    ASSERT_EQ(list.back(), 1);
}

TEST(MyList, pop_front) {
    List<int> list;
    ASSERT_THROW(list.pop_front(), std::out_of_range);

    list.push_back(1);
    list.pop_front();
    ASSERT_TRUE(list.is_empty());

    list.push_back(1);
    list.push_back(2);
    list.pop_front();
    ASSERT_EQ(list.front(), 2);
    ASSERT_EQ(list.size(), 1);

    list.push_back(3);
    list.push_back(4);
    list.pop_front();
    ASSERT_EQ(list.front(), 3);
}

TEST(MyList, front) {
    List<int> list;
    EXPECT_THROW(list.front(), std::out_of_range);

    list.push_back(1);
    ASSERT_EQ(list.front(), 1);
}

TEST(MyList, back) {
    List<int> list;
    EXPECT_THROW(list.back(), std::out_of_range);

    list.push_back(1);
    ASSERT_EQ(list.back(), 1);
}

TEST(MyList, is_empty) {
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

TEST(MyList, size) {
    List<int> list;
    ASSERT_EQ(list.size(), 0);

    list.push_back(1);
    ASSERT_EQ(list.size(), 1);

    list.push_back(2);
    ASSERT_EQ(list.size(), 2);

    list.pop_back();
    ASSERT_EQ(list.size(), 1);

    list.pop_back();
    ASSERT_EQ(list.size(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}