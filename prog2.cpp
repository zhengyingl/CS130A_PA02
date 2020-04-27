#include <fstream>
#include "heap.h"

using namespace std;

int main(int argc, char* argv[]) {
    Heap h1;

    string argv1 = "";
    if(argv[1]) {
        argv1 = argv[1];
    }
    size_t space;
    size_t comma;
    string command;

    ifstream ifs;
    string line;

    ifs.open("PA2_dataset.txt");

    while(ifs) {
        getline(ifs, line);
        cout << line.substr(0, line.size()) << endl;
    }
    h1.printHeap();
    // h.insert(69);
    // h.insert(420);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(rand() % 100);
    // h.insert(1);
    // h.insert(4);
    // h.insert(8);
    // h.insert(15);
    // h.insert(21);
    // h.insert(41);
    // h.insert(83);
    // h.insert(165);
    // h.insert(331);
    // h.insert(-1);
    // h.printHeap();
    // cout << "min = " << h.getMin() << endl;
    // cout << "inserted " << h.insert(45) << endl;
    // h.printHeap();
    // cout << "max = " << h.getMax() << endl;
    // h.printHeap();
    // cout << "inserted " << h.insert(685) << endl;
    // h.printHeap();
    // cout << "max = " << h.getMax() << endl;
    // cout << "deleted " << h.deleteMin() << endl;
    // cout << "---" << endl;
    // cout << "deleted " << h.deleteMin() << endl;
    // h.printHeap();
    // cout << "deleted " << h.deleteMax() << endl;
    // h.printHeap();
    // cout << "deleted " << h.deleteMin() << endl;
    // h.printHeap();
    // cout << "deleted " << h.deleteMax() << endl;
    // h.printHeap();
    // cout << "max = " << h.getMax() << endl;
    // cout << "min = " << h.getMin() << endl;
    // h.printHeap();
    // cout << "Min = " << h.getMin() << endl;
    // cout << "Max = " << h.getMax() << endl;
    // h.deleteMax();
    // h.printHeap();
    return 0;
}