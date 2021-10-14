//
// Created by d3vyatk4 on 09.10.2021.
//

#include "gtest/gtest.h"
extern "C" {
#include "split_logic.h"
#include "waybill_structure.h"
}

constexpr unsigned NUM = 10;

// проверка корректности логики разделения накладных по цене
TEST(LOGIC_TEST, Split_data_price) {

    waybill_structure *waybill;
    waybill = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    waybill_structure *new_waybill_1, *new_waybill_2;
    new_waybill_1 = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    new_waybill_2 = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    // правильный ответ
    double correct_waybill_1[5] = {10, 7, 5, 4, 2};
    double correct_waybill_2[5] = {9, 8, 6, 3, 1};

    // автоматическое заполнение
    for (size_t i = 0; i < 10; ++i) {
        waybill[i].price = i + 1;
        waybill[i].num = i + 1;
    }

    unsigned int num_1 = waybill_split(waybill, new_waybill_1, new_waybill_2, NUM, 0);
    free(waybill);

    // проверка на кол-во накладных
    EXPECT_EQ(num_1, 5);

    // проверка самих значений в накладных
    for (size_t i = 0; i < num_1; ++i) {
        EXPECT_EQ(new_waybill_1[i].num, correct_waybill_1[i]);
    }

    for (size_t i = 0; i < NUM - num_1; ++i) {
        EXPECT_EQ(new_waybill_2[i].num, correct_waybill_2[i]);
    }

    free(new_waybill_1);
    free(new_waybill_2);
}

// проверка корректности логики разделения накладных по цене
TEST(LOGIC_TEST, Split_data_weight) {

    waybill_structure *waybill;
    waybill = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    waybill_structure *new_waybill_1, *new_waybill_2;
    new_waybill_1 = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    new_waybill_2 = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    // правильный ответ
    double correct_waybill_1[5] = {10, 7, 5, 4, 2};
    double correct_waybill_2[5] = {9, 8, 6, 3, 1};

    // автоматическое заполнение
    for (size_t i = 0; i < 10; ++i) {
        waybill[i].weight = i + 1;
        waybill[i].num = i + 1;
    }

    unsigned int num_1 = waybill_split(waybill, new_waybill_1, new_waybill_2, NUM, 1);
    free(waybill);

    // проверка на кол-во накладных
    EXPECT_EQ(num_1, 5);

    // проверка самих значений в накладных
    for (size_t i = 0; i < num_1; ++i) {
        EXPECT_EQ(new_waybill_1[i].num, correct_waybill_1[i]);
    }

    for (size_t i = 0; i < NUM - num_1; ++i) {
        EXPECT_EQ(new_waybill_2[i].num, correct_waybill_2[i]);
    }

    free(new_waybill_1);
    free(new_waybill_2);
}

// корректность сортировки по цене
TEST(SORT_TEST, Simple_sort_price) {

    waybill_structure *waybill;
    waybill = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    for (size_t i = 0; i < NUM; ++i) {
        waybill[i].price = i + 1;
        waybill[i].num = i + 1;
    }

    bubble_sort(waybill, NUM, 0);
    for (size_t i = 0; i < NUM; ++i) {
        EXPECT_EQ(waybill[i].num, NUM - i);
    }

    free(waybill);
}

// корректность сортировки по весу
TEST(SORT_TEST, Simple_sort_weight) {

    waybill_structure *waybill;
    waybill = (waybill_structure *) malloc(NUM * sizeof(waybill_structure));

    for (size_t i = 0; i < NUM; ++i) {
        waybill[i].price = i + 1;
        waybill[i].num = i + 1;
    }

    bubble_sort(waybill, NUM, 0);
    for (size_t i = 0; i < NUM; ++i) {
        EXPECT_EQ(waybill[i].num, NUM - i);
    }

    free(waybill);
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
