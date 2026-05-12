#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

int main() {
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");

    if (!inputFile) {
        cout << "Error: Could not open codes.txt" << endl;
        return 1;
    }

    string code;

    while (inputFile >> code) {
        tree.insertNode(code);
    }
    
    inputFile.close();

    return 0;
}