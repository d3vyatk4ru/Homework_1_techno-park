//
// Created by d3vyatk4 on 09.10.2021.
//

#ifndef GET_DATA_BY_USER_H
#define GET_DATA_BY_USER_H

#include "waybill_structure.h"

void bad_memory(waybill_structure *waybill, waybill_structure *waybill_1);

void print_waybills(unsigned int num, waybill_structure const *waybill);

int input_number_waybill();

waybill_structure input_waybill_values(waybill_structure waybill, unsigned int i);

#endif
