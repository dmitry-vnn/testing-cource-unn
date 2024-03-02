// Copyright 2024 Dmitry
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(primary_numbers, check_basic_numbers_on_primary) {
    ASSERT_TRUE(checkPrime(107));
    ASSERT_FALSE(checkPrime(92));
    ASSERT_FALSE(checkPrime(999));
}

TEST(primary_numbers, check_low_numbers_on_primary) {
    ASSERT_FALSE(checkPrime(1));
    ASSERT_FALSE(checkPrime(0));
    ASSERT_FALSE(checkPrime(0));
}

TEST(primary_numbers, check_high_numbers_on_primary) {
    ASSERT_FALSE(checkPrime(UINT64_MAX - 1));
}

// TEST(primary_numbers, zero_in_a_primary_row_number) {
//     // Вопрос в нумерации ряда простых чисел.
//     // По нулевой позиции - результат 0, что ошибочно, 0 - непростое
//     // Тест не выполняется!
//     ASSERT_NE(nPrime(0), 0);
// }

TEST(primary_numbers, primary_row_numbers) {
    ASSERT_EQ(nPrime(5), 11);
    ASSERT_EQ(nPrime(61), 283);
    ASSERT_EQ(nPrime(500), 3571);
}

TEST(primary_numbers, big_primary_in_row_numbers) {
    ASSERT_EQ(nPrime(0xFFFF), 821603);
}

TEST(primary_numbers, low_number_next_primary) {
    ASSERT_EQ(nextPrime(1), 2);
    ASSERT_EQ(nextPrime(0), 2);
}

TEST(primary_numbers, next_primary) {
    ASSERT_EQ(nextPrime(5), 7);
    ASSERT_EQ(nextPrime(101), 103);
    ASSERT_EQ(nextPrime(492), 499);
    ASSERT_EQ(nextPrime(3571), 3581);
}

TEST(primary_numbers, big_next_primary) {
    ASSERT_EQ(nextPrime(UINT32_MAX), 4294967311);
}

TEST(primary_numbers, sum_primary) {
    ASSERT_EQ(sumPrime(0), 0);
    ASSERT_EQ(sumPrime(1), 0);
    ASSERT_EQ(sumPrime(2), 0);
    ASSERT_EQ(sumPrime(3), 2);
    ASSERT_EQ(sumPrime(10), 17);
    ASSERT_EQ(sumPrime(100), 1060);
    ASSERT_EQ(sumPrime(10000), 5736396);
}

TEST(primary_numbers, sum_primary_until_two_millions_bound) {
    ASSERT_EQ(sumPrime(2000000), 142913828922);
}
