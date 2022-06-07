#pragma once

#include "TrueBool.h"
#include <stdlib.h>
#include <stdexcept>

#define eight 8

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

/*
bool TrueBoolArray::get_bit_0(bitf& field){
    return (field % 2);
}
bool TrueBoolArray::get_bit_1(bitf& field){
    /*
    0000 = 0  (false)
    0001 = 1  (false)
    0010 = 2  (true)
    0011 = 3  (true)
    0100 = 4  (false)
    0101 = 5  (false)
    0110 = 6  (true)
    0111 = 7  (true)
    1000 = 8  (false)
    1001 = 9  (false)
    1010 = 10 (true)
    1011 = 11 (true)
    1100 = 12 (false)
    1101 = 13 (false)
    1110 = 14 (true)
    1111 = 15 (true)
     
    //bitf new_field = field / 2; //bitshift once to right
    return ((field / 2) % 2);
}
bool TrueBoolArray::get_bit_2(bitf& field){
    //bitf new_field = field / 4; //bitshift twice to right
    return ((field / 4) % 2);
}
bool TrueBoolArray::get_bit_3(bitf& field){
    //bitf new_field = field / 8; //bitshift 3 times to right
    return ((field / 8) % 2);
}
bool TrueBoolArray::get_bit_4(bitf& field){
    //bitf new_field = field / 16; //bitshift 4 times to right
    return ((field / 16) % 2);
}
bool TrueBoolArray::get_bit_5(bitf& field){
    //bitf new_field = field / 32; //bitshift 5 times to right
    return ((field / 32) % 2);
}
bool TrueBoolArray::get_bit_6(bitf& field){
    //bitf new_field = field / 64; //bitshift 6 times to right
    return ((field / 64) % 2);
}
bool TrueBoolArray::get_bit_7(bitf& field){
    //bitf new_field = field / 128; //bitshift 7 times to right
    return ((field / 128) % 2);
}

void TrueBoolArray::set_bit_0(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_0(field));
    //if (!this->get_bit_0(field) && new_value) field += 1;
    //if (this->get_bit_0(field) && !new_value) field -= 1;
}
void TrueBoolArray::set_bit_1(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_1(field)) * 2;
    // if (!this->get_bit_1(field) && new_value) field += 2;
    // if (this->get_bit_1(field) && !new_value) field -= 2;
}
void TrueBoolArray::set_bit_2(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_2(field)) * 4;
    // if (!this->get_bit_2(field) && new_value) field += 4;
    // if (this->get_bit_2(field) && !new_value) field -= 4;
}
void TrueBoolArray::set_bit_3(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_3(field)) * 8;
    // if (!this->get_bit_3(field) && new_value) field += 8;
    // if (this->get_bit_3(field) && !new_value) field -= 8;
}
void TrueBoolArray::set_bit_4(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_4(field)) * 16;
    // if (!this->get_bit_4(field) && new_value) field += 16;
    // if (this->get_bit_4(field) && !new_value) field -= 16;
}
void TrueBoolArray::set_bit_5(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_5(field)) * 32;
    // if (!this->get_bit_5(field) && new_value) field += 32;
    // if (this->get_bit_5(field) && !new_value) field -= 32;
}
void TrueBoolArray::set_bit_6(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_6(field)) * 64;
    // if (!this->get_bit_6(field) && new_value) field += 64;
    // if (this->get_bit_6(field) && !new_value) field -= 64;
}
void TrueBoolArray::set_bit_7(bitf& field, bool& new_value){
    field += (new_value - this->get_bit_7(field)) * 128;
    // if (!this->get_bit_7(field) && new_value) field += 128;
    // if (this->get_bit_7(field) && !new_value) field -= 128;
}
*/

bool TrueBoolArray::get(int index){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to retrieve data");
    }
    int true_index, bit_place;
    true_index = index / eight;
    bit_place = index % eight;

    bitf current = this->bitfield[true_index];

    return (current >> bit_place) & 0b1;
    return current & (0b1 << bit_place);
}
void TrueBoolArray::set(int index, bool new_value){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to set data");
    }
    int true_index, bit_place;
    true_index = index / eight;
    bit_place = index % eight;
    //div_t division = div(index, 8);

    bitf* current = &this->bitfield[true_index];

    *current ^= (-new_value ^ *current) & (0b1 << bit_place);
}

TrueBoolArray::~TrueBoolArray(){
    delete[] this->bitfield;
}