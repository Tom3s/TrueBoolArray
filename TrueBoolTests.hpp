#include "TrueBool.h"

#include <cassert>
#include <iostream>

void __prime_sieve_test(){
    TrueBoolArray array = TrueBoolArray(1024, true);

    assert(array.get(0) == true);
    assert(array.get(1) == true);
    array.set(0, false);
    assert(array.get(0) == false);
    array.set(1, false);
    assert(array.get(1) == false);

    for (int i = 2; i < 1024; i++){
        if (array.get(i) == true){
            //assert(array.get(i) == true);
            for (int j = 2; j * i < 1024; j++){
                array.set(j * i, false);
                assert(array.get(j * i) == false);
            }
        }
    }

    for (int i = 0; i < 1024; i++){
        if (array.get(i)) std::cout << i << std::endl;
    }
}

void __resize_test(){
    TrueBoolArray array = TrueBoolArray(300);

    for (int i = 0; i < 300; i += 3){
        array.set(i, true);
    }

    try {
        array.get(-1);
        assert(false);
    } catch (std::exception& ex) {}
    try {
        array.set(-1, false);
        assert(false);
    } catch (std::exception& ex) {}
    try {
        array.get(301);
        assert(false);
    } catch (std::exception& ex) {}
    try {
        array.set(301, false);
        assert(false);
    } catch (std::exception& ex) {}

    array.resize(600);

    array.set(301, false);

    assert(array.get(0) == true);
    array.set(0, false);
    assert(array.get(0) == false);

    for (int i = 1; i < 600; i++){
        if ((i < 300) && (i % 3 == 0)){
            assert(array.get(i) == true);
            continue;
        }  
        assert(array.get(i) == false);
    }

    array.resize(150);

    try {
        array.get(151);
        assert(false);
    } catch (std::exception& ex) {}
    try {
        array.set(151, false);
        assert(false);
    } catch (std::exception& ex) {}

    for (int i = 1; i < 150; i++){
        if (i % 3 == 0){
            assert(array.get(i) == true);
            continue;
        }
        assert(array.get(i) == false);
    }
}

void __do_all_tests(){
    __prime_sieve_test();
    __resize_test();

}