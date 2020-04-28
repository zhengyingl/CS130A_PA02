#include "heap.h"
#include <fstream>

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
    string word;

    ifstream ifs;
    string line;

    ifs.open("/autograder/submission/PA2_dataset.txt");

    while(ifs) {
        getline(ifs, line);
        if(line.substr(0, line.size()) + "" != "") {
            h1.insert(stoi(line.substr(0, line.size()) + ""));
        }
    }

    for(int i = 0; i < argv1.size(); i++) {
        space = argv1.find(" ", i);
        comma = argv1.find(",", i);
        if(space < comma) {
            command = argv1.substr(i, space - i);
            word = argv1.substr(space + 1, comma - space - 1);
        } else {
            command = argv1.substr(i, comma - i);
        }

        if(!command.compare("insert")) {
            cout <<  "inserted " << h1.insert(stoi(word + "")) << endl;
        } else if(!command.compare("getMin")) {
            cout << "min = " << h1.getMin() << endl;
        } else if(!command.compare("getMax")) {
            cout << "max = " << h1.getMax() << endl;
        } else if(!command.compare("deleteMin")) {
            cout << "deleted " << h1.deleteMin() << endl;
        } else if(!command.compare("deleteMax")) {
            cout << "deleted " << h1.deleteMax() << endl;
        } else if(!command.compare("printHeap")) {
            h1.printHeap();
        }
    }
    return 0;
}