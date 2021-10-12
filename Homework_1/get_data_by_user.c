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

void print_waybills(int num, waybill_structure const *waybill) {

    for (int i = 0; i < num; i++) {
        printf("\nWaybill #%d\n\tVendor code: %d\n\tNumber: %d\n\tPrice: "
               "%f\n\tWeight: %f\n",
               i + 1, waybill[i].vendore_code, waybill[i].num, waybill[i].price,
               waybill[i].weight);
    }
}

static bool check_input_int(char *input) {

    for (size_t i = 0; input[i] != 0; i++) {

        if (!(input[i] >= '0' && input[i] <= '9')) {
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

        scanf("%s", input);
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

static int set_int(int val, char *msg) {

    char input[10];
    bool res = false;

    printf("%s", msg);

    while (!res) {

        scanf("%s", input);
        res = check_input_int(input);// проверка на int

        if (!res) {

            printf("Error! Input the positive number!\n");
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

waybill_structure input_waybill_values(waybill_structure waybill, int i) {

    printf("\nFill in the details of the of the #%d billway!\n", i + 1);

    waybill.vendore_code =
            set_int(waybill.vendore_code, "Input vendor code of product: ");

    waybill.num = set_int(waybill.num, "Input number of product: ");

    waybill.price = set_double(waybill.price, "Input price of product: ");

    waybill.weight = set_double(waybill.weight, "Input weight of product: ");

    return waybill;
}