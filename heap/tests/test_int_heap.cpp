#include "gtest/gtest.h"
#include "heap.hpp"

/*Test module for Heap<int>*/
namespace {
  class MinHeapFixture : public ::testing::Test {
   protected:

    MinHeapFixture() {
    // You can do set-up work for each test here.
    }

    ~MinHeapFixture() override {
    // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
      my_min_heap->push(1);
      my_min_heap->push(2);
      my_min_heap->push(2);
      my_min_heap->push(3);
      my_min_heap->push(4);
      my_min_heap->push(5);
      my_min_heap->push(6);
      my_min_heap->push(8);
      my_min_heap->push(9);
    }
    void TearDown() override {
      delete my_min_heap;
    }

    Heap<int> *my_min_heap = new Heap<int>(0);
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
      my_max_heap->push(1);
      my_max_heap->push(2);
      my_max_heap->push(2);
      my_max_heap->push(3);
      my_max_heap->push(4);
      my_max_heap->push(5);
      my_max_heap->push(6);
      my_max_heap->push(8);
      my_max_heap->push(9);
    }

    void TearDown() override {
      delete my_max_heap;
    }

    Heap<int> *my_max_heap = new Heap<int>(1);
  };

  TEST(IntHeap, BlankHeap) {
    Heap<int> *my_max_heap = new Heap<int>(1);
    Heap<int> *my_min_heap = new Heap<int>(0);
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    EXPECT_EQ(0, my_min_heap->size());
    //extract max
    EXPECT_EQ(-1, my_max_heap->pop());
    EXPECT_EQ(-1, my_min_heap->pop());
    //view extreme
    EXPECT_EQ(-1, my_max_heap->front());
    EXPECT_EQ(-1, my_min_heap->front());
  }

  TEST(IntHeap, CreateHeap) {
    Heap<int> *my_max_heap = new Heap<int>(1);
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    //insert an element
    my_max_heap->push(5);
    EXPECT_EQ(1, my_max_heap->size());
    //insert two more
    my_max_heap->push(3);
    my_max_heap->push(4);
    EXPECT_EQ(3, my_max_heap->size());
  }

  TEST_F(MaxHeapFixture, ExtractMax) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //Extract max #1
    //my_max_heap->print_heap();
    EXPECT_EQ(9, my_max_heap->pop());
    EXPECT_EQ(8, my_max_heap->pop());
    EXPECT_EQ(6, my_max_heap->pop());
    EXPECT_EQ(5, my_max_heap->pop());
    EXPECT_EQ(4, my_max_heap->pop());
    EXPECT_EQ(3, my_max_heap->pop());
    EXPECT_EQ(2, my_max_heap->pop());
    EXPECT_EQ(2, my_max_heap->pop());
    EXPECT_EQ(1, my_max_heap->pop());
  }

  TEST_F(MaxHeapFixture, ViewMax) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //View max repeatedly
    //my_max_heap->print_heap();
    EXPECT_EQ(9, my_max_heap->front());
    EXPECT_EQ(9, my_max_heap->front());
    EXPECT_EQ(9, my_max_heap->front());
  }

  TEST_F(MaxHeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    //my_max_heap->print_heap();
    //Insert #1
    my_max_heap->push(4);
    std::cout << "Heap after inserting 4:" << std::endl;
    //my_max_heap->print_heap();
    my_max_heap->push(13);
    std::cout << "Heap after inserting 13:" << std::endl;
    //my_max_heap->print_heap();
    //Extract min#1
    EXPECT_EQ(13, my_max_heap->pop());
    EXPECT_EQ(9, my_max_heap->pop());
    EXPECT_EQ(8, my_max_heap->pop());
    EXPECT_EQ(6, my_max_heap->pop());
    EXPECT_EQ(5, my_max_heap->pop());
    EXPECT_EQ(4, my_max_heap->pop());
    EXPECT_EQ(4, my_max_heap->pop());
    EXPECT_EQ(3, my_max_heap->pop());
    EXPECT_EQ(2, my_max_heap->pop());
    EXPECT_EQ(2, my_max_heap->pop());
    EXPECT_EQ(1, my_max_heap->pop());
  }

  TEST_F(MinHeapFixture, ExtractMin) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //Extract min #1
    //my_min_heap->print_heap();
    EXPECT_EQ(1, my_min_heap->pop());
    EXPECT_EQ(2, my_min_heap->pop());
    EXPECT_EQ(2, my_min_heap->pop());
    EXPECT_EQ(3, my_min_heap->pop());
    EXPECT_EQ(4, my_min_heap->pop());
    EXPECT_EQ(5, my_min_heap->pop());
    EXPECT_EQ(6, my_min_heap->pop());
    EXPECT_EQ(8, my_min_heap->pop());
    EXPECT_EQ(9, my_min_heap->pop());
  }

  TEST_F(MinHeapFixture, ViewMin) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //View min repeatedly
    //my_min_heap->print_heap();
    EXPECT_EQ(1, my_min_heap->front());
    EXPECT_EQ(1, my_min_heap->front());
    EXPECT_EQ(1, my_min_heap->front());
  }

  TEST_F(MinHeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    //my_min_heap->print_heap();
    //Insert #1
    my_min_heap->push(4);
    std::cout << "Heap after inserting 4:" << std::endl;
    //my_min_heap->print_heap();
    my_min_heap->push(13);
    std::cout << "Heap after inserting 13:" << std::endl;
    //my_min_heap->print_heap();
    //Extract min#1
    EXPECT_EQ(1, my_min_heap->pop());
    EXPECT_EQ(2, my_min_heap->pop());
    EXPECT_EQ(2, my_min_heap->pop());
    EXPECT_EQ(3, my_min_heap->pop());
    EXPECT_EQ(4, my_min_heap->pop());
    EXPECT_EQ(4, my_min_heap->pop());
    EXPECT_EQ(5, my_min_heap->pop());
    EXPECT_EQ(6, my_min_heap->pop());
    EXPECT_EQ(8, my_min_heap->pop());
    EXPECT_EQ(9, my_min_heap->pop());
    EXPECT_EQ(13, my_min_heap->pop());
  }
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
Compile:
g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread tests/test_int_heap.cpp src/heap.cpp googletest-release-1.8.0/libgtest.a -o tests/test_int_heap

*/
