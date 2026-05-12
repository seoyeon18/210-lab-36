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

    cout << "Codes loaded into BST" << endl;
    cout << "Codes in sorted order:";
    tree.displayInOrder();

    return 0;
}

void showMenu() {
    cout << "========== Code BST Menu ==========" << endl;
    cout << "1. Add a code" << endl;
    cout << "2. Delete a code" << endl;
    cout << "3. Search for a code" << endl;
    cout << "4. Modify a code" << endl;
    cout << "5. Display all codes" << endl;
    cout << "6. Quit" << endl;
    cout << "===================================" << endl;
}