#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string name;
    string surname;
    double expenditure;
    int points;
    ofstream outFile;
    outFile.open("LoyaltyPoints.txt");

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter surname: ";
    cin >> surname;
    cout << "Enter amount spent: R";
    cin >>expenditure;

    if(outFile.is_open()){
       int units = expenditure / 10;
        for(int i = 0; i <= units - 1; i++){
            points ++;
        }
        if(expenditure >= 100){
            points += 10;
        }
        outFile << name << ' ' << surname << " has earned " << points << " points." << endl; 
        cout << "Loyaly file has been updated" << endl;


    }else{
        cout << "Error: Cant open file" << endl;
    }

    
    
    
    outFile.close(); 
    return 0;
}