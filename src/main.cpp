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
        std::cout << x << " ";
    }
    std::cout << std::endl;


    std::vector<int> unsorted = {9, 1, 3, 8, 2, 7};
    std::vector<int> sorted(unsorted.size());

    merge_sort(unsorted.begin(), unsorted.end(), sorted.begin());

    for (int x : sorted) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

}