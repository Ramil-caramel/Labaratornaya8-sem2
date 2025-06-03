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

 // 2
template <class It, class Out, class Compare=std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp = Compare{}) {
    int size = std::distance(first, last);
    if (size <= 1) {
        while (first != last) {
            *out++ = *first++;
        }
        return out;
    }

    It mid = first;
    for (int i = 0; i < size / 2; ++i) {
        ++mid;
    }

    std::vector<int> left;
    std::vector<int> right;

    for (It it = first; it != mid; ++it) {
        left.push_back(*it);
    }

    for (It it = mid; it != last; ++it) {
        right.push_back(*it);
    }

    std::vector<int> sorted_left;
    std::vector<int> sorted_right;

    merge_sort(left.begin(), left.end(), std::back_inserter(sorted_left), cmp);
    merge_sort(right.begin(), right.end(), std::back_inserter(sorted_right), cmp);

    return merge(sorted_left.begin(), sorted_left.end(),
                 sorted_right.begin(), sorted_right.end(), out, cmp);
}
// 3
template <class It, class Compare=std::less<>>
void inplace_merge_sort(It first, It last, Compare cmp=Compare{}){
    auto inplace_merge = [&](It begin, It mid, It end) {
        It left = begin;
        It right = mid;

        while (left < right && right < end) {
            if (!cmp(*right, *left)) {
                ++left;
            } else {
                
                auto value = *right;
                It it = right;
                while (it != left) {
                    *it = *(it - 1);
                    --it;
                }
                *left = value;

                ++left;
                ++right;
            }
        }
    };

    auto sort = [&](auto& self, It start, It end) -> void {
        if (end - start <= 1) return;

        It mid = start + (end - start) / 2;
        self(self, start, mid);
        self(self, mid, end);
        inplace_merge(start, mid, end);
    };

    sort(sort, first, last);
}
//4
template <class It, class Compare = std::less<>>
void heap_sort(It first, It last, Compare cmp = Compare{}) {
    int n = last - first;

    auto heapify = [&](int i, int heap_size, auto& heapify_ref) -> void {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap_size && cmp(first[largest], first[left])) {
            largest = left;
        }
        if (right < heap_size && cmp(first[largest], first[right])) {
            largest = right;
        }

        if (largest != i) {
            auto temp = first[i];
            first[i] = first[largest];
            first[largest] = temp;

            heapify_ref(largest, heap_size, heapify_ref);
        }
    };

    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(i, n, heapify);
    }

    for (int i = n - 1; i > 0; --i) {
        auto temp = first[0];
        first[0] = first[i];
        first[i] = temp;

        heapify(0, i, heapify);
    }
}
//5
template <class It, class Compare = std::less<>>
void quick_sort(It first, It last, Compare cmp = Compare{}) {
    if (last - first <= 1) return;

    It pivot_it = last - 1;
    auto pivot = *pivot_it;

    It i = first;
    for (It j = first; j != pivot_it; ++j) {
        if (cmp(*j, pivot)) {
            auto temp = *i;
            *i = *j;
            *j = temp;
            ++i;
        }
    }

    auto temp = *i;
    *i = *pivot_it;
    *pivot_it = temp;

    quick_sort(first, i, cmp);   
    quick_sort(i + 1, last, cmp); 
}
// 6
template <class It, class Compare=std::less<>>
void insertion_sort(It first, It last, Compare cmp=Compare{}){
    for (It i = first; i != last; ++i) {
        It j = i;
        while (j != first && cmp(*j, *(j - 1))) {
            std::iter_swap(j, j - 1);
            --j;
        }
    }
}