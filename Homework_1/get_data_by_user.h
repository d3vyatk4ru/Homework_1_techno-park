//
// Created by d3vyatk4 on 09.10.2021.
//

#include "waybill_structure.h"

#ifndef GET_DATA_BY_USER_H
#define GET_DATA_BY_USER_H

void print_waybills(int num, waybill_structure const *waybill);

int input_number_waybill();

waybill_structure input_waybill_values(waybill_structure waybill, int i);

#endif