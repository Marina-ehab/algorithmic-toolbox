#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  //int current_weight = 0;
  // for (size_t i = 0; i < w.size(); ++i) {
  //   if (current_weight + w[i] <= W) {
  //     current_weight += w[i];
  //   }
  // }
  //vector<vector<int>> vect(w.size())(W);
  vector<vector<int>> vect( w.size() , vector<int> (W, 0));
  for(int j = 0; j<W ; j++){
    if(w[0]<= j+1){
      vect[0][j]= w[0];
    }
    else{
      vect[0][j]=0;
    }
  }

  for(int i = 1; i < w.size(); i++ ){
    for(int j = 0; j <W; j++){
      if(w[i]<= j+1){
      vect[i][j]= max(vect[i-1][j], w[i]+ vect[i-1][j-w[i]]);
      }
      else{
        vect[i][j]= vect[i-1][j];
      }
    }
  }
  return vect[w.size()-1][W-1];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
