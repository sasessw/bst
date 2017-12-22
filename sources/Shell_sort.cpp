//  SHELL_SORT

#include <assert.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include "../includes/Shell_sort.h"
#include <chrono>
#include <mysql/mysql.h>
#include "../includes/template_array.h"



int main()
{
    T_array<std::string> b(19);
    b.generateArray(10);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    b.getArray();
    start = std::chrono::system_clock::now();
    Shell_sort(b.getArray_(),b.getSize());
    end = std::chrono::system_clock::now();
    b.getArray();
    size_t elapsed_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    cout << "time is" << elapsed_nano << endl;
}