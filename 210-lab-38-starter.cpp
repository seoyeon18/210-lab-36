#include <iostream>
#include <fstream>
#include <string>
#include "IntBinaryTree.h"

using namespace std;

int main()
{
    IntBinaryTree tree;
    ifstream inputFile("codes.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open codes.txt" << endl;
        return 1;
    }

    string code;
    string oldCode;
    string newCode;

    while (inputFile >> code)
    {
        tree.insertNode(code);
    }

    inputFile.close();

    cout << "Codes loaded into BST" << endl;
    cout << "Codes in sorted order:";
    tree.displayInOrder();

    int choice;

    do
    {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter code to add:";
            cin >> code;

            if (tree.searchNode(code))
            {
                cout << "That code already exists" << endl;
            }
            else
            {
                tree.insertNode(code);
            }
            break;
        case 2:
            cout << "Enter code to delete: ";
            cin >> code;

            if (tree.searchNode(code))
            {
                tree.remove(code);
                cout << "Code deleted" << endl;
            }
            else
            {
                cout << "Code not found" << endl;
            }
            break;
        case 3:
            cout << "Enter code to search:";
            cin >> code;

            if (tree.searchNode(code))
            {
                cout << "Code found." << endl;
            }
            else
            {
                cout << "Code not found." << endl;
            }
        case 4:
            cout << "Enter code to modify: ";
            cin >> oldCode;

            if (tree.searchNode(oldCode))
            {
                cout << "Enter new code: ";
                cin >> newCode;

                if (tree.searchNode(newCode))
                {
                    cout << "New code already exists. Modify cancelled." << endl;
                }
                else
                {
                    tree.remove(oldCode);
                    tree.insertNode(newCode);
                    cout << "Code modified." << endl;
                }
            }
            else
            {
                cout << "Original code not found." << endl;
            }
            break;
        case 5:
            cout << "\nCodes in sorted order:" << endl;
            tree.displayInOrder();
            break;
        case 6:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}

void showMenu()
{
    cout << "========== Code BST Menu ==========" << endl;
    cout << "1. Add a code" << endl;
    cout << "2. Delete a code" << endl;
    cout << "3. Search for a code" << endl;
    cout << "4. Modify a code" << endl;
    cout << "5. Display all codes" << endl;
    cout << "6. Quit" << endl;
    cout << "===================================" << endl;
}