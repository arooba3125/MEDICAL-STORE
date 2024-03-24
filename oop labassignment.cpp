#include<iostream>
#include "medicalstore.h"
#include "Customer.h"
using namespace std;

int main() {
    Medicine* medArray = nullptr; // Dynamic array of Medicine objects
    int arraySize = 0;

    int choice;
    do {
        cout << "**** 1. Medicine Details ****\n";
        cout << "**** 2. Customer Details ****\n";
        cout << "**** 3. Exit ****\n\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "MEDICINE DETAILS\n";
            cout << "1. Add Data\n";
            cout << "2. View Data\n";
            cout << "Enter your choice: ";
            int choice1;
            cin >> choice1;
            switch (choice1) {
            case 1:
                Medicine::adddata();
                break;
            case 2:
                Medicine::populateMedicineArray(medArray, arraySize); // Populate dynamic array
                for (int i = 0; i < arraySize; ++i) {
                    cout << medArray[i] << endl; // Display medicine details
                }
                break;
            default:
                cout << "Invalid choice\n";
            }
            break;
        case 2:
            cout << "CUSTOMER DETAILS\n";
            cout << "1. Add Data\n";
            cout << "2. View Data\n";
            cout << "Enter your choice: ";
            int choice2;
            cin >> choice2;
            switch (choice2) {
            case 1:
                Customer::adddata();
                break;
            case 2:
                Customer::viewallRecords();
                break;
            default:
                cout << "Invalid choice\n";
            }
            break;
        case 3:
            exit(0);
        default:
            cout << "Enter valid choice\n";
        }

    } while (choice != 3);

    // Clean up allocated memory
    delete[] medArray;

    return 0;
}
