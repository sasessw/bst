//  TREE_SORT

#include <exception>
#include <iostream>
#include <vector>

class node{
    int value;
    node* left;
    node* right;

    ~node(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }

public:
    explicit node(int val): left(NULL), right(NULL){
        value = val;
    }

    void put(int val){
        if(val >= value){
            if(left)             {
                left->put(val);
            }else{
                left = new node(val);
            }
        }
        else{
            if(right)             {
                right->put(val);
            }else{
                right = new node(val);
            }
        }
    }

    void printBack(){
        if(left){
            left->printBack();
        }
        std::cout << value << ' ';
        if(right){
            right->printBack();
        }
    }

    void print(){
        if(right){
            right->print();
        }
        std::cout << value << ' ';
        if(left){
            left->print();
        }
    }
};





class tree{
    node* head;
public:
    tree() :head(NULL){
    }

    void put(int val){
        if(head){
            head->put(val);
        }
        else{
            head = new node(val);
        }
    }

    void print(){
        if(head){
            head->print();
        }
        else{
            std::cout << "tree is empty";
        }
        std::cout << std::endl;
    }

    void printBack(){
        if(head){
            head->printBack();
        }
        else{
            std::cout << "tree is empty";
        }
        std::cout << std::endl;
    }
};



int main() {
    std::cout << "Tree sort." << std::endl;
    std::vector<int> vector = std::vector<int>();

    vector.push_back(10);
    vector.push_back(10);
    vector.push_back(5);
    vector.push_back(1);
    vector.push_back(12);
    vector.push_back(18);
    vector.push_back(9);

    tree t = tree();
    for (int i = 0; i < vector.size(); ++i) {
        t.put(vector.at(i));
    }
    t.print();
    t.printBack();

    return 0;
}
