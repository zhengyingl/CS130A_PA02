#include "heap.h"

using namespace std;

int Heap::getMin() const {

}

int Heap::getMax() const {

}

int Heap::insert(int x) {
    v.push_back(x);
    int i = v.size() - 1;
    if((int)log2(i) % 2 == 0) {
        if(i/2 > 0 && v[i] > v[i/2]) {
            swap(i, i/2);
            bubbleUpMax(i/2);
        } else {
            bubbleUpMin(i);
        }
    } else {
        if(i/2 > 0 && v[i] < v[i/2]) {
            swap(i, i/2);
            bubbleUpMin(i/2);
        } else {
            bubbleUpMax(i);
        }
    }
    return x;
}

int Heap::deleteMin() {

}

int Heap::deleteMax() {

}

void Heap::printHeap() const{
    cout << "heap =";
    for(size_t i = 1; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "\n";
}

void Heap::swap(size_t i, size_t j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void Heap::bubbleUpMin(size_t i) {
    if(i/4 > 0) {
        if(v[i] < v[i/4]) {
            swap(i, i/4);
            bubbleUpMin(i/4);
        }
    }
}

void Heap::bubbleUpMax(size_t i) {
    if(i/4 > 0) {
        if(v[i] > v[i/4]) {
            swap(i, i/4);
            bubbleUpMax(i/4);
        }
    }
}