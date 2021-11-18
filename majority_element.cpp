#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  //vector<int> b(right +1);
  sort(a.begin(), a.end());
  int count = 1;
  int size = a.size();
  for (int i=1; i < size; i++){
    if(a[i]==a[i-1]){
      count++;
    }
    else{
      count = 1;
    }
    if (count > size/2 ){
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size())  << '\n';
}
