#pragma once

#include "TrueBool.h"
#include <stdlib.h>
#include <stdexcept>

#define eight 8
#define true_index index / eight
#define bit_place index % eight
#define current this->bitfield[true_index]

TrueBoolArray::TrueBoolArray(int size){
    this->size = size;
    int true_size = size/8;
    if (size % 8 != 0) true_size++;

    this->bitfield = new bitf[true_size];
    for (int i = 0; i < true_size; i++){
        this->bitfield[i] = 0;
    }
}

TrueBoolArray::TrueBoolArray(int size, bool initial){
    this->size = size;
    int true_size = size/8;
    if (size % 8 != 0) true_size++;

    this->bitfield = new bitf[true_size];
    for (int i = 0; i < true_size; i++){
        this->bitfield[i] = initial * 255;
    }
}

void TrueBoolArray::resize(int new_size){
    int true_size = new_size/8, old_true_size = this->size/8;
    if (new_size % 8 != 0) true_size++;
    if (this->size % 8 != 0) old_true_size++;

    bitf* new_field = new bitf[true_size];
    for (int i = 0; i < std::min(old_true_size, true_size); i++){
        new_field[i] = this->bitfield[i];
    }
    for (int i = old_true_size; i < true_size; i++){
        new_field[i] = 0;
    }
    this->size = new_size;
    delete[] this->bitfield;
    this->bitfield = new_field;
}

int TrueBoolArray::get_size(){
    return this->size;
}

bool TrueBoolArray::get(int index){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to retrieve data");
    }
    return (current >> bit_place) & 0b1;
}
void TrueBoolArray::set(int index, bool new_value){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to set data");
    }
    current ^= (-new_value ^ current) & (0b1 << bit_place);
}

TrueBoolArray::~TrueBoolArray(){
    delete[] this->bitfield;
}