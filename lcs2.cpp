#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;
using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
   vector<vector<int>> vect( a.size() , vector<int> (b.size(), 0));
  // for(int j = 0; j<b.size() ; j++){
  //   if(a[0] == b[j]){
  //     vect[0][j]= 1;
  //   }
  //   else{
  //     vect[0][j]=0;
  //   }
  // }
  if(a[0]== b[0]){
    vect[0][0] = 1;
  }else{
    vect[0][0] = 0;
  }
  for(int j = 1 ; j<b.size();j++){
    if(a[0]==b[j]){
      vect[0][j] = 1;
    }
    else{
       vect[0][j] = vect[0][j-1];
    }
  }
  for(int i = 1 ; i<a.size();i++){
    if(a[i]==b[0]){
      vect[i][0] = 1;
    }
    else{
       vect[i][0] = vect[i-1][0];
    }
  }

  for(int i = 1; i < a.size(); i++ ){
    for(int j = 1; j <b.size(); j++){
        
        if(a[i] == b[j] ){
        vect[i][j]= vect[i-1][j-1] +1 ;
        }
        else{
          vect[i][j]= max(vect[i-1][j],  vect[i][j-1]);
        }
      
      
      
    }
  }
  return vect[a.size()-1][b.size()-1];
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
