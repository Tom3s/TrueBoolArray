#pragma once

typedef unsigned char bitf;
typedef unsigned long long cont_size;
typedef unsigned long long Index;

class TrueBoolArray {
    private:
        bitf* bitfield;
        int size;
        
    public:
        TrueBoolArray(cont_size size);
        TrueBoolArray(cont_size new_size, bool initial_value);
        int get_size();
        void resize(cont_size new_size);
        bool get(Index index);
        void set(Index index, bool new_value);
        ~TrueBoolArray();
};

#include "TrueBool.hpp"