#include <iostream>
#include "header.hpp"
#include <vector>

int main(){

    std::vector<int> a, b;
    a = {1,3,5,7,9};
    b = {2,4,6,8};
    std::vector<int> c(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    
    for (int x : c) {
        std::cout << x << " " << std::endl;
    }

}