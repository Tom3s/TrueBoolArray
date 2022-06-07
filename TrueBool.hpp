#pragma once

#include "TrueBool.h"
#include <stdlib.h>
#include <stdexcept>

#define __eight 8
#define __true_index index / __eight
#define __bit_place index % __eight
#define __current this->bitfield[__true_index]

TrueBoolArray::TrueBoolArray(cont_size size){
    this->size = size;
    cont_size true_size = size/8;
    if (size % 8 != 0) true_size++;

    this->bitfield = new bitf[true_size];
    for (Index i = 0; i < true_size; i++){
        this->bitfield[i] = 0;
    }
}

TrueBoolArray::TrueBoolArray(cont_size size, bool initial){
    this->size = size;
    cont_size true_size = size/8;
    if (size % 8 != 0) true_size++;

    this->bitfield = new bitf[true_size];
    for (Index i = 0; i < true_size; i++){
        this->bitfield[i] = initial * 255;
    }
}

void TrueBoolArray::resize(cont_size new_size){
    cont_size true_size = new_size/8, old_true_size = this->size/8;
    if (new_size % 8 != 0) true_size++;
    if (this->size % 8 != 0) old_true_size++;

    bitf* new_field = new bitf[true_size];
    for (Index i = 0; i < std::min(old_true_size, true_size); i++){
        new_field[i] = this->bitfield[i];
    }
    for (Index i = old_true_size; i < true_size; i++){
        new_field[i] = 0;
    }
    this->size = new_size;
    delete[] this->bitfield;
    this->bitfield = new_field;
}

int TrueBoolArray::get_size(){
    return this->size;
}

bool TrueBoolArray::get(cont_size index){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to retrieve data");
    }
    return (__current >> __bit_place) & 0b1;
}
void TrueBoolArray::set(cont_size index, bool new_value){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to set data");
    }
    __current ^= (-new_value ^ __current) & (0b1 << __bit_place);
}

TrueBoolArray::~TrueBoolArray(){
    delete[] this->bitfield;
}