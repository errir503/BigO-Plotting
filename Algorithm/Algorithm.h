#include <iostream>
#include <math.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>

#include <algorithm>
#include <iterator>

#include "binaryTree.h"

class Algorithm{
    public:
        int max, count;
        int current_time_nanoseconds();
        int rand_gen();
        std::vector<int> arr_gen();
        void arr_print(std::vector<int> arr);
        BST<int> binary_tree();
        bool binarySearch(std::vector<int> arr, const int& val);
        void heap_sort(vector<int>& arr);
        void to_heap(vector<int>& arr);
        void shift_down(vector<int>& heap,int i, int max);
        void bubbleSort(vector<int>& arr);
};

int Algorithm::current_time_nanoseconds(){
    struct timespec tm;
    clock_gettime(CLOCK_REALTIME, &tm);
    return tm.tv_nsec;
}

int Algorithm::rand_gen(){
    //srand((unsigned)time(0));
    int random_number = std::rand() % this->max + 1;
    return random_number;
}

std::vector<int> Algorithm::arr_gen(){
    std::vector<int> arr;
    for (int i = 0; i < this->count; i++)
    {
        arr.push_back(this->rand_gen());
    }
    return arr;
}

void Algorithm::arr_print(std::vector<int> arr){
    int i = 0;
    for(int& loop : arr){
        std::cout << "array[" << i << "]: " << loop << std::endl;
        i += 1;
    }
}

BST<int> Algorithm::binary_tree(){
    BST<int> *bst = new BST<int>();
    for (int i = 0; i < this->count; i++)
    {
        bst->add(this->rand_gen());
    }
    return *bst;    
}

void Algorithm::shift_down(vector<int>& heap,int i, int max) {
    int i_big, c1, c2;
    while(i < max) {
        i_big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( c1<max && heap[c1]>heap[i_big] )
            i_big = c1;
        if( c2<max && heap[c2]>heap[i_big] )
            i_big = c2;
        if(i_big == i) return;
        swap(heap[i],heap[i_big]);
        i = i_big;
    }
}
 
void Algorithm::to_heap(vector<int>& arr) {
    int i = (arr.size()/2) - 1;
    while(i >= 0) {
        shift_down(arr, i, arr.size());
        --i;
    }
}
 
void Algorithm::heap_sort(vector<int>& arr) {
    to_heap(arr);
    int end = arr.size() - 1;
    while (end > 0) {
        swap(arr[0], arr[end]);
        shift_down(arr, 0, end);
        --end;
    }
}

void Algorithm::bubbleSort(vector<int>& arr) {
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < arr.size()-1; i++) {
            if (arr[i] > arr[i+1] ){
                arr[i] += arr[i+1];
                arr[i+1] = arr[i] - arr[i+1];
                arr[i] -= arr[i+1];
                swapp = true;
            }
        }
    }
}