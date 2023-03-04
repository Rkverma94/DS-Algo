#include<iostream>
using namespace std;

int main() {
  uint32_t *gpioa_moder_ptr = reinterpret_cast<uint32_t*>(0x4800'0000);
  cout<<*gpioa_moder_ptr;
  return 0;
}