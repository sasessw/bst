//
// Created by gerdon on 11.12.17.
//

#ifndef SORT_QUICK_SORT_H_H
#define SORT_QUICK_SORT_H_H


template <typename T>
void change_pivot(T* array, size_t size){
    if(((array[sizeof(array)/sizeof(*array)])<=(array[0])<=(array[sizeof(array)/2*sizeof(*array)]))||
            ((array[sizeof(array)/sizeof(*array)])>=(array[0])>=(array[sizeof(array)/2*sizeof(*array)])))
            {std::swap(array[sizeof(array)/sizeof(*array)],array[0]);}
    if(((array[sizeof(array)/sizeof(*array)])>=(array[sizeof(array)/2*sizeof(*array)])>=(array[0]))||
            ((array[sizeof(array)/sizeof(*array)])<=(array[sizeof(array)/2*sizeof(*array)])<=(array[0])))
            {std::swap(array[sizeof(array)/sizeof(*array)],array[0]);}
}

template <typename T>
int partition(T* array, int left, int right)
{
//   change_pivot(array, sizeof(array)/sizeof(*array));
    int index = left;
    T pivot = array[index];
    std::swap(array[index], array[right]);
    for (int i = left; i < right; i++)
    {
        if (array[i] < pivot)
            std::swap(array[index++], array[i]);
    }
    std::swap(array[right], array[index]);
    return index;
}


template <typename T>
void qsort(T* array, int left, int right)
{
    if (left >= right)
        return;

    int index = partition(array, left, right);
    qsort(array, left, index - 1);
    qsort(array, index + 1, right);
}

template <typename T>
void quick_sort(T *array, int len) {
    qsort(array, 0, len - 1);
}

#endif //SORT_QUICK_SORT_H_H
