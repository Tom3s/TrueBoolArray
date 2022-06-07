#pragma once

typedef unsigned char bitf;
typedef unsigned long long cont_size;
typedef unsigned long long Index;

class TrueBoolArray {
    public:
        TrueBoolArray(cont_size size);
        TrueBoolArray(cont_size new_size, bool initial_value);
        int get_size();
        void resize(cont_size new_size);
        bool get(Index index);
        void set(Index index, bool new_value);
        ~TrueBoolArray();
    
    private:
        bitf* bitfield;
        int size;
};

#include "TrueBool.hpp"