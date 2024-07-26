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

TEST(CapacityTest, reserve_test1) {
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

TEST(CapacityTest, empty_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector1.empty() == test_vector2.empty());
}

TEST(CapacityTest, empty_test2) {
    s21::vector<int> test_vector1;
    std::vector<int> test_vector2;
    EXPECT_TRUE(test_vector1.empty() == test_vector2.empty());
}

TEST(CapacityTest, shrink_to_fit_test1) {
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

TEST(ElementAccessTest, at_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.at(0) == 1);
}

TEST(ElementAccessTest, at_test2) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.at(7) == 8);
}

TEST(ElementAccessTest, at_test3) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.at(3) == 4);
}

TEST(ElementAccessTest, at_test4) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_THROW(test_vector.at(11), std::out_of_range);
}

TEST(ElementAccessTest, at_test5) {
    s21::vector<int> test_vector;
    EXPECT_THROW(test_vector.at(0), std::out_of_range);
}

TEST(ElementAccessTest, brackets_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector[0] == 1);
}

TEST(ElementAccessTest, brackets_test2) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector[7] == 8);
}

TEST(ElementAccessTest, brackets_test3) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector[3] == 4);
}

TEST(ElementAccessTest, front_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.front() == test_vector2.front());
}

TEST(ElementAccessTest, back_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.back() == test_vector2.back());
}

TEST(ElementAccessTest, data_test1) {
    s21::vector<int> test_vector{1,2,3,4,5,6,7,8};
    EXPECT_TRUE(test_vector.data() == test_vector.get_data());
}

TEST(ModifiersTest, clear_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    test_vector1.clear();
    test_vector2.clear();
    EXPECT_TRUE(test_vector1.size() == test_vector2.size());
    EXPECT_TRUE(test_vector1.capacity() == test_vector2.capacity());
}

TEST(IteratorsTest, iter_begin_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    EXPECT_TRUE(*iter == 1);
}

TEST(IteratorsTest, iter_end_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.end() - 1;
    EXPECT_TRUE(*iter == 8);
}

TEST(ModifiersTest, erase_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    iter++;
    test_vector1.erase(iter);
    EXPECT_TRUE(test_vector1.size() == 7);
    for (int i = 0; i < *test_vector1.end() - 1; i++) {
        if (i >= 1) {
            EXPECT_TRUE(test_vector1[i] == i + 2);
        } else {
            EXPECT_TRUE(test_vector1[i] == i + 1);
        }
    }
}

TEST(ModifiersTest, erase_test2) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    test_vector1.erase(iter);
    EXPECT_TRUE(test_vector1.size() == 7);
    for (int i = 0; i < *test_vector1.end() - 1; i++) {
        if (i >= 0) {
            EXPECT_TRUE(test_vector1[i] == i + 2);
        }
    }
}

TEST(ModifiersTest, erase_test3) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.end();
    iter--;
    test_vector1.erase(iter);
    EXPECT_TRUE(test_vector1.size() == 7);
    for (int i = 0; i < *test_vector1.end() - 1; i++) {
        if (i >= 7) {
            EXPECT_TRUE(test_vector1[i] == i + 2);
        } else {
            EXPECT_TRUE(test_vector1[i] == i + 1);
        }
    }
}

TEST(ModifiersTest, erase_test4) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    iter--;
    EXPECT_THROW(test_vector1.erase(iter), std::out_of_range);
}

TEST(ModifiersTest, erase_test5) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.end();
    EXPECT_THROW(test_vector1.erase(iter), std::out_of_range);
}

TEST(ModifiersTest, insert_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    test_vector1.reserve(50);
    s21::vector<int>::iterator iter = test_vector1.begin();
    iter++;
    test_vector1.insert(iter, 5);
    EXPECT_EQ(test_vector1[0], 1);
    EXPECT_EQ(test_vector1[1], 5);
    for (int i = 2; i < 8; i++) {
        EXPECT_EQ(test_vector1[i], i);
    }
}

TEST(ModifiersTest, insert_test2) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter = test_vector1.begin();
    iter++;
    test_vector1.insert(iter, 5);
    EXPECT_EQ(test_vector1[0], 1);
    EXPECT_EQ(test_vector1[1], 5);
    for (int i = 2; i < 8; i++) {
        EXPECT_EQ(test_vector1[i], i);
    }
}

TEST(ModifiersTest, insert_test3) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter1 = test_vector1.begin();
    std::vector<int>::iterator iter2 = test_vector2.begin();
    test_vector1.insert(iter1, 5);
    test_vector2.insert(iter2, 5);
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(test_vector1[i], test_vector2[i]);
    }
}

TEST(ModifiersTest, insert_test4) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    s21::vector<int>::iterator iter1 = test_vector1.end() - 1;
    std::vector<int>::iterator iter2 = test_vector2.end() - 1;
    auto iter_result1 = test_vector1.insert(iter1, 5);
    auto iter_result2 = test_vector2.insert(iter2, 5);
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(test_vector1[i], test_vector2[i]);
    }
    EXPECT_TRUE(*iter_result1 == *iter_result2);
}

TEST(ModifiersTest, push_back_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    test_vector1.push_back(5);
    test_vector2.push_back(5);
    for (int i = 0; i < 9; i++) {
        EXPECT_EQ(test_vector1[i], test_vector2[i]);
    }
}

TEST(ModifiersTest, push_back_test2) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    test_vector1.push_back(5);
    test_vector1.push_back(6);
    test_vector1.push_back(11);
    test_vector1.push_back(367);
    test_vector2.push_back(5);
    test_vector2.push_back(6);
    test_vector2.push_back(11);
    test_vector2.push_back(367);
    for (int i = 0; i < 12; i++) {
        EXPECT_EQ(test_vector1[i], test_vector2[i]);
    }
}

TEST(ModifiersTest, pop_back_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector2{1,2,3,4,5,6,7,8};
    test_vector1.pop_back();
    test_vector2.pop_back();
    for (size_t i = 0; i < test_vector1.size(); i++) {
        EXPECT_EQ(test_vector1[i], test_vector2[i]);
    }
}

TEST(ModifiersTest, swap_test1) {
    s21::vector<int> test_vector1{1,2,3,4,5,6,7,8};
    s21::vector<int> test_vector2{99,88,77,66};

    std::vector<int> test_vector3{1,2,3,4,5,6,7,8};
    std::vector<int> test_vector4{99,88,77,66};
    test_vector1.swap(test_vector2);
    test_vector3.swap(test_vector4);
    for (size_t i = 0; i < test_vector1.size(); i++) {
        EXPECT_EQ(test_vector1[i], test_vector3[i]);
    }
    for (size_t i = 0; i < test_vector2.size(); i++) {
        EXPECT_EQ(test_vector2[i], test_vector4[i]);
    }
}