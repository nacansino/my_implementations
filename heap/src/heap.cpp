// heap.cpp
#include "heap.hpp"

template <typename T>
Heap<T>::Heap(const int& set_mode){
  size_ = 0;
  data_ = nullptr;
  data_end_ = nullptr;
  if(set_mode != 0){
    //max_heap
    mode_ = 1;
  }else{
    mode_ = 0;
  }
}

template <typename T>
Heap<T>::~Heap(void){
  delete[] data_;
  data_ = nullptr;
  data_end_ = nullptr;
  size_ = 0;
}

template <typename T>
void Heap<T>::push(const T& key){
  /*This function inserts the key into the heap.*/
  //Inserts the int v to the heap
  if(size_ == 0){
    //initialize object
    data_ = new T[1];
  }
  size_++;
  data_[size_-1] = key;
  data_end_++;
  sift_up(size_-1); //sift up the recently inserted elemenet
}

template <typename T>
T Heap<T>::pop(){
  /*This function extracts the first element of the heap.*/
  if(size_ == 0){
    throw "Element requested during blank heap condition.";
  }
  T result = data_[0];  //the max value is the head of the tree
  data_[0] = data_[size_-1]; //replace head with the latest leaf
  //the next two lines are essentially pop_back
  size_--;
  data_end_--;
  sift_down(0); //put the new head to its right position to maintain heap property
  return result;
}

template <typename T>
T Heap<T>::front(){
  /*This function displays the first element of the heap.*/
  if(size_ == 0){
    throw "Element requested during blank heap condition.";
  }
  return data_[0];
}

template <typename T>
int Heap<T>::mode(){
  /*This function displays the current mode of the heap (max/min).*/
  return mode_;
}

template <typename T>
int Heap<T>::size(){
  /*This function returns the size of the heap.*/
  return size_;
}