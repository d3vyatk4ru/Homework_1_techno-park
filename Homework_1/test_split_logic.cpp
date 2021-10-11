//
// Created by d3vyatk4 on 09.10.2021.
//

#include "gtest/gtest.h"
extern "C" {
#include "split_logic.h"
#include "waybill_structure.h"
}

#define NUM 10

// проверка корректности логики разделения накладных
TEST(LOGIC_TEST, Split_data_price) {
    
    waybill_structure* waybill = nullptr;
    waybill = new waybill_structure[NUM];

    waybill_structure* new_waybill_1 = nullptr;
    new_waybill_1 = new waybill_structure[NUM];

    waybill_structure* new_waybill_2 = nullptr;
    new_waybill_2 = new waybill_structure[NUM];

    // правильный ответ
    double correct_waybill_1[5] = {10, 7, 5, 4, 2};
    double correct_waybill_2[5] = {9, 8, 6, 3, 1};

    // автоматическое заполнение
    for ( int i = 0; i < 10; i++ ) {
        waybill[i].price = i + 1;
        waybill[i].num = i + 1;
    }

    int num_1 = waybill_split(waybill, new_waybill_1, new_waybill_2, NUM);
    delete waybill;

    // проверка на кол-во накладных
    EXPECT_EQ(num_1, 5);

    // проверка самих значений в накладных
    for( int i = 0; i < num_1; i++ ) {
        EXPECT_EQ(new_waybill_1[i].num, correct_waybill_1[i]);
    }

    for( int i = 0; i < NUM - num_1; i++ ) {
        EXPECT_EQ(new_waybill_2[i].num, correct_waybill_2[i]);
    }

    delete new_waybill_1;
    delete new_waybill_2;
}

// корректность сортировки
TEST(SORT_TEST, simple_sort)
{
    waybill_structure* waybill = nullptr;
    waybill = new waybill_structure[NUM];

    for (int i = 0; i < NUM; i++) {
        waybill[i].price = i + 1;
        waybill[i].num = i + 1;
    }

    bubble_sort(waybill, NUM);
    for (int i = 0; i < NUM; i++) {
        EXPECT_EQ(waybill[i].num, NUM - i );
    }

    delete waybill;
}

int main(int argc, char** argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
