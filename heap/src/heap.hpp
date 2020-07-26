#ifndef HEAP
#define HEAP

//#define HEAP_EXCEPTION_BLANK string("Element requested during blank heap condition.")

#include <iostream>
#include <algorithm>
#include <assert.h>

template <class T>
class Heap {
/*  This is a generic implementation of a heap data structure.
    Upon class instantiation, the user should set the mode in which
    the heap will be created (Minimum/Maximum).
    This is done via the constructor
    The user should also set the data structure of the keys in the heap.

    example test use:

    (1) Initializing an integer min-heap :
        Heap<int> my_min_heap = new Heap<int>(0);
    (2) Initializing an integer max-heap :
        Heap<int> my_max_heap = new Heap<int>(1);
*/
  private:
    T* data_;
    T* data_end_;
    int size_;
    int mode_; //max or min heap; by default (0) this is a min_heap

    int parent(const int&);
    int left_child(const int&);
    int right_child(const int&);
    void sift_down_max(const int&);
    void sift_up_max(int);
    void sift_down_min(const int&);
    void sift_up_min(int);
    void sift_down(const int&);
    void sift_up(const int&);

  public:
    Heap(const int&);
    ~Heap();

    void push(const T&);
    T pop();
    T front();
    int mode();
    int size();
};

template <typename T>
int Heap<T>::parent(const int& i){
  return (int)(i-1)/2;
}

template <typename T>
int Heap<T>::left_child(const int& i){
  return 2*i+1;
}

template <typename T>
int Heap<T>::right_child(const int& i){
  return 2*i+2;
}

template <typename T>
void Heap<T>::sift_down_max(const int& i){
  int max_index = i;
  int l = left_child(i);
  if (l<size_ && data_[l] > data_[max_index])
    max_index = l;
  int r = right_child(i);
  if (r<size_ && data_[r] > data_[max_index])
    max_index = r;
  if (i != max_index){
    std::swap(data_[i], data_[max_index]);
    //sift down
    sift_down(max_index);
  }
}

template <typename T>
void Heap<T>::sift_up_max(int i){
  while(i>0 && data_[i] > data_[parent(i)]){
    std::swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

template <typename T>
void Heap<T>::sift_down_min(const int& i){
  int min_index = i;
  int l = left_child(i);
  if (l<size_ && data_[l] < data_[min_index])
    min_index = l;
  int r = right_child(i);
  if (r<size_ && data_[r] < data_[min_index])
    min_index = r;
  if (i != min_index){
    std::swap(data_[i], data_[min_index]);
    //sift down
    sift_down(min_index);
  }
}

template <typename T>
void Heap<T>::sift_up_min(int i){
  while(i>0 && data_[i] < data_[parent(i)]){
    std::swap(data_[parent(i)], data_[i]);
    i = parent(i);
  }
}

template <typename T>
void Heap<T>::sift_down(const int& i){
  if(mode_ == 1){
    //max_heap
    sift_down_max(i);
  }else{
    //min heap
    sift_down_min(i);
  }
}

template <typename T>
void Heap<T>::sift_up(const int& i){
  if(mode_ == 1){
    //max_heap
    sift_up_max(i);
  }else{
    //min heap
    sift_up_min(i);
  }
}

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

#endif
