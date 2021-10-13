//
// Created by d3vyatk4 on 09.10.2021.
//

#include "waybill_structure.h"

#ifndef SPLIT_LOGIC_H
#define SPLIT_LOGIC_H

int waybill_split(waybill_structure *waybill, waybill_structure *waybill_new_1,
                  waybill_structure *waybill_new_2, unsigned int num);
void bubble_sort(waybill_structure *waybill, unsigned int num);

#endif