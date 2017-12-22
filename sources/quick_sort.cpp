//  QUICK_SORT

#include <time.h>
#include <iostream>
#include <chrono>
#include "../includes/quick_sort.h"
#include "../includes/template_array.h"

int main(){
    T_array<std::string> b(1900);
    b.generateArray(10);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    b.getArray();
    start = std::chrono::system_clock::now();
    quick_sort(b.getArray_(),b.getSize());
    end = std::chrono::system_clock::now();
    b.getArray();
    size_t elapsed_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    cout << "time is" << elapsed_nano << endl;
	


	return 0;
}