#ifndef HEAP_H
#define HEAP_H

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Heap {
public:
    Heap() { v.push_back(0); }
    int getMin() const;
    int getMax() const;
    int insert(int x);
    int deleteMin();
    int deleteMax();
    void printHeap() const;

private:
    std::vector<int> v;
    void swap(size_t i, size_t j);
    void bubbleUpMin(size_t i);
    void bubbleUpMax(size_t i);
};

#endif