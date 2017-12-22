//  INSERTION_SORT

#include <time.h>
#include <iostream>

using namespace std;

void insertsort(int arr[], int s){
	for (int i = 1; i < s; i++){
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

void message(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}


int main(){
	srand(time(NULL));
    const int ARRAY_LEN = 20;
    const int INT_RANGE = 100;
    int *array = new int[ARRAY_LEN];

    for (int i = 0; i < ARRAY_LEN; i ++) {
        array[i] = rand() % INT_RANGE;
    }

	message(array, ARRAY_LEN);

	insertsort(array, ARRAY_LEN);
	
	message(array, ARRAY_LEN);


	return 0;
}