#include "gtest/gtest.h"
#include "heap.hpp"

/*Test module for Heap<double>*/
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
      my_min_heap->insert(1.323);
      my_min_heap->insert(2.2234);
      my_min_heap->insert(2.5231);
      my_min_heap->insert(3.42344);
      my_min_heap->insert(4.643);
      my_min_heap->insert(5.3342);
      my_min_heap->insert(6.443);
      my_min_heap->insert(8.723);
      my_min_heap->insert(9.1233);
    }
    void TearDown() override {
      delete my_min_heap;
    }

    Heap<double> *my_min_heap = new Heap<double>(0);
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
      my_max_heap->insert(1.323);
      my_max_heap->insert(2.2234);
      my_max_heap->insert(2.5231);
      my_max_heap->insert(3.42344);
      my_max_heap->insert(4.643);
      my_max_heap->insert(5.3342);
      my_max_heap->insert(6.443);
      my_max_heap->insert(8.723);
      my_max_heap->insert(9.1233);
    }

    void TearDown() override {
      delete my_max_heap;
    }

    Heap<double> *my_max_heap = new Heap<double>(1);
  };

  TEST(IntHeap, BlankHeap) {
    Heap<double> *my_max_heap = new Heap<double>(1);
    Heap<double> *my_min_heap = new Heap<double>(0);
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    EXPECT_EQ(0, my_min_heap->size());
    //extract extreme
    EXPECT_EQ(-1.0, my_max_heap->extract_extreme());
    EXPECT_EQ(-1.0, my_min_heap->extract_extreme());
    //view extreme
    EXPECT_EQ(-1.0, my_max_heap->view_extreme());
    EXPECT_EQ(-1.0, my_min_heap->view_extreme());
  }

  TEST(IntHeap, CreateHeap) {
    Heap<double> *my_max_heap = new Heap<double>(1);
    //check size
    EXPECT_EQ(0, my_max_heap->size());
    //insert an element
    my_max_heap->insert(5);
    EXPECT_EQ(1, my_max_heap->size());
    //insert two more
    my_max_heap->insert(3);
    my_max_heap->insert(4);
    EXPECT_EQ(3, my_max_heap->size());
  }

  TEST_F(MaxHeapFixture, ExtractMax) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //Extract max #1
    //my_max_heap->print_heap();
    EXPECT_EQ(9.1233, my_max_heap->extract_extreme());
    EXPECT_EQ(8.723, my_max_heap->extract_extreme());
    EXPECT_EQ(6.443, my_max_heap->extract_extreme());
    EXPECT_EQ(5.3342, my_max_heap->extract_extreme());
    EXPECT_EQ(4.643, my_max_heap->extract_extreme());
    EXPECT_EQ(3.42344, my_max_heap->extract_extreme());
    EXPECT_EQ(2.5231, my_max_heap->extract_extreme());
    EXPECT_EQ(2.2234, my_max_heap->extract_extreme());
    EXPECT_EQ(1.323, my_max_heap->extract_extreme());
  }

  TEST_F(MaxHeapFixture, ViewMax) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_max_heap->size()); //check size
    //View max repeatedly
    //my_max_heap->print_heap();
    EXPECT_EQ(9.1233, my_max_heap->view_extreme());
    EXPECT_EQ(9.1233, my_max_heap->view_extreme());
    EXPECT_EQ(9.1233, my_max_heap->view_extreme());
  }

  TEST_F(MaxHeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    //my_max_heap->print_heap();
    //Insert #1
    my_max_heap->insert(4.01);
    std::cout << "Heap after inserting 4:" << std::endl;
    //my_max_heap->print_heap();
    my_max_heap->insert(13.999);
    std::cout << "Heap after inserting 13:" << std::endl;
    //my_max_heap->print_heap();
    //Extract min#1
    EXPECT_EQ(13.999, my_max_heap->extract_extreme());
    EXPECT_EQ(9.1233, my_max_heap->extract_extreme());
    EXPECT_EQ(8.723, my_max_heap->extract_extreme());
    EXPECT_EQ(6.443, my_max_heap->extract_extreme());
    EXPECT_EQ(5.3342, my_max_heap->extract_extreme());
    EXPECT_EQ(4.643, my_max_heap->extract_extreme());
    EXPECT_EQ(4.01, my_max_heap->extract_extreme());
    EXPECT_EQ(3.42344, my_max_heap->extract_extreme());
    EXPECT_EQ(2.5231, my_max_heap->extract_extreme());
    EXPECT_EQ(2.2234, my_max_heap->extract_extreme());
    EXPECT_EQ(1.323, my_max_heap->extract_extreme());
  }

  TEST_F(MinHeapFixture, ExtractMin) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //Extract min #1
    //my_min_heap->print_heap();
    EXPECT_EQ(1.323, my_min_heap->extract_extreme());
    EXPECT_EQ(2.2234, my_min_heap->extract_extreme());
    EXPECT_EQ(2.5231, my_min_heap->extract_extreme());
    EXPECT_EQ(3.42344, my_min_heap->extract_extreme());
    EXPECT_EQ(4.643, my_min_heap->extract_extreme());
    EXPECT_EQ(5.3342, my_min_heap->extract_extreme());
    EXPECT_EQ(6.443, my_min_heap->extract_extreme());
    EXPECT_EQ(8.723, my_min_heap->extract_extreme());
    EXPECT_EQ(9.1233, my_min_heap->extract_extreme());
  }

  TEST_F(MinHeapFixture, ViewMin) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    EXPECT_EQ(9, my_min_heap->size()); //check size
    //View min repeatedly
    //my_min_heap->print_heap();
    EXPECT_EQ(1.323, my_min_heap->view_extreme());
    EXPECT_EQ(1.323, my_min_heap->view_extreme());
    EXPECT_EQ(1.323, my_min_heap->view_extreme());
  }

  TEST_F(MinHeapFixture, Insert) {
    /*Make sure that this fixture has the same name as the setup class declared above*/
    std::cout << "Heap before inserting:" << std::endl;
    //my_min_heap->print_heap();
    //Insert #1
    my_min_heap->insert(4.01);
    my_min_heap->insert(13.099);
    //Extract min#1
    EXPECT_EQ(1.323, my_min_heap->extract_extreme());
    EXPECT_EQ(2.2234, my_min_heap->extract_extreme());
    EXPECT_EQ(2.5231, my_min_heap->extract_extreme());
    EXPECT_EQ(3.42344, my_min_heap->extract_extreme());
    EXPECT_EQ(4.01, my_min_heap->extract_extreme());
    EXPECT_EQ(4.643, my_min_heap->extract_extreme());
    EXPECT_EQ(5.3342, my_min_heap->extract_extreme());
    EXPECT_EQ(6.443, my_min_heap->extract_extreme());
    EXPECT_EQ(8.723, my_min_heap->extract_extreme());
    EXPECT_EQ(9.1233, my_min_heap->extract_extreme());
    EXPECT_EQ(13.099, my_min_heap->extract_extreme());
  }
}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
Compile:
g++ -Igoogletest-release-1.8.0/googletest/include -Isrc -pthread tests/test_double_heap.cpp src/heap.cpp googletest-release-1.8.0/libgtest.a -o tests/test_double_heap

*/
