#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Medicine; // Forward declaration of Medicine class

class Customer {
private:
    string name;
    string contact;

public:
    // Constructor
    Customer();
    Customer(string n, string c);
        // Getter functions
    string getName() const{ return name; } ;
    string getContact()const { return contact; };

    // Function to buy medicine
    void buyMedicine();// take the input from the user for the customer record
    void storeCustomerRecord(const Customer& customer, const string& medicineName) ; // if the medicine is present in the record than assign the medicine
    bool checkMedicineInStock(const string& medicineName); // checking if the medicine the user wants to assign to a customer is present in the record or not
    static void adddata(); // add the data of customer to file
    static void viewallRecords();
  
};
#endif