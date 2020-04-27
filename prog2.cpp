#include "heap.h"

using namespace std;

int main() {
    srand (time(NULL));
    Heap h;
    h.insert(69);
    h.insert(420);
    h.insert(rand() % 100);
    h.insert(rand() % 100);
    h.insert(rand() % 100);
    h.insert(rand() % 100);
    h.insert(rand() % 100);
    h.insert(rand() % 100);
    h.insert(rand() % 100);
    h.printHeap();
    return 0;
}