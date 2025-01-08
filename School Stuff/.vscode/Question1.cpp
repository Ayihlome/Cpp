#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std; 

void displayMenu() {
    cout << "Cafeteria Menu:\n";
    cout << "1. Burger - R50.00\n";
    cout << "2. Pizza - R75.00\n";
    cout << "3. Soda - R20.00\n";
    cout << "4. Salad - R30.00\n";
    cout << "5. Coffee - R15.00\n";
    cout << "6. Tea - R12.00\n";
    cout << "7. Sandwich - R40.00\n";
    cout << "8. Fries - R25.00\n";
}

int main () {
    // User name and surname:
    string namesurname;
    cout << "Please enter your Name and Surname:   ";
    cin >> namesurname;

    // Display Menu:
    displayMenu(); 


    map<string, float> menu;
    menu["Burger"] = 50.00; 
    menu["Pizza"] = 75.00; 
    menu["Soda"] = 20.00; 
    menu["Salad"] = 30.00; 
    menu["Coffee"] = 15.00; 
    menu["Tea"] = 12.00; 
    menu["Sandwich"] = 40.00;
    menu["Fries"] = 25.00;  

    // Ordering
    int choice;
    float totalBill = 0;


    for (int i = 0; i < 8; i++) {
        cout << "Please place your order (1-8) (0 to stop ordering): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        // Process each choice in the loop
        switch (choice) {
            case 1:
                totalBill += menu["Burger"];
                break;
            case 2: 
                totalBill += menu["Pizza"];
                break;
            case 3: 
                totalBill += menu["Soda"];
                break;
            case 4: 
                totalBill += menu["Salad"];
                break;
            case 5: 
                totalBill += menu["Coffee"];
                break;
            case 6: 
                totalBill += menu["Tea"];
                break;
            case 7: 
                totalBill += menu["Sandwich"];
                break;
            case 8: 
                totalBill += menu["Fries"];
                break;
            default:
                cout << "Invalid input, please choose a valid option.\n";
                break;
        }
    }

    float discount = 0;
    if (totalBill > 100) {
        discount = totalBill * 0.10;  // 10% discount
    }
    float finalBill = totalBill - discount;

    // Output the total bill and discount
    cout << "\nYour total bill is: R" << totalBill << endl;
    if (discount > 0) {
        cout << "Discount applied: R" << discount << endl;
    }
    cout << "Final bill after discount: R" << finalBill << endl;

    // Write the final bill to a text file
    ofstream billFile("CafeteriaBill.txt");
    if (billFile.is_open()) {
        billFile << "Customer: " << namesurname << endl;
        billFile << "Total bill: R" << totalBill << endl;
        if (discount > 0) {
            billFile << "Discount applied: R" << discount << endl;
        }
        billFile << "Final bill: R" << finalBill << endl;
        billFile.close();
        cout << "The bill has been written to CafeteriaBill.txt.\n";
    } else {
        cout << "Error: Could not open file to write the bill.\n";
    }


    
    
    return 0;

}