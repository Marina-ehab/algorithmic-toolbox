#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int firstIndex = -1;
    int secondIndex = -1 ;

    /*for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }*/
    for(int i = 0;i<n;i++){
        if( firstIndex == -1  || numbers[firstIndex]< numbers[i] ){
            firstIndex = i;
        }
    }
     for(int i = 0;i<n;i++){
        if(i != firstIndex && (secondIndex == -1 || numbers[secondIndex]< numbers[i] )){
            secondIndex = i;
        }
    }
    max_product = numbers[firstIndex]*numbers[secondIndex];
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
