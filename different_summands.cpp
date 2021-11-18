#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  if(n<3){
    summands.push_back(n);
    return summands;
  }
  int x =n;
  summands.push_back(1);
  x --;
  for(int i = 1; x>0; i++){
    summands.push_back(i+1);

    if(x - summands[i]<=summands[i]){
      summands[i]+= x-summands[i];

    }
    x-= summands[i];
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
