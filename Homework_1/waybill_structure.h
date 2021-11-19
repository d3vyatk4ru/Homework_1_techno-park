#ifndef WAYBILL_STRUCTURE_H
#define WAYBILL_STRUCTURE_H

typedef struct waybill_structure {

    unsigned int vendore_code;// номер накладной
    unsigned int num;         // кол-во единиц товара
    double price;             // цена товара за единицу
    double weight;            // вес товара

} waybill_structure;

#endif
