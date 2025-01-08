#include <iostream>
using namespace std;

int main (){

    // Inputing the scores
    int scores[5] = {};
    cout << "Enter the scores of 5 students: " << endl;
    for(int i = 0; i < 5; i++){
        cout << "Please enter the scores of student " << i + 1 << ": ";
        cin >> scores[i];
    }

    // Outputing the marks of the students
    cout << "Scores entered: "<< endl;
    for (int i = 0; i < 5; i++){
        cout << " Student " << i + 1 << ": " << scores[i] <<endl;
    }

    // Average
    int total = 0;
    for (int i = 0; i < 5; i++){
        total += scores[i];
    }
    int average = total/5;
    cout << "Average Score:  " << average << endl;


    // Lowest
    int lowest = scores[0]; 
    for (int i = 0; i < 4; i++){
        if (scores[i] < lowest){
            lowest = scores[i];
        }
    }
    cout << "Lowest Score: " << lowest << endl;

    // Highest
     int highest = 0; 
    for (int i = 0; i < 5; i++){
        if (scores[i] > highest){
            highest = scores[i];
        }
    }

    cout << "Highest Score: " << highest << endl;

    return 0;
}