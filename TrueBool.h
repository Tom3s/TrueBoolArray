#pragma once

typedef unsigned char bitf;

class TrueBoolArray {
    private:
        bitf* bitfield;
        int size;
        
    public:
        TrueBoolArray(int size);
        TrueBoolArray(int new_size, bool initial_value);
        int get_size();
        void resize(int new_size);
        bool get(int index);
        void set(int index, bool new_value);
        ~TrueBoolArray();
};

#include "TrueBool.hpp"