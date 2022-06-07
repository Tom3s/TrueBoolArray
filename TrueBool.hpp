#pragma once

#include "TrueBool.h"
#include <stdlib.h>
#include <stdexcept>

#define __eight 8
#define __true_index index / __eight
#define __bit_place index % __eight
#define __current this->bitfield[__true_index]

/**
 * @brief Construct a new True Bool Array object
 * Note: default value of elements is false (0)
 * 
 * @param size number of elements to store
 */
TrueBoolArray::TrueBoolArray(cont_size size){
    this->size = size;
    cont_size true_size = size/8;
    if (size % 8 != 0) true_size++;

    this->bitfield = new bitf[true_size];
    for (Index i = 0; i < true_size; i++){
        this->bitfield[i] = 0;
    }
}

/**
 * @brief Construct a new True Bool Array object
 * Note: default value of the elements will be set equal to parameter 'initial'
 * 
 * @param size number of elements to store
 * @param initial the initial value of the elements
 */
TrueBoolArray::TrueBoolArray(cont_size size, bool initial){
    this->size = size;
    cont_size true_size = size/8;
    if (size % 8 != 0) true_size++;

    this->bitfield = new bitf[true_size];
    for (Index i = 0; i < true_size; i++){
        this->bitfield[i] = initial * 255;
    }
}

/**
 * @brief Resize the array
 * 
 * @param new_size the desired new size of the array
 * 
 * @post Available elements will be 'new_size'
 * @post If 'new_size' is bigger than the old size, the new elements will default to false (0)
 * @post If 'new_size' is lower than the old size, the array will be cut off
 */
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

/**
 * @brief Get the current capacity of the array
 * 
 * @return the current capacity of the array -> int
 */
int TrueBoolArray::get_size(){
    return this->size;
}

/**
 * @brief Get value of element at index
 * 
 * @param index index of the desired element (starting from 0)
 * @return value of element at 'index' -> bool
 * 
 * @throws std::out_of_range Thrown if the index parameter is negative, larger or equal to the current size of the array
 * 
 */
bool TrueBoolArray::get(cont_size index){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to retrieve data");
    }
    return (__current >> __bit_place) & 0b1;
}
/**
 * @brief Set value of element at index
 * 
 * @param index index of the desired element (starting from 0)
 * @param new_value the new value of the element at 'index'
 * 
 * @throws std::out_of_range Thrown if the index parameter is negative, larger or equal to the current size of the array
 */
void TrueBoolArray::set(cont_size index, bool new_value){
    if (index < 0 || index >= this->size){
        throw std::out_of_range("Index outside of range while trying to set data");
    }
    __current ^= (-new_value ^ __current) & (0b1 << __bit_place);
}

/**
 * @brief Destroy the True Bool Array object
 * 
 */
TrueBoolArray::~TrueBoolArray(){
    delete[] this->bitfield;
}