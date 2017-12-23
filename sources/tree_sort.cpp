//  TREE_SORT

#include <chrono>
#include "../includes/tree_sort.h"
#include "../includes/template_array.h"
int main() {


    T_array<std::string> b(19);
    b.generateArray(10);
    std::chrono::time_point<std::chrono::system_clock> start, end;
    b.getArray();
    tree str_t = tree();

    start = std::chrono::system_clock::now();
    for (int i = 0; i < b.getSize(); ++i) {
        str_t.put(b.getElem(i));
    }
    end = std::chrono::system_clock::now();
    size_t elapsed_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    str_t.print();
    cout << "time is" << elapsed_nano << endl;



//    tree t = tree();
//    for (int i = 0; i < vector.size(); ++i) {
//        t.put(vector.at(i));
//    }
//    t.print();
//    t.printBack();

    return 0;
}
