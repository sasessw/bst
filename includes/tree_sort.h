#ifndef SORT_TREE_SORT_H
#define SORT_TREE_SORT_H
#include <exception>
#include <iostream>
#include <vector>


class node{
    std::string value;
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
    explicit node(std::string val): left(NULL), right(NULL){
        value = val;
    }

    void put(std::string val){
        if(val > value){
            if(left){
                left->put(val);
            }else{
                left = new node(val);
            }
        }
        else{
            if(right){
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

    void put(std::string val){
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


#endif //SORT_TREE_SORT_H
