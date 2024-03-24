#pragma once

#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
using namespace std;

class Customer;

class Medicine {
private:
    int NDC;
    string name;
    string chemicalName;
    string dateOfManufacturing;
    string dateOfExpiry;
    float* price; // old price and new price
    int stock_no;
    float* profit; // dynamic array for number of stocks arrived for a particular medicine and how much profit earned from each stock

    void getprofit();

public:
    Medicine(); // Default constructor
    Medicine(int, string, string, string, string, float, float, const int); // Parameterized constructor
    ~Medicine(); // Destructor
    Medicine(const Medicine& obj); // Copy constructor

    friend class Customer; // populatearray function is used in the customer class thats why made friend to give acccesss

    void setNDC(int);
    void setName(string);
    void setChemicalName(string);
    void setDateOfManufacturing(string);
    void setDateOfExpiry(string);
    void setPrices(float, float);
    void setStock(int);

    int getNDC();
    string getName();
    string getChemicalName();
    string getDateOfManufacturing();
    string getDateOfExpiry();
    float getCurrentPrice();
    float getDiscountedPrice();
    void setprofit();
    int getStock();

    string toString();
    void writeToFile(); 
    static string viewAllRecords();

    int cal_totalprofit(); // to calculate the sum of individual profit from respective stocks to get total profit
    friend ostream& operator<<(ostream& output, const Medicine& m);
    friend istream& operator>>(istream& input, Medicine& medicine);
    friend Medicine operator+(int i, const Medicine& m); //incrementing the price of the medicine 
    friend Medicine operator-(int i, const Medicine& m); // decrementing the price of the medicine
    bool operator = (Medicine m); // to get the true result if the two medicines are having the same chemical name 
    static void populateMedicineArray(Medicine*& medArray, int& arraySize); // reading file of medicine and populating the array so that other functions can be performed using that array
    static void adddata(); // adding new record of medicine to the file by taking input from the user

};

#endif

