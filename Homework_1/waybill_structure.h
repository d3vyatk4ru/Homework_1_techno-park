// #pragma once
#ifndef WAYBILL_STRUCTURE_H
#define WAYBILL_STRUCTURE_H

struct waybill_structure {

    int vendore_code;// номер накладной
    int num;         // кол-во единиц товара
    double price;    // цена товара за единицу
    double weight;   // вес товара

} typedef waybill_structure;

#endif