#include "get_data_by_user.h"
#include "waybill_structure.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*  void print_waybills(int num,  waybill_structure const * waybill) --- выводит
   на экран накладные;

    static bool check_input_int(char* input) --- проверяет число на int;

    static bool check_input_double(char* input) --- проверяет число на double
   (float);

    input_number_waybill() --- возвращает количество наладных, введенных
   пользователем;

    static int set_int(int val, char* msg) --- делает запись переменных в
   накладную, тип которых int;

    static double set_double(double val, char* msg) --- елает запись переменных
   в накладную, тип которых double (float);

    waybill_structure input_waybill_values(waybill_structure waybill, int i) ---
   заполняет накладную и вовзращает ее;
*/

void bad_memory(waybill_structure *waybill, waybill_structure *waybill_1) {

    printf("Error! Can't allocate memory!");

    if ((waybill) && (waybill_1)) {
        free(waybill);
        free(waybill_1);
    } else if (waybill) {
        free(waybill);
    }
}

void print_waybills(unsigned int num, waybill_structure const *waybill) {

    if (waybill) {
        for (size_t i = 0; i < num; ++i) {
            printf("\nWaybill #%lu\n\tVendor code: %u\n\tNumber: %u\n\tPrice: "
                   "%f\n\tWeight: %f\n",
                   i + 1, waybill[i].vendore_code, waybill[i].num, waybill[i].price,
                   waybill[i].weight);
        }
    }
}

static bool check_input_int(char *input) {

    for (size_t i = 0; input[i] != 0; ++i) {

        if (!(input[i] >= '0' && input[i] <= '9')) {
            return false;
        }
    }

    return true;
}

static bool check_input_01(char *input) {

    for (size_t i = 0; input[i] != 0; ++i) {

        if (!(input[i] >= '0' && input[i] <= '1')) {
            return false;
        }
    }

    return true;
}

int input_number_waybill() {

    bool res = false;
    char input[10];

    printf("Input the number of waybill: ");

    while (!res) {

        scanf("%9s", input);
        res = check_input_int(input);

        if (!res) {
            printf("Error! Input the natural number!\n");
            printf("%s", "Input the number of waybill: ");
        }

        while ((getchar()) != '\n')
            ;// очистка буфера
    }

    int num = atoi(input);

    return num;
}

static int set_int(unsigned int val, char *msg, bool key) {

    char input[10];
    bool res = false;

    printf("%s", msg);

    while (!res) {

        scanf("%9s", input);
        if (key) {
            res = check_input_int(input); // проверка на uint
        } else {
            res = check_input_01(input); // проверка на 0 и 1
        }

        if (!res) {

            printf("Error! Input the positive correct number!\n");
            printf("%s", msg);
            while ((getchar()) != '\n')
                ;
        }
    }

    val = atoi(input);

    return val;
}

static double set_double(double val, char *msg) {

    printf("%s", msg);

    while (val < 0 || scanf("%lf", &val) != 1) {

        printf("Error! Input the positive number!\n");
        printf("%s", msg);
        while ((getchar()) != '\n')
            ;
    }

    return val;
}

waybill_structure input_waybill_values(waybill_structure waybill, unsigned int i) {

    printf("\nFill in the details of the of the #%u billway!\n", i + 1);

    waybill.vendore_code = set_int(waybill.vendore_code, "Input vendor code of product: ", true);

    waybill.num = set_int(waybill.num, "Input number of product: ", true);

    waybill.price = set_double(waybill.price, "Input price of product: ");

    waybill.weight = set_double(waybill.weight, "Input weight of product: ");

    return waybill;
}

unsigned int input_split_criterion() {

    unsigned int criterion = 0;

    criterion = set_int(criterion, "\nInput number {0, 1} for criterion of splitting.\n 0) Price criterion;\n 1) Weight criterion.\n Your answer: ", false);

    return criterion;
}
