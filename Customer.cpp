#include "Customer.h"
#include "medicalstore.h" 

Customer::Customer() {
    name = " ";
    contact = " ";
}

Customer::Customer(string n, string c) {
    name = n;
    contact = c;
}

void Customer::buyMedicine() {
    string medicineName;
    cout << "Enter the name of the medicine you want to buy: ";
    cin >> medicineName;

    // Check if medicine is present in stock and store customer record if available
    storeCustomerRecord(*this, medicineName);
}

void Customer::storeCustomerRecord(const Customer& customer, const string& medicineName) {
    if (checkMedicineInStock(medicineName)) {
        ofstream fout("Customer_Record.txt", ios::app);

        fout << "Customer Name: " << customer.getName() << endl;
        fout << "Customer Contact: " << customer.getContact() << endl;
        fout << "Medicine Name: " << medicineName << endl;
        fout << "--------------------------------------------" << endl;
        fout.close();
    }
    else {
        cout << "Medicine not available in stock!" << endl;
    }
}

bool Customer::checkMedicineInStock(const string& medicineName) {
    int arraySize;
    Medicine* medArray;
    Medicine::populateMedicineArray(medArray, arraySize);

    bool medicineFound = false;
    for (int i = 0; i < arraySize; i++) {
        if (medArray[i].getName() == medicineName) {
            medicineFound = true;
            break;
        }
    }

    delete[] medArray; // Clean up allocated memory

    return medicineFound;
}


void Customer:: adddata() {
    Customer customer;
    cout << "Enter customer name: ";
    cin >> customer.name;
    cout << "Enter customer contact: ";
    cin >> customer.contact;
    customer.buyMedicine(); // Initiate buying process

}


void Customer::viewallRecords() {
    ifstream fin("Customer_Record.txt");
    cout << "Customer Records:" << endl;
    string record;
    while (getline(fin, record)) {
        // Check if the current line is not empty
        if (!record.empty()) {
            // Print the current record
            cout << record << endl;
        }
        else {
            // Print a separator between records
            cout << "--------------------------------------------" << endl;
        }
    }

    fin.close();
}
