#ifndef HEAP
#define HEAP

#include <iostream>
#include <algorithm>
#include <assert.h>

// This is a template class, the user will provide the data type for T
template <class T>
class Heap {
/*  This is a generic heap implementation
*/
  private:
    T* data_;
    T* data_end_;
    int size_;
    int mode_; //max or min heap; by default (0) this is a min_heap

    int parent(int i){
      return (int)(i-1)/2;
    }

    int left_child(int i){
      return 2*i+1;
    }

    int right_child(int i){
      return 2*i+2;
    }

    void sift_down_max(int i){
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

    void sift_up_max(int i){
      while(i>0 && data_[i] > data_[parent(i)]){
        std::swap(data_[parent(i)], data_[i]);
        i = parent(i);
      }
    }

    void sift_down_min(int i){
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

    void sift_up_min(int i){
      while(i>0 && data_[i] < data_[parent(i)]){
        std::swap(data_[parent(i)], data_[i]);
        i = parent(i);
      }
    }

    void sift_down(int i){
      if(mode_ == 1){
        //max_heap
        sift_down_max(i);
      }else{
        //min heap
        sift_down_min(i);
      }
    }

    void sift_up(int i){
      if(mode_ == 1){
        //max_heap
        sift_up_max(i);
      }else{
        //min heap
        sift_up_min(i);
      }
    }

  public:
    Heap(int set_mode){
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

    ~Heap(){
      delete[] data_;
      data_ = nullptr;
      data_end_ = nullptr;
      size_ = 0;
    }

    void insert(const T& key){
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

    T extract_extreme(void){
      if(size_ == 0){
        std::cout << "ERROR: Blank Heap" << std::endl;
        return -1;
      }
      T result = data_[0];  //the max value is the head of the tree
      data_[0] = data_[size_-1]; //replace head with the latest leaf
      //the next two lines are essentially pop_back
      size_--;
      data_end_--;
      sift_down(0); //put the new head to its right position to maintain heap property
      return result;
    }

    T view_extreme(void){
      if(size_ == 0){
        std::cout << "ERROR: Blank Heap" << std::endl;
        return -1;
      }
      return data_[0];
    }

    int mode(void){
      return mode_;
    }

    int size(){
      return size_;
    }

};

#endif
