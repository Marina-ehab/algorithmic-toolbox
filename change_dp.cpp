#include <iostream>
#include <cmath>

int get_change(int m) {
  //write your code here
  return ceil(m / 4.00);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
