#include "heap.h"

using namespace std;

int Heap::getMin() const {
    if(v.size() >= 2) {
        return v[1];
    }
    return 0;
}

int Heap::getMax() const {
    if(v.size() >= 4) {
        if(v[2] > v[3]) {
            return v[2];
        }
        return v[3];
    } else if(v.size() == 3) {
        return v[2];
    } else if(v.size() == 2) {
        return v[1];
    }
    return 0;
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
    int del = v[1];
    v[1] = v[v.size() - 1];
    v.erase(v.begin() + v.size() - 1);
    bubbleDownMin(1);
    return del;
}

int Heap::deleteMax() {
    int del;
    if(v.size() >= 4) {
        if(v[2] > v[3]) {
            del = v[2];
            v[2] = v[v.size() - 1];
            v.erase(v.begin() + v.size() - 1);
            bubbleDownMax(2);
        } else {
            del = v[3];
            v[3] = v[v.size() - 1];
            v.erase(v.begin() + v.size() - 1);
            bubbleDownMax(3);
        }
    } else if(v.size() == 3) {
        del = v[2];
        v[2] = v[v.size() - 1];
        v.erase(v.begin() + v.size() - 1);
        bubbleDownMax(2);
    } else if(v.size() == 2) {
        del = v[1];
        v[1] = v[v.size() - 1];
        v.erase(v.begin() + v.size() - 1);
        bubbleDownMin(1);
    } else {
        del = 0;
    }
    return del;
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

void Heap::bubbleDownMin(size_t i) {
    int children[6] = {2*i, 2*i + 1, 4*i, 4*i + 1, 4*i + 2, 4*i + 3};
    vector<int> valid;
    // cout << "-1" << endl;
    for(size_t j = 0; j < 6; j++) {
        if(children[j] < v.size()) {
            valid.push_back(children[j]);
        }
    }
    if(valid.empty()) {
        return;
    }
    // cout << "0" << endl;
    int smallestVal = v[valid[0]];
    int smallestInd = valid[0];
    // cout << "1" << endl;
    for(size_t j = 0; j < valid.size(); j++) {
        if(v[valid[j]] < smallestVal) {
            smallestVal = v[valid[j]];
            smallestInd = valid[j];
        }
    }
    // cout << "2" << endl;
    if(smallestInd/4 == i) {
        // cout << "smallestInd/4" << endl;
        if(v[smallestInd] < v[i]) {
            // cout << "3" << endl;
            swap(smallestInd, i);
            // cout << "4" << endl;
            if(smallestInd/2 > 0 && v[smallestInd] > v[smallestInd/2]) {
                swap(smallestInd, smallestInd/2);
            }
            // cout << "5" << endl;
            bubbleDownMin(smallestInd);
        }
    } else if(smallestInd/2 == i){
        // cout << "smallestInd/2" << endl;
        // cout << "inside smallest/1 == i" << endl;
        // cout << "smallest: " << smallestVal << endl;
        if(v[smallestInd] < v[i]) {
            swap(smallestInd, i);
            // cout << "swapped here" << endl;
        }
    }
}

void Heap::bubbleDownMax(size_t i) {
    int children[6] = {2*i, 2*i + 1, 4*i, 4*i + 1, 4*i + 2, 4*i + 3};
    vector<int> valid;
    for(size_t j = 0; j < 6; j++) {
        if(children[j] < v.size()) {
            valid.push_back(children[j]);
        }
    }
    if(valid.empty()) {
        return;
    }
    int largestVal = v[valid[0]];
    int largestInd = valid[0];
    for(size_t j = 0; j < valid.size(); j++) {
        if(v[valid[j]] > largestVal) {
            largestVal = v[valid[j]];
            largestInd = valid[j];
        }
    }
    if(largestInd/4 == i) {
        if(v[largestInd] > v[i]) {
            swap(largestInd, i);
            if(largestInd/2 > 0 && v[largestInd] < v[largestInd/2]) {
                swap(largestInd, largestInd/2);
            }
            bubbleDownMax(largestInd);
        }
    } else if(largestInd/2 == i) {
        if(v[largestInd] > v[i]) {
            swap(largestInd, i);
        }
    }
}