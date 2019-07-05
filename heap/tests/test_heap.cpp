#include "gtest/gtest.h"
#include "heap.hpp"

namespace {
  class HeapFixture : public ::testing::Test {
   protected:

    HeapFixture() {
    // You can do set-up work for each test here.
    }

    ~HeapFixture() override {
    // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
      my_heap->insert(1);
      my_heap->insert(2);
      my_heap->insert(2);
      my_heap->insert(3);
      my_heap->insert(4);
      my_heap->insert(5);
      my_heap->insert(6);
      my_heap->insert(8);
      my_heap->insert(9);
    }
    void TearDown() override {
      delete my_heap;
    }

    Heap *my_heap = new Heap;
  };

  TEST(Heap, BlankHeap) {
    //instantiate max_heap
    Heap *my_heap(1) = new Heap;
    //check size
    EXPECT_EQ(0, my_heap->size());
    //extract
    EXPECT_EQ(-1, my_heap->extract_extreme());
  }

  TEST(Heap, CreateHeap) {
    Heap *my_heap = new Heap;
    //check size
    EXPECT_EQ(0, my_heap->size());
    //insert an element
    my_heap->insert(5);
    EXPECT_EQ(1, my_heap->size());
    //insert two more
    my_heap->insert(3);
    my_heap->insert(4);
    EXPECT_EQ(3, my_heap->size());
  }

  TEST_F(HeapFixture, Extract) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_heap->size()); //check size
    //Extract  #1
    my_heap->print_heap();
    EXPECT_EQ(9, my_heap->extract_extreme());
    EXPECT_EQ(8, my_heap->extract_extreme());
    EXPECT_EQ(6, my_heap->extract_extreme());
    EXPECT_EQ(5, my_heap->extract_extreme());
    EXPECT_EQ(4, my_heap->extract_extreme());
    EXPECT_EQ(3, my_heap->extract_extreme());
    EXPECT_EQ(2, my_heap->extract_extreme());
    EXPECT_EQ(2, my_heap->extract_extreme());
    EXPECT_EQ(1, my_heap->extract_extreme());
  }

  TEST_F(HeapFixture, View) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_heap->size()); //check size
    //View  repeatedly
    my_heap->print_heap();
    EXPECT_EQ(9, my_heap->view_extreme());
    EXPECT_EQ(9, my_heap->view_extreme());
    EXPECT_EQ(9, my_heap->view_extreme());
  }

  TEST_F(HeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    my_heap->print_heap();
    //Insert #1
    my_heap->insert(4);
    std::cout << "Heap after inserting 4:" << std::endl;
    my_heap->print_heap();
    my_heap->insert(13);
    std::cout << "Heap after inserting 13:" << std::endl;
    my_heap->print_heap();
    //Extract min#1
    EXPECT_EQ(13, my_heap->extract_extreme());
    EXPECT_EQ(9, my_heap->extract_extreme());
    EXPECT_EQ(8, my_heap->extract_extreme());
    EXPECT_EQ(6, my_heap->extract_extreme());
    EXPECT_EQ(5, my_heap->extract_extreme());
    EXPECT_EQ(4, my_heap->extract_extreme());
    EXPECT_EQ(4, my_heap->extract_extreme());
    EXPECT_EQ(3, my_heap->extract_extreme());
    EXPECT_EQ(2, my_heap->extract_extreme());
    EXPECT_EQ(2, my_heap->extract_extreme());
    EXPECT_EQ(1, my_heap->extract_extreme());
  }

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
Compile:
g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread tests/test_heap.cpp src/heap.cpp googletest-release-1.8.0/libgtest.a -o tests/test_heap

*/
