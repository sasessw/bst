//
// Created by gerdon on 11.12.17.
//

#ifndef SORT_QUICK_SORT_H_H
#define SORT_QUICK_SORT_H_H



void change_pivot(int* array, size_t size){
    if(((array[sizeof(array)/sizeof(*array)])<=(array[0])<=(array[sizeof(array)/2*sizeof(*array)]))||
            ((array[sizeof(array)/sizeof(*array)])>=(array[0])>=(array[sizeof(array)/2*sizeof(*array)])))
            {std::swap(array[sizeof(array)/sizeof(*array)],array[0]);}
    if(((array[sizeof(array)/sizeof(*array)])>=(array[sizeof(array)/2*sizeof(*array)])>=(array[0]))||
            ((array[sizeof(array)/sizeof(*array)])<=(array[sizeof(array)/2*sizeof(*array)])<=(array[0])))
            {std::swap(array[sizeof(array)/sizeof(*array)],array[0]);}
}

int partition(int* array, int left, int right)
{
    change_pivot(array, sizeof(array)/sizeof(*array));
    int index = left;
    int pivot = array[index];
    std::swap(array[index], array[right]);
    for (int i = left; i < right; i++)
    {
        if (array[i] < pivot)
            std::swap(array[index++], array[i]);
    }
    std::swap(array[right], array[index]);
    return index;
}

void qsort(int* array, int left, int right)
{
    if (left >= right)
        return;

    int index = partition(array, left, right);
    qsort(array, left, index - 1);
    qsort(array, index + 1, right);
}

void quick_sort(int *array, int len) {
    qsort(array, 0, len - 1);
}


void message(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

#endif //SORT_QUICK_SORT_H_H
