#include "../test.h"

TEST(ConstructorTest, default_constructor_test1) {
    s21::vector<int> test_vector;
    EXPECT_TRUE(test_vector.get_data() == nullptr);
    EXPECT_TRUE(test_vector.get_size() == 0);
    EXPECT_TRUE(test_vector.get_capacity() == 0);
}

TEST(ConstructorTest, constructor_with_size_test1) {
    s21::vector<int> test_vector(5);
    EXPECT_TRUE(test_vector.get_data() != nullptr);
    EXPECT_TRUE(test_vector.get_size() == 5);
    EXPECT_TRUE(test_vector.get_capacity() == 5);
    for (size_t i = 0; i < 5; i++) {
        EXPECT_TRUE(*(test_vector.get_data() + i) == 0);
    }
}

TEST(ConstructorTest, constructor_from_initializer_list_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.get_data() != nullptr);
    EXPECT_TRUE(test_vector.get_size() == 8);
    EXPECT_TRUE(test_vector.get_capacity() == 8);
    for (int i = 0; i < 8; i++) {
        EXPECT_TRUE(*(test_vector.get_data() + i) == i + 1);
    }
}

TEST(ConstructorTest, copy_constructor_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    s21::vector<int> test_vector2(test_vector);
    EXPECT_TRUE(test_vector.get_data() != nullptr);
    EXPECT_TRUE(test_vector.get_data() != test_vector2.get_data());
    EXPECT_TRUE(test_vector.get_size() == test_vector2.get_size());
    EXPECT_TRUE(test_vector.get_capacity() == test_vector2.get_capacity());
    for (int i = 0; i < 8; i++) {
        EXPECT_TRUE(*(test_vector.get_data() + i) == *(test_vector2.get_data() + i));
    }
}

TEST(ConstructorTest, move_constructor_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    s21::vector<int> test_vector2 = std::move(test_vector);
    EXPECT_TRUE(test_vector.get_data() == nullptr);
    EXPECT_TRUE(test_vector.get_size() == 0);
    EXPECT_TRUE(test_vector.get_capacity() == 0);
    EXPECT_TRUE(test_vector2.get_size() == 8);
    EXPECT_TRUE(test_vector2.get_capacity() == 8);
    for (int i = 0; i < 8; i++) {
        EXPECT_TRUE(*(test_vector2.get_data() + i) == i + 1);
    }
}

TEST(ConstructorTest, assignment_constructor_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    s21::vector<int> test_vector2;
    test_vector2 = std::move(test_vector);
    EXPECT_TRUE(test_vector.get_data() == nullptr);
    EXPECT_TRUE(test_vector.get_size() == 0);
    EXPECT_TRUE(test_vector.get_capacity() == 0);
    EXPECT_TRUE(test_vector2.get_size() == 8);
    EXPECT_TRUE(test_vector2.get_size() == 8);
    for (int i = 0; i < 8; i++) {
        EXPECT_TRUE(*(test_vector2.get_data() + i) == i + 1);
    }
}