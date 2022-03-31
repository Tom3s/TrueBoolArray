#include "TrueBool.h"

int main(){
    //__do_all_tests();
    TrueBoolArray array = TrueBoolArray(1000000);

    for (int i = 0; i < 1000000; i += 2){
        array.set(i, true);
    }
    for (int i = 0; i < 1000000; i += 2){
        assert(array.get(i) == true);
        assert(array.get(i + 1) == false);
    }
    return 0;
}