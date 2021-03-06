#include "get_data_by_user.h"
#include "split_logic.h"
#include "waybill_structure.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned int num = input_number_waybill();

    if (num == 0) {
        return 0;
    }

    waybill_structure *waybill;
    waybill = (waybill_structure *) malloc(num * sizeof(waybill_structure));

    // в случае успешного выделения памяти продолжаем работу, инче аварийный выход
    if (!waybill) {
        bad_memory(NULL, NULL);
        return 1;
    }

    for (size_t i = 0; i < num; ++i) {
        waybill[i] = input_waybill_values(waybill[i], i);
    }

    waybill_structure *new_waybill_1, *new_waybill_2;
    new_waybill_1 = (waybill_structure *) malloc(num * sizeof(waybill_structure));

    if (!new_waybill_1) {
        bad_memory(waybill, NULL);
        return 1;
    }

    new_waybill_2 = (waybill_structure *) malloc(num * sizeof(waybill_structure));
    if (!new_waybill_2) {
        bad_memory(waybill, new_waybill_1);
        return 1;
    }

    unsigned int criterion = input_split_criterion();

    // разделение на 2 накладные
    unsigned int count_1 = waybill_split(waybill, new_waybill_1, new_waybill_2, num, criterion);
    free(waybill);

    print_waybills(count_1, new_waybill_1);
    free(new_waybill_1);
    printf("#####################################################################");
    print_waybills(num - count_1, new_waybill_2);
    free(new_waybill_2);

    return 0;
}
