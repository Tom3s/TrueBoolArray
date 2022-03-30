#pragma once

typedef unsigned char bitf;

class TrueBoolArray {
    private:
        bitf* bitfield;
        
        void resize();
        bool get_bit_0(bitf field);
        bool get_bit_1(bitf field);
        bool get_bit_2(bitf field);
        bool get_bit_3(bitf field);
        bool get_bit_4(bitf field);
        bool get_bit_5(bitf field);
        bool get_bit_6(bitf field);
        bool get_bit_7(bitf field);
        void set_bit_0(bitf& field, bool new_value);
        void set_bit_1(bitf& field, bool new_value);
        void set_bit_2(bitf& field, bool new_value);
        void set_bit_3(bitf& field, bool new_value);
        void set_bit_4(bitf& field, bool new_value);
        void set_bit_5(bitf& field, bool new_value);
        void set_bit_6(bitf& field, bool new_value);
        void set_bit_7(bitf& field, bool new_value);
    public:
        TrueBoolArray(int size);
        bool get(int index);
        void set(int index, bool new_value);
        ~TrueBoolArray();
};

#include "TrueBool.hpp"