#pragma once

#include "TrueBool.h"
#include <stdlib.h>
#include <stdexcept>

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

bool TrueBoolArray::get_bit_0(bitf field){
    return (field % 2 == 1);
}
bool TrueBoolArray::get_bit_1(bitf field){
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
    */  
    bitf new_field = field / 2; //bitshift once to right
    return (new_field % 2 == 1);
}
bool TrueBoolArray::get_bit_2(bitf field){
    bitf new_field = field / 4; //bitshift twice to right
    return (new_field % 2 == 1);
}
bool TrueBoolArray::get_bit_3(bitf field){
    bitf new_field = field / 8; //bitshift 3 times to right
    return (new_field % 2 == 1);
}
bool TrueBoolArray::get_bit_4(bitf field){
    bitf new_field = field / 16; //bitshift 4 times to right
    return (new_field % 2 == 1);
}
bool TrueBoolArray::get_bit_5(bitf field){
    bitf new_field = field / 32; //bitshift 5 times to right
    return (new_field % 2 == 1);
}
bool TrueBoolArray::get_bit_6(bitf field){
    bitf new_field = field / 64; //bitshift 6 times to right
    return (new_field % 2 == 1);
}
bool TrueBoolArray::get_bit_7(bitf field){
    bitf new_field = field / 128; //bitshift 7 times to right
    return (new_field % 2 == 1);
}

void TrueBoolArray::set_bit_0(bitf& field, bool new_value){
    if (!this->get_bit_0(field) && new_value) field += 1;
    if (this->get_bit_0(field) && !new_value) field -= 1;
}
void TrueBoolArray::set_bit_1(bitf& field, bool new_value){
    if (!this->get_bit_1(field) && new_value) field += 2;
    if (this->get_bit_1(field) && !new_value) field -= 2;
}
void TrueBoolArray::set_bit_2(bitf& field, bool new_value){
    if (!this->get_bit_2(field) && new_value) field += 4;
    if (this->get_bit_2(field) && !new_value) field -= 4;
}
void TrueBoolArray::set_bit_3(bitf& field, bool new_value){
    if (!this->get_bit_3(field) && new_value) field += 8;
    if (this->get_bit_3(field) && !new_value) field -= 8;
}
void TrueBoolArray::set_bit_4(bitf& field, bool new_value){
    if (!this->get_bit_4(field) && new_value) field += 16;
    if (this->get_bit_4(field) && !new_value) field -= 16;
}
void TrueBoolArray::set_bit_5(bitf& field, bool new_value){
    if (!this->get_bit_5(field) && new_value) field += 32;
    if (this->get_bit_5(field) && !new_value) field -= 32;
}
void TrueBoolArray::set_bit_6(bitf& field, bool new_value){
    if (!this->get_bit_6(field) && new_value) field += 64;
    if (this->get_bit_6(field) && !new_value) field -= 64;
}
void TrueBoolArray::set_bit_7(bitf& field, bool new_value){
    if (!this->get_bit_7(field) && new_value) field += 128;
    if (this->get_bit_7(field) && !new_value) field -= 128;
}

bool TrueBoolArray::get(int index){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to retrieve data");
    }

    int eight = 8;
    int true_index, bit_place;
    true_index = index / eight;
    bit_place = index % eight;
    //div_t division = div(index, 8);

    //bitf current = this->bitfield[true_index];

    switch (bit_place){
        case 0:
            return get_bit_0(this->bitfield[true_index]);
            break;
        case 1:
            return get_bit_1(this->bitfield[true_index]);
            break;
        case 2:
            return get_bit_2(this->bitfield[true_index]);
            break;
        case 3:
            return get_bit_3(this->bitfield[true_index]);
            break;
        case 4:
            return get_bit_4(this->bitfield[true_index]);
            break;
        case 5:
            return get_bit_5(this->bitfield[true_index]);
            break;
        case 6:
            return get_bit_6(this->bitfield[true_index]);
            break;
        case 7:
            return get_bit_7(this->bitfield[true_index]);
            break;
    }
}
void TrueBoolArray::set(int index, bool new_value){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to set data");
    }
    int eight = 8;
    int true_index, bit_place;
    true_index = index / eight;
    bit_place = index % eight;
    //div_t division = div(index, 8);

    //bitf current = this->bitfield[true_index];

    switch (bit_place){
        case 0:
            set_bit_0(this->bitfield[true_index], new_value);
            break;
        case 1:
            set_bit_1(this->bitfield[true_index], new_value);
            break;
        case 2:
            set_bit_2(this->bitfield[true_index], new_value);
            break;
        case 3:
            set_bit_3(this->bitfield[true_index], new_value);
            break;
        case 4:
            set_bit_4(this->bitfield[true_index], new_value);
            break;
        case 5:
            set_bit_5(this->bitfield[true_index], new_value);
            break;
        case 6:
            set_bit_6(this->bitfield[true_index], new_value);
            break;
        case 7:
            set_bit_7(this->bitfield[true_index], new_value);
            break;
    }
}

TrueBoolArray::~TrueBoolArray(){
    delete[] this->bitfield;
}

#include "TrueBoolTests.hpp"