#pragma once
#include <functional>

// 1
template <class It, class Out, class Compare = std::less<>>
Out merge(It first1, It last1, It first2, It last2, Out out, Compare cmp = Compare{}) {
    while (first1 != last1 && first2 != last2) {
        if (cmp(*first2, *first1)) {
            *out++ = *first2++;
        } else {
            *out++ = *first1++;
        }
    }

    while (first1 != last1) {
        *out++ = *first1++;
    }

    while (first2 != last2) {
        *out++ = *first2++;
    }

    return out;
}


template <class It, class Out, class Compare=std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp=Compare{}); // 2

template <class It, class Compare=std::less<>>
void inplace_merge_sort(It first, It last, Compare cmp=Compare{}); // 3

template<class It, class Compare=std::less<>>
void heap_sort(It first, It last, Compare cmp=Compare{}); // 4

template <class It, class Compare=std::less<>>
void quick_sort(It first, It last, Compare cmp=Compare{}); // 5

template <class It, class Compare=std::less<>>
void insertion_sort(It first, It last, Compare cmp=Compare{}); // 6