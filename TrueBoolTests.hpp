#include "TrueBool.h"

#include <cassert>
#include <iostream>
#include <chrono>

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
        if (array.get(i)) std::cout << i <<  "  " << std::flush;
    }
    std::cout << std::endl;
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

using namespace std::chrono;
#define clock high_resolution_clock::now


void __capacity_test(){
    TrueBoolArray array = TrueBoolArray(1000000000);

    auto start_time = clock();
    for (int i = 0; i < 1000000000; i += 2){
        array.set(i, true);
    }
    for (int i = 0; i < 1000000000; i += 2){
        assert(array.get(i) == true);
        assert(array.get(i + 1) == false);
    }
    auto stop_time = clock();
    int ms = duration_cast<milliseconds>(stop_time - start_time).count();

    std::cout << "Initialize, set and get 1b elements: " << ms << "ms" << std::endl;
}

void __do_all_tests(){
    __prime_sieve_test();
    __resize_test();
    __capacity_test();
}