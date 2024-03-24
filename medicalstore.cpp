#include "medicalstore.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

// Constructor
Medicine::Medicine() {
    NDC = 00;
    name = "";
    chemicalName = "";
    dateOfManufacturing = "";
    dateOfExpiry = "";
    price = new float[2]; // Allocate memory for the price array dynamically
    price[0] = 0; // Set old price to the provided value
    price[1] = 0; // Set new price to the provided value
    stock_no = 1;
    profit = new float[stock_no];
}

class stock{};

// Parameterized Constructor
Medicine::Medicine(int ndc, string n, string cn, string dom, string doe, float cp, float dp,int count) {
    NDC = ndc;
    name = n;
    chemicalName = cn;
    dateOfManufacturing = dom;
    dateOfExpiry = doe;
    price = new float[2]; // Allocate memory for the price array dynamically
    price[0] = 0; // Set old price to the provided value
    price[1] = 0; // Set new price to the provided value
    this -> stock_no = count;
    profit = new float[stock_no]; // dynamic array in which " jitna no of stocks hon gy otni array size define ho jy gi"
    cout << "No of stocks arrived " <<stock_no << endl;
    getprofit();
}

// Destructor
Medicine::~Medicine() {
    delete[]price; // free memory/ preventing memory leakage 
    delete[]profit;// free memory/ preventing memory leakage 
}

// Copy Constructor
Medicine::Medicine(const Medicine& obj) {
    NDC = obj.NDC;
    name = obj.name;
    chemicalName = obj.chemicalName;
    dateOfManufacturing = obj.dateOfManufacturing;
    dateOfExpiry = obj.dateOfExpiry;
    price = new float[2]; // Allocate memory for the price array dynamically
    this -> price[0] = obj.price[0]; // Copying old price
    this -> price[1] = obj.price[1]; // Copying new price
    stock_no = obj.stock_no;
    profit = new float[stock_no];  // dynamic array in which " jitna no of stocks hon gy otni array size define ho jy gi"
    for (int i = 0; i < stock_no; ++i) {
        profit[i] = obj.profit[i]; // Copying profit values
    }
}

// Setter functions
void Medicine::setNDC(int ndc) {
    NDC = ndc;
}

void Medicine::setName(string n) {
    name = n;
}

void Medicine::setChemicalName(string cn) {
    chemicalName = cn;
}

void Medicine::setDateOfManufacturing(string dom) {
    dateOfManufacturing = dom;
}

void Medicine::setDateOfExpiry(string doe) {
    dateOfExpiry = doe;
}

void Medicine::setPrices(float cp, float dp) {
    price[0] = cp; // Setting the value of old price
    price[1] = dp; // Setting the value of new price
}

void Medicine::setStock(int stock) {
    stock_no = stock;
}

void Medicine::setprofit() {
    profit = new float[stock_no]; // Allocate memory for profit array based on stock_no
    for (int i = 0; i < stock_no; i++) {
        cout << "Profit of stock " << i + 1 << ": ";
        cin >> profit[i];
    }
}



// Getter functions
int Medicine::getNDC() {
    return NDC;
}

string Medicine::getName() {
    return name;
}

string Medicine::getChemicalName() {
    return chemicalName;
}

string Medicine::getDateOfManufacturing() {
    return dateOfManufacturing;
}

string Medicine::getDateOfExpiry() {
    return dateOfExpiry;
}

float Medicine::getCurrentPrice() {
   return price[0]; // Returning the value of old price
}

float Medicine::getDiscountedPrice() {
    return  price[1]; // Returning the value of old price;
}

void Medicine::getprofit() {
profit = new float[stock_no]; // Allocate memory for profit array based on stock_no
    for (int i = 0; i < stock_no; i++) {
        cout << "Profit of stock " << i + 1 << ": " << profit[i] << "/t";
       
    }
}

int Medicine::getStock() {
    return stock_no;
}

//tostring function to check the state of the object
string Medicine::toString() {
    string result = "NDC: " + to_string(NDC) + "\nName: " + name + "\nChemical Name: " + chemicalName + "\nDate of Manufacturing: " + dateOfManufacturing + "\nDate of Expiry: " + dateOfExpiry + "\nCurrent Price: $" + to_string(price[0]) + "\nDiscounted Price: $" + to_string(price[1]);

    // Append stock information
    result += "\nStock: " + to_string(stock_no);

    // Append profit information
    result += "\nProfit:";
    for (int i = 0; i < stock_no; i++) {
        result += "\n  Stock " + to_string(i + 1) + " Profit: $" + to_string(profit[i]);// tking individual profit of stock
    }

    return result;
}



// Function to write object details to a file
void Medicine::writeToFile() {
    ofstream fout("MEDICINES_LIST.txt", ios::app);
    fout << left << setw(20) << NDC << setw(20) << name << setw(20) << chemicalName << setw(20) << dateOfManufacturing << setw(20) << dateOfExpiry << setw(10) << fixed << setprecision(2) << price[0] << setw(10) << price[1];
    // Append stock information
    fout << setw(10) << stock_no;
    // Append profit information
    for (int i = 0; i < stock_no; i++) {
        fout << setw(10) << profit[i];
    }
    fout << endl;
    fout.close();
}


// Function to view all records
string Medicine::viewAllRecords() {
    ifstream fin("MEDICINES_LIST.txt");
    string result;
    string line;
    while (getline(fin, line)) {
        result += line + "\n";
    }
    fin.close();
    cout << result;
    return result;
}


int Medicine::cal_totalprofit() {

    float sum = 0.0;
    for (int i = 0; i< stock_no; i++) {
        sum = sum + profit[i];
    }
    return sum;
}

Medicine operator+(int i, const Medicine& m) {
    Medicine temp = m;
    temp.price[0] += i;
    return temp;
}

Medicine operator-(int i, const Medicine& m) {
    Medicine temp = m;
    temp.price[0] -= i;
    return temp;
}
bool Medicine::operator=(Medicine m) {
    if (this->chemicalName == m.chemicalName) // if the two medicines chemical names re same returning the true result
        return true;

    return false;
}

istream& operator>>(istream& input, Medicine& medicine) {
    bool debugMode = false; // Set to true if you want to print debug information
    if (debugMode) {
        cout << "ADD THE RECORD OF MEDICINE \n";
        cout << "NDC  ";
    }
    input >> medicine.NDC;
    if (debugMode) {
        cout << "Name  ";
    }
    input >> medicine.name;
    if (debugMode) {
        cout << "Chemical Name  ";
    }
    input >> medicine.chemicalName;
    if (debugMode) {
        cout << "Date of Manufacturing  ";
    }
    input >> medicine.dateOfManufacturing;
    if (debugMode) {
        cout << "Date of Expiry  ";
    }
    input >> medicine.dateOfExpiry;
    if (debugMode) {
        cout << "Current Price  ";
    }
    input >> medicine.price[0];
    if (debugMode) {
        cout << "Discounted Price  ";
    }
    input >> medicine.price[1];
    if (debugMode) {
        cout << "Stock  ";
    }
    input >> medicine.stock_no;
    if (debugMode) {
        cout << "Profit: ";
    }
    medicine.profit = new float[medicine.stock_no];
    for (int i = 0; i < medicine.stock_no; ++i) {
        input >> medicine.profit[i];
    }
    return input;
}



ostream& operator<<(ostream& output, const Medicine& m) {
    output << "\nNDC: " << m.NDC << "\nName: " << m.name << "\nChemical Name: " << m.chemicalName << "\nDate of Manufacturing: " << m.dateOfManufacturing << "\nDate of Expiry: " << m.dateOfExpiry << "\nCurrent Price: $" << m.price[0] << "\nDiscounted Price: $" << m.price[1];
    output << "\nStock: " << m.stock_no;
    output << "\nProfit:";
    for (int i = 0; i < m.stock_no; ++i) {
        output << "\n  Stock " << i + 1 << " Profit: $" << m.profit[i];
    }
    return output;
}


  // Function to populate dynamic array of Medicine objects from file
void Medicine::populateMedicineArray(Medicine*& medArray, int& arraySize) {
    ifstream fin("MEDICINES_LIST.txt");
    if (!fin) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    // Count the number of medicine records in the file
    int count = 0;
    string line;
    while (getline(fin, line)) {
        count++;
    }
    fin.clear(); // Clear eof flag
    fin.seekg(0, ios::beg); // Move file pointer to beginning

    // Allocate memory for the array
    arraySize = count;
    medArray = new Medicine[arraySize]; // creating Medicine obj dynamic array

    // Read data from file and populate the array
    for (int i = 0; i < arraySize; i++) {
        bool debugMode = false; // Set to true if you want to print debug information
        if (debugMode) {
            cout << "Reading Medicine record " << i + 1 << ":" << endl;
        }
        fin >> medArray[i]; // Assuming operator>> is defined for Medicine class
    }

    fin.close();
}

void Medicine::adddata() {
    Medicine medicine;
        cout << "Enter the details of the medicine: " << endl;
        cin >> medicine;
        cout << endl << "The medicine details are: " << endl;
        cout << medicine;
    
    medicine.writeToFile();
}



