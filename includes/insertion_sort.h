//
// Created by gerdon on 23.12.17.
//

#ifndef SORT_INSERTION_SORT_H
#define SORT_INSERTION_SORT_H

template <typename T>
void insertsort(T* arr, size_t s){
    for (int i = 1; i < s; i++){
        T temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
#endif //SORT_INSERTION_SORT_H
