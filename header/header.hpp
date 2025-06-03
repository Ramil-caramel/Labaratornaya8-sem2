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

    // считаем середину вручную (двигаем итератор на size / 2 шагов)
    It mid = first;
    for (int i = 0; i < size / 2; ++i) {
        ++mid;
    }

    // копируем левую и правую части в обычные векторы
    std::vector<int> left;
    std::vector<int> right;

    // Копируем в left
    for (It it = first; it != mid; ++it) {
        left.push_back(*it);
    }

    // Копируем в right
    for (It it = mid; it != last; ++it) {
        right.push_back(*it);
    }

    // Рекурсивная сортировка
    std::vector<int> sorted_left;
    std::vector<int> sorted_right;

    merge_sort(left.begin(), left.end(), std::back_inserter(sorted_left), cmp);
    merge_sort(right.begin(), right.end(), std::back_inserter(sorted_right), cmp);

    // Слияние
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
                // Найти, куда вставить элемент right
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

template<class It, class Compare=std::less<>>
void heap_sort(It first, It last, Compare cmp=Compare{}); // 4

template <class It, class Compare=std::less<>>
void quick_sort(It first, It last, Compare cmp=Compare{}); // 5
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