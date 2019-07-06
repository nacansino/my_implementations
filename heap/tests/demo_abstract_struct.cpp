#include <iostream>
#include <cassert>

/*This is a demonstration of an abstract data structure
  with assignment and comparison overload.*/

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

void print_mem(Abstract bar){
  std::cout << "idx: " << bar.idx << "| key: " <<  bar.key << std::endl;
}

int main(){


  Abstract bar = {1, 2.5};
  Abstract bar2= {1, 2.7};
  Abstract bar3= {2, 2.5};

  print_mem({1, 2.5});
  assert((bar>bar2) == false);
  assert((bar<bar2) == true);
  assert((bar>=bar2) == false);
  assert((bar<=bar2) == true);
  assert((bar==bar3) == true);
  assert((bar>=bar3) == true);
  assert((bar<=bar3) == true);
  assert((bar==bar2) == false);
  assert((bar!=bar3) == false);
  std::cout << "passed all tests" << std::endl;
}
