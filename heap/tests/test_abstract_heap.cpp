#include "gtest/gtest.h"
#include "heap.hpp"

/*Test module for Heap with abstract data structure*/
namespace {
  struct Abstract {
    int idx;
    double key;
    bool operator==(const Abstract& other) const { return key == other.key;}
    bool operator!=(const Abstract& other) const { return key != other.key;}
    bool operator>(const Abstract& other) const { return key > other.key;}
    bool operator>=(const Abstract& other) const { return key >= other.key;}
    bool operator<(const Abstract& other) const { return key < other.key;}
    bool operator<=(const Abstract& other) const { return key <= other.key;}
  };
  class MaxHeapFixture : public ::testing::Test {
   protected:

    MaxHeapFixture() {
    // You can do set-up work for each test here.
    }

    ~MaxHeapFixture() override {
    // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
      my_max_heap->push({1, 1.323});
      my_max_heap->push({2, 2.2234});
      my_max_heap->push({3, 2.5231});
      my_max_heap->push({4, 3.42344});
      my_max_heap->push({5, 4.643});
      my_max_heap->push({6, 5.3342});
      my_max_heap->push({7, 6.443});
      my_max_heap->push({8, 8.723});
      my_max_heap->push({9, 9.1233});
    }

    void TearDown() override {
      delete my_max_heap;
    }

    Heap<Abstract> *my_max_heap = new Heap<Abstract>(1);
  };
  class MinHeapFixture : public ::testing::Test {
   protected:

    MinHeapFixture() {
    // You can do set-up work for each test here.
    }

    ~MinHeapFixture() override {
    // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
      my_min_heap->push({1, 1.323});
      my_min_heap->push({2, 2.2234});
      my_min_heap->push({3, 2.5231});
      my_min_heap->push({4, 3.42344});
      my_min_heap->push({5, 4.643});
      my_min_heap->push({6, 5.3342});
      my_min_heap->push({7, 6.443});
      my_min_heap->push({8, 8.723});
      my_min_heap->push({9, 9.1233});
    }

    void TearDown() override {
      delete my_min_heap;
    }

    Heap<Abstract> *my_min_heap = new Heap<Abstract>(0);
  };

  /*TESTS*/

  TEST(IntHeap, BlankHeap) {
    Heap<Abstract> *my_max_heap = new Heap<Abstract>(1);
    Heap<Abstract> *my_min_heap = new Heap<Abstract>(0);
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    EXPECT_EQ(0, my_min_heap->size());
    //extract min/max
    EXPECT_ANY_THROW(my_max_heap->pop());
    EXPECT_ANY_THROW(my_min_heap->pop());
    //view min/max
    EXPECT_ANY_THROW(my_max_heap->front());
    EXPECT_ANY_THROW(my_min_heap->front());
  }

  TEST(IntHeap, CreateHeap) {
    Heap<Abstract> *my_max_heap = new Heap<Abstract>(1);
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    //insert an element
    my_max_heap->push({1, 5.3});
    EXPECT_EQ(1, my_max_heap->size());
    //insert two more
    my_max_heap->push({2, 12.3});
    my_max_heap->push({4, -35.3});
    EXPECT_EQ(3, my_max_heap->size());
  }

  TEST_F(MaxHeapFixture, ExtractMax) {
    Abstract a;
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //Extract max #1
    //my_max_heap->print_heap();
    a = {9, 9.1233};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {8, 8.723};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {7, 6.443};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {6, 5.3342};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {5, 4.643};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {4, 3.42344};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {3, 2.5231};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {2, 2.2234};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {1, 1.323};
    EXPECT_EQ(a, my_max_heap->pop());
  }

  TEST_F(MaxHeapFixture, ViewMax) {
    Abstract a;
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //View max repeatedly
    //my_max_heap->print_heap();
    a = {9, 9.1233};
    EXPECT_EQ(a, my_max_heap->front());
    a = {9, 9.1233};
    EXPECT_EQ(a, my_max_heap->front());
    a = {9, 9.1233};
    EXPECT_EQ(a, my_max_heap->front());
  }

  TEST_F(MaxHeapFixture, Insert) {
    Abstract a;
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    //my_max_heap->print_heap();
    //Insert #1
    my_max_heap->push({8, 4.01});
    std::cout << "Heap after inserting 4:" << std::endl;
    my_max_heap->push({13, 13.999});
    std::cout << "Heap after inserting 13:" << std::endl;
    //Extract max
    a = {13, 13.999};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {9, 9.1233};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {8, 8.723};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {7, 6.443};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {6, 5.3342};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {5, 4.643};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {8, 4.01};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {4, 3.42344};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {3, 2.5231};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {2, 2.2234};
    EXPECT_EQ(a, my_max_heap->pop());
    a = {1, 1.323};
    EXPECT_EQ(a, my_max_heap->pop());
  }

  TEST_F(MinHeapFixture, ExtractMin) {
    Abstract a;
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //Extract min
    a={1, 1.323};
    EXPECT_EQ(a, my_min_heap->pop());
    a={2, 2.2234};
    EXPECT_EQ(a, my_min_heap->pop());
    a={3, 2.5231};
    EXPECT_EQ(a, my_min_heap->pop());
    a={4, 3.42344};
    EXPECT_EQ(a, my_min_heap->pop());
    a={5, 4.643};
    EXPECT_EQ(a, my_min_heap->pop());
    a={6, 5.3342};
    EXPECT_EQ(a, my_min_heap->pop());
    a={7, 6.443};
    EXPECT_EQ(a, my_min_heap->pop());
    a={8, 8.723};
    EXPECT_EQ(a, my_min_heap->pop());
    a={9, 9.1233};
    EXPECT_EQ(a, my_min_heap->pop());
  }

  TEST_F(MinHeapFixture, ViewMin) {
    Abstract a;
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //View min repeatedly
    //my_min_heap->print_heap();
    a={1, 1.323};
    EXPECT_EQ(a, my_min_heap->front());
    a={1, 1.323};
    EXPECT_EQ(a, my_min_heap->front());
    a={1, 1.323};
    EXPECT_EQ(a, my_min_heap->front());
  }

  TEST_F(MinHeapFixture, Insert) {
    Abstract a;
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    //my_min_heap->print_heap();
    //Insert #1
    my_min_heap->push({8, 4.01});
    my_min_heap->push({13, 13.099});
    //Extract min#1
    a={1, 1.323};
    EXPECT_EQ(a, my_min_heap->pop());
    a={2, 2.2234};
    EXPECT_EQ(a, my_min_heap->pop());
    a={3, 2.5231};
    EXPECT_EQ(a, my_min_heap->pop());
    a={4, 3.42344};
    EXPECT_EQ(a, my_min_heap->pop());
    a={8, 4.01};
    EXPECT_EQ(a, my_min_heap->pop());
    a={5, 4.643};
    EXPECT_EQ(a, my_min_heap->pop());
    a={6, 5.3342};
    EXPECT_EQ(a, my_min_heap->pop());
    a={7, 6.443};
    EXPECT_EQ(a, my_min_heap->pop());
    a={8, 8.723};
    EXPECT_EQ(a, my_min_heap->pop());
    a={9, 9.1233};
    EXPECT_EQ(a, my_min_heap->pop());
    a={13, 13.099};
    EXPECT_EQ(a, my_min_heap->pop());
  }

}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
Compile:
g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread tests/test_double_heap.cpp src/heap.cpp googletest-release-1.8.0/libgtest.a -o tests/test_double_heap

*/
