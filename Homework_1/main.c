#include "get_data_by_user.h"
#include "split_logic.h"
#include "waybill_structure.h"
#include <malloc.h>
#include <stdlib.h>

int main() {

    int num = input_number_waybill();

    if (num == 0)
        return 0;

    waybill_structure *waybill;

    // в случае успешного выделения памяти продолжаем работу, инче аварийный выход
    if (!(waybill =
                  (waybill_structure *) malloc(num * sizeof(waybill_structure)))) {
        printf("Error: can't allocate memory");
        return 0;
    }

    for (size_t i = 0; i < num; i++) {
        waybill[i] = input_waybill_values(waybill[i], i);
    }

    waybill_structure *new_waybill_1, *new_waybill_2;

    if (!(new_waybill_1 =
                  (waybill_structure *) malloc(num * sizeof(waybill_structure)))) {
        printf("Error: can't allocate memory");
        free(waybill);
        return 0;
    }

    if (!(new_waybill_2 =
                  (waybill_structure *) malloc(num * sizeof(waybill_structure)))) {
        printf("Error: can't allocate memory");
        free(waybill);
        free(new_waybill_1);
        return 0;
    }

    // разделение на 2 накладные
    int count_1 = waybill_split(waybill, new_waybill_1, new_waybill_2, num);
    free(waybill);

    print_waybills(count_1, new_waybill_1);
    free(new_waybill_1);
    printf("#####################################################################");
    print_waybills(num - count_1, new_waybill_2);
    free(new_waybill_2);

    return 0;
}