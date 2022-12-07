# True Bool Array
An array structure to store `bool` data with only _1 bit_ per element (this is _8 times lower_ than a normal `bool` array).

## Usage
To use this data structure, download the repository and include the header file

    #include "TrueBool.h"


## Members

### Jump to:
- [TrueBoolArray()](#constructor)
- [.size(), .resize()](#size-resize)
- [.get(), .set()](#getter-setter)
- [~TrueBoolArray()](#destructor)
- [Test Results](#test-results)


> ### Constructor
> - **TrueBoolArray(_size_)**: create a new array
> - **TrueBoolArray(_size, initial_value_)**: create a new array filled with initial values
> ```cpp
> // Create an array without initial value
> TrueBoolArray bool_array1(16);
> // bool_array1: [0000 0000 0000 0000]
> 
> // Create arrays with initial values
> TrueBoolArray bool_array_true(8, true);
> // bool_array_true: [1111 1111]
>
> TrueBoolArray bool_array_false(12, false);
> // bool_array_false: [0000 0000 0000]
> ```

> ### Size, resize
> - **get_size()** -> unsigned int64: returns the _current capacity_ of the array 
> ```cpp
> TrueBoolArray array1(16, true);
> std::cout << "Size of 'array1': " << array.size() << std::endl;
> // this will print 16
>
> TrueBoolArray array2(32, false);
> std::cout << "Size of 'array2': " << array.size() << std::endl;
> // this will print 32
> ...
> ```
>

> - **resize(_new_size_)**: resizes the array to _new_size_
>   - if _new_size_ is larger than the old size, the new elements will default to false (0)
>   - if _new_size_ s lower than the old size, the elements will be cut off
> ```cpp
> ...
> // current state of array1: [1111 1111 1111 1111]
> array1.resize(20);
> // after resizing: [1111 1111 1111 1111 0000] -> note the extra zeros at the end
>
> std::cout << "Resized 'array1': " << array.size() << std::endl;
>
> // suppose we have array3: [1101 0010 0110 1101 1010 0111] -> size: 24
> std::cout << "Old size of 'array3': " << array.size() << std::endl;
>
> array3.resize(10);
> // after resizing to a lower number: [1101 0010 01] -> only the first 10 numbers remained
>
> std::cout << "New size of 'array3': " << array.size() << std::endl;
> ```
> Output:
> ```
> Size of 'array1': 16
> Size of 'array2': 32
> Resized 'array1': 20
> Old size of 'array3': 24
> New size of 'array3': 10
> ```

> ### Getter, setter
> - **TrueBoolArray::set(_index, new_value_)**: set the value of element at _index_
> ```cpp
> TrueBoolArray array(16)
> // array: [0000 0000 0000 0000]
>
> array.set(0, true);
> // array: [1000 0000 0000 0000]
> //         ^ - first element set to true
>
> for (int i = 1; i < array.size(); i += 2){
>   array.set(i, true); // Setting elements at odd index to true
> }
> // array: [1101 0101 0101 0101]
> //          ^ ^  ^ ^  ^ ^  ^ ^ - elements at indecis 1, 3,.. 13, 15 set to true
>
> array.set(0, false);
> // array: [0101 0101 0101 0101]
> //         ^ - first element set back to false
>
> for (int i = 11; i < array.size(); i++){
>   array.set(i, false);
> }
> // array: [0101 0101 0100 0000]
> //                     ^^ ^^^^ - all elements after index 11 set to false
> ...
> ```
> 
> - **TrueBoolArray::get(_index_)** -> bool: get the value of element at _index_
> ```cpp
> ...
> std::cout << "Elements of the array: " << std::flush;
> for (int i = 0; i < array.size(); i++) {
>   std::cout << array.get(i) << " " << std::flush;
> }
> std::cout << std::endl;
> ```
> Output:
> ```
> Elements of the array: 0 1 0 1 0 1 0 1 0 1 0 0 0 0 0 0
> ```

> ### Destructor
> - **~TrueBoolArray()**: this simply frees up the allocated memory (no leaks are possible)
>   - this was tested using _Valgrind_

> ### Test results
> - *Initialize*, *set* and *get* 5 million elements: 
>   - **Normal Array** (```new bool[5000000]```) - 114ms
>   - **Vector** (``std::vector<bool> array(5000000)``) - 2328ms
>   - **TrueBoolArray** - 290ms
> - Memory usage (tested with _Valgrind_):
>   - **Normal Array**: 5 million bytes -> 5 MB
>   - **TrueBoolArray**: 625000 bytes -> 625 KB
>       - Memory usage is _**8** times lower_
