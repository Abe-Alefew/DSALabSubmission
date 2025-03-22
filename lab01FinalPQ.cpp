#include <iostream>
#include <string>
#include <fstream> //Optional:File creating
using namespace std;
#define TAX_RATE_CONSTANT 0.6 //defining constant by preprocessor directive

int main(){
    // Displaying an introductory Message
    cout << "This program analyzes the product sales and inventory for a store." <<'\n';
    cout << "Remember that C++ is a compiled language" <<'\n';

    //Declaring Variables for Product details and demonstrating different initalization method
    string productName = "Phone";// direct initlization
    int productCategory = 3;
    int Inventory = 4;
    float productPricePerUnit;
    productPricePerUnit = 9999.99;

    int soldNumOfItems;
    soldNumOfItems = 2;

    //Declaring variables for computed values;

    int newInventory;
    float totalSales;
    string inventoryStatus;


    

    //defining constant

    const double tax_rate_constant = 0.6;

    //input from the user
    cout << "Product categories: 1-Electronics, 2-Groceries, 3-Clothing, 4-Stationery, 5-Miscellaneous" << '\n';
    cout << "Enter a product category(only from 1-5 inclusive): " ;
    cin >> productCategory;
    cout << "Enter a product name(only single word): ";
    cin >> productName;
    cout << "Enter the initial inventory quantity(only a positive number): ";
    cin >> Inventory;
    cout << "Enter the product price: ";
    cin >> productPricePerUnit;
    cout << "How many number of items you sold? ";
    cin >> soldNumOfItems;
    

    //Calculating
    Inventory -= soldNumOfItems;
    newInventory = Inventory;
    totalSales = soldNumOfItems * productPricePerUnit;

    //Type Deduction

    auto salesHelper = totalSales;
    decltype(Inventory) initialHelper = newInventory;

    inventoryStatus = (newInventory < 10) ? "Low Inventory" : "Sufficent Inventory";// using ternary operator

    cout << "------Receipt------" << '\n';

    //implementing flow control
    if (productCategory <=5 && productCategory >=1){
        cout << "The product category is valid" << '\n';
    } else{
        cout << "The product category is not valid." << '\n';
    }

    switch (productCategory)
    {
    case 1:
        cout << "Category 1: Electronics" << '\n';
        break;
    case 2:
        cout << "Category 2: Groceries" << '\n';
        break;
    case 3:
        cout << "Category 3: Clothing" << '\n';
        break;
    case 4:
        cout << "Category 4: Stationery" << '\n';
        break;
    case 5:
        cout << "Category 5: Miscellaneous" << '\n';
        break;
    default:
        cout << "Category not found" << '\n';
        break;
        
    }

    // Implementating a For Loop

    for (int i=1; i <= soldNumOfItems; i++){
        cout << "----" << productName  << ": " << productPricePerUnit <<" birr. -----" << '\n';

    }
    cout << "------result------" << '\n';
    //Displaying the results
    cout<< "Tax rates using const: " << tax_rate_constant << '\n';
    cout << "Tax rates using #define: " << TAX_RATE_CONSTANT << '\n';
    cout << "Product Name: " << productName << '\n';
    cout << "Product Category: " << productCategory << '\n';
    cout << "Initial Inventory: " << Inventory << '\n';
    cout << "Product Price: " << productPricePerUnit << '\n';
    cout << "Number of items sold: " << soldNumOfItems << '\n';
    cout << "No of Items Left: " << newInventory << '\n';
    cout << "Total Sales: " << totalSales << '\n';
    cout << "Inventory Status: " << inventoryStatus << '\n';
    cout << "Sales Helper: " << salesHelper << '\n';
    cout << "Initial Helper: " << initialHelper << '\n';

    //Additional thing - putting the output in a file
    ofstream outputFile;
    outputFile.open("reciept.txt");  
    
    if (outputFile.is_open()){
        outputFile << "------Receipt------" << '\n';
        outputFile << "Tax rates using const: " << tax_rate_constant << '\n';
        outputFile << "Tax rates using #define: " << TAX_RATE_CONSTANT << '\n';
        outputFile << "Product Name: " << productName << '\n';
        outputFile << "Product Category: " << productCategory << '\n';
        outputFile << "Initial Inventory: " << Inventory << '\n';
        outputFile << "Product Price: " << productPricePerUnit << '\n';
        outputFile << "Number of items sold: " << soldNumOfItems << '\n';
        outputFile << "No of Items Left: " << newInventory << '\n';
        outputFile << "Total Sales: " << totalSales << '\n';
        outputFile << "Inventory Status: " << inventoryStatus << '\n';
        outputFile << "Sales Helper: " << salesHelper << '\n';
        outputFile << "Initial Helper: " << initialHelper << '\n';
        outputFile.close();
    } else{
        cout << "Unable to open the file" << '\n';

    }







    return 0;
}