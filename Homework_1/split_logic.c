//
// Created by d3vyatk4 on 09.10.2021.
//
#include "waybill_structure.h"
#include <stdbool.h>
#include <stddef.h>

void bubble_sort(waybill_structure *waybill, unsigned int num) {

    if (waybill) {

        for (size_t i = 0; i < num; ++i) {

            bool flag = true;

            for (size_t j = 0; j < num - i; ++j) {
                if (waybill[j].price * waybill[j].num <
                    waybill[j + 1].price * waybill[j + 1].num) {
                    flag = false;
                    waybill_structure tmp = waybill[j];
                    waybill[j] = waybill[j + 1];
                    waybill[j + 1] = tmp;
                }
            }
            if (flag) {
                break;
            }
        }
    }
}

int waybill_split(waybill_structure *waybill, waybill_structure *waybill_new_1,
                  waybill_structure *waybill_new_2, unsigned int num) {

    if ((waybill) && (waybill_new_1) && (waybill_new_2)) {

        bubble_sort(waybill, num - 1);

        waybill_new_1[0] = waybill[0];
        waybill_new_2[0] = waybill[1];

        // 2 первых самых больших значение записываем в 2 накладные
        unsigned int num_1 = 1, num_2 = 1;
        double sum_price_1 = waybill_new_1[0].price * waybill_new_1[0].num;
        double sum_price_2 = waybill_new_2[0].price * waybill_new_2[0].num;

        for (size_t i = 2; i < num; ++i) {

            if (sum_price_1 <= sum_price_2) {
                waybill_new_1[num_1++] = waybill[i];
                sum_price_1 += waybill[i].price * waybill[i].num;
            } else {
                waybill_new_2[num_2++] = waybill[i];
                sum_price_2 += waybill[i].price * waybill[i].num;
            }
        }

        return num_1;
    } else

        return 0;
}
