#include <iostream>
long long gcd(int a, int b){
  if (b==0){
  return a;
  }
  return gcd(b, a%b);
}

long long lcm_naive(int a, int b) {
  /* for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l; */
      long long c = gcd(a,b);
      long long d = ((long long)a)* b;
      //std::cout<<d<<" "<< c <<" "<<d/c <<" ";

  return d/c;
}

int main() {
  int a, b;
  std::cin >> a >> b;
 /*  a=714552;
  b=374513; */
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
