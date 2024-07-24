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

TEST(ConstructorTest, reserve_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.get_size() == 8);
    EXPECT_TRUE(test_vector.get_capacity() == 8);
    test_vector.reserve(50);
    EXPECT_TRUE(test_vector.get_size() == 8);
    EXPECT_TRUE(test_vector.get_capacity() == 50);
    for (size_t i = 0; i < test_vector.get_size(); i++) {
        EXPECT_TRUE(*(test_vector.get_data() + i) == (int) i + 1);
    }
}

TEST(ConstructorTest, shrink_to_fit_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.get_size() == 8);
    EXPECT_TRUE(test_vector.get_capacity() == 8);
    test_vector.reserve(50);
    EXPECT_TRUE(test_vector.get_size() == 8);
    EXPECT_TRUE(test_vector.get_capacity() == 50);
    for (size_t i = 0; i < test_vector.get_size(); i++) {
        EXPECT_TRUE(*(test_vector.get_data() + i) == (int) i + 1);
    }
    test_vector.shrink_to_fit();
    EXPECT_TRUE(test_vector.get_size() == 8);
    EXPECT_TRUE(test_vector.get_capacity() == 8);
}

TEST(ConstructorTest, at_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.at(0) == 1);
}

TEST(ConstructorTest, at_test2) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.at(7) == 8);
}

TEST(ConstructorTest, at_test3) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.at(3) == 4);
}

TEST(ConstructorTest, at_test4) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_THROW(test_vector.at(11), std::out_of_range);
}

TEST(ConstructorTest, at_test5) {
    s21::vector<int> test_vector;
    EXPECT_THROW(test_vector.at(0), std::out_of_range);
}

TEST(ConstructorTest, brackets_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector[0] == 1);
}

TEST(ConstructorTest, brackets_test2) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector[7] == 8);
}

TEST(ConstructorTest, brackets_test3) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector[3] == 4);
}

TEST(ConstructorTest, front_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.front() == test_vector2.front());
}

TEST(ConstructorTest, back_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.back() == test_vector2.back());
}

TEST(ConstructorTest, data_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.data() == test_vector.get_data());
}

TEST(ConstructorTest, clear_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    test_vector1.clear();
    test_vector2.clear();
    EXPECT_TRUE(test_vector1.size() == test_vector2.size());
    EXPECT_TRUE(test_vector1.capacity() == test_vector2.capacity());
}

TEST(ConstructorTest, iter_begin_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    EXPECT_TRUE(*iter == 1);
}

TEST(ConstructorTest, iter_end_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.end();
    EXPECT_TRUE(*iter == 8);
}

TEST(ConstructorTest, erase_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    iter++;
    // s21::vector<int>::iterator iter = iter;
    test_vector1.erase(iter);
    std::cout << "vector1 size is: " << test_vector1.size() << std::endl;
    for (int i = 0; i < *test_vector1.end(); i++) {
        std::cout << "i = " << i << " value: " << test_vector1[i] << " \n";
    }
    std::cout << std::endl;
}