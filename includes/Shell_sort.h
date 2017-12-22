//
// Created by gerdon on 15.12.17.
//

#ifndef SORT_SHELL_SORT_H
#define SORT_SHELL_SORT_H
#include <vector>
#include <math.h>

std::vector<int> sequence_A102549 = {1, 4, 10, 23, 57, 132, 301, 701, 1750}; // Optimal (best known) sequence of increments for shell sort algorithm.
using std::cout;
using std::endl;


std::vector<int> sequence_A108870 (size_t v_size){
    int n = 0;
    std::vector<int> a;
    while(ceil((9 * (pow((9.0 / 4), n)) - 4) / 5) < v_size){
        a.push_back(ceil((9 * (pow((9.0 / 4), n)) - 4) / 5));
        ++n;
     }
    return a;
}

//??
std::vector<int> Choose_sequence(size_t size){
    (size < 4000) ? sequence_A102549 : sequence_A108870(size);
}

template <typename T>
void Shell_sort(T* a, size_t p){
    std::vector<int> b = sequence_A108870(p);
    for(std::vector<int>::iterator it = b.begin(); it < b.end(); ++it) {
 //       cout << *it << " ";
    }

    for (std::vector<int>::iterator it = b.end()-1; it != b.begin()-1; --it)
    {
        for (int collection_num = 0; collection_num < *it; collection_num ++)
        {
            for (int collection_cursor = collection_num; collection_cursor < p; collection_cursor += *it)
            {
                int i = collection_cursor - *it;
                for (; i >= 0 && a[i] > a[i + *it]; i -= *it) {
                    std::swap(a[i], a[i + *it]);
                }
            }
        }
    }
}
#endif //SORT_SHELL_SORT_H
