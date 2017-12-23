//  INSERTION_SORT


#include <iostream>
#include <chrono>
#include "../includes/insertion_sort.h"

#include "../includes/template_array.h"
using namespace std;






int main(int argc, char const *argv[]){
	T_array<std::string> b(19);
	b.generateArray(10);
	std::chrono::time_point<std::chrono::system_clock> start, end;
	b.getArray();
	start = std::chrono::system_clock::now();
	insertsort(b.getArray_(),b.getSize());
	end = std::chrono::system_clock::now();
	b.getArray();
	size_t elapsed_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
	cout << "time is" << elapsed_nano << endl;

	return 0;
}