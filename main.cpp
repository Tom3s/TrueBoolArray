#include "TrueBoolTests.h"
#include <iostream>

//8653ms - baseline
int main(){
   __do_all_tests();
    
    // int index = 3;
    // unsigned char a = 0b0;
    // a= (a|(0b1 << index));
    // __asm__("nop");
    // std::cout << (int)a ;

    // Initialize, set and get 5m elements: 554ms - TrueBool
    // Initialize, set and get 5m elements: 114ms - Normal Array
    // Initialize, set and get 5m elements: 2328ms - Vector

    // Initialize, set and get 5m elements: 411ms - bitwise
    // Initialize, set and get 5m elements: 377ms - bitwise, less allocation
    // Initialize, set and get 5m elements: 318ms - bitwise, least allocation


    return 0;
}