#include "heap.h"

using namespace std;

int main() {
    srand (time(NULL));
    Heap h;
    // h.insert(69);
    // h.insert(420);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    h.insert(1);
    h.insert(4);
    h.insert(8);
    h.insert(15);
    h.insert(21);
    h.insert(41);
    h.insert(83);
    h.insert(165);
    h.insert(331);
    // h.insert(-1);
    h.printHeap();
    cout << "Min = " << h.getMin() << endl;
    cout << "Max = " << h.getMax() << endl;
    return 0;
}