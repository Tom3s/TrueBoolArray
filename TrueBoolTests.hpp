#include "TrueBool.h"

#include <cassert>
#include <iostream>
#include <chrono>

void __prime_sieve_test(){
    int control[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021};

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

    int index = 0;
    for (int i = 0; i < 1024; i++){
        if (array.get(i)) {
            assert(control[index] == i);
            index++;
        }
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