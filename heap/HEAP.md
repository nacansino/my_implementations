# Generic Heap
This is a Heap data structure in C++ that supports abstract data types/user data types.

-  This is a part of the my_implementations repo: https://github.com/nacansino/my_implementations

## Basic Features:

### Heap(int mode)
- this is the constructor
- initializes a heap with a specified mode of operation
- set mode to 0 for a minimum heap, and any integer other than zero to initialize a maximum heap.
### front()
- views the max/min of the heap
### push()
- inserts an element in the heap
- heap automatically adjusts elements inside such that the heap property is satisfied.
### pop()
- return and remove the max/min of the heap

## Usage:

### Initializing an integer min heap
```cpp
Heap<int> *my_min_heap = new Heap<int>(0);
```
### Initializing an integer max heap
- note that you can set the argument to any non-zero integer
```cpp
Heap<int> *my_max_heap = new Heap<int>(1);
```
### push(), front(), and pop() an integer max heap
```cpp

#include <iostream>
#include "heap.hpp"

int main(){
  Heap<int> *my_max_heap = new Heap<int>(1);

  /*Add 6 elements*/
  my_max_heap->push(-5);
  my_max_heap->push(1);
  my_max_heap->push(2);
  my_max_heap->push(-8);
  my_max_heap->push(0);
  my_max_heap->push(3);

  /*At this point, the heap in ascending order: 
    {-8, -5, 0, 1, 2, 3}
  */

  /*print size*/
  std::cout << "Size of heap: " << my_max_heap->size() << std::endl;

  /*look at the maximum repeatedly. this should not remove element from the heap*/
  std::cout << my_max_heap->front() << " ";
  std::cout << my_max_heap->front() << " ";
  std::cout << my_max_heap->front() << std::endl;

  /*pop sequentially*/
  std::cout << my_max_heap->pop() << " ";
  std::cout << my_max_heap->pop() << " ";
  std::cout << my_max_heap->pop() << " ";
  std::cout << my_max_heap->pop() << " ";
  std::cout << my_max_heap->pop() << " ";
  std::cout << my_max_heap->pop() << std::endl;
}
```
- Output:
```
  Size of heap: 6
  3 3 3
  3 2 1 0 -5 -8
```
