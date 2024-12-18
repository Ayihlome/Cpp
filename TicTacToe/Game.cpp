#include <iostream>
#include <ctime> 
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool Winning(char *spaces, char player);
bool Tie(char *spaces);


int main (){
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;


    drawBoard(spaces);
    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if (Winning(spaces, player)){
            running = false;
            break;
        }else if(Tie(spaces)){
            cout << "ITS A TIE" << endl;
            running = false;
            break;
        }
        

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (Winning(spaces,player)){
            running = false;
            break;
        }else if(Tie(spaces)){
            cout << "ITS A TIE" << endl;
            running = false;
            break;
        }
        
    }


    return 0;
}


void drawBoard(char *spaces){
    cout << "     |     |     " << endl;
    cout << "  "<< spaces[0] << "  |  " << spaces[1] << "  |   "<< spaces[2] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  "<< spaces[3] << "  |  " << spaces[4] << "  |   "<< spaces[5] <<"  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  "<< spaces[6] << "  |  " << spaces[7] << "  |   "<< spaces[8] <<"  " << endl;
    cout << "     |     |     " << endl;
}

void playerMove(char *spaces, char player){
    int number;
    cout << "Enter your postion (1-9): ";
    cin >> number;
    number--;
    do
    {
     if(spaces[number] == ' '){
        spaces[number] = player;
     }
    } while (number > 9 && number < 0 && spaces[number] == ' ');
   
}

void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}

bool Winning(char *spaces, char player){
    if((spaces[0] != ' ') && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        if(spaces[0] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if((spaces[3] != ' ') && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
         if(spaces[3] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if((spaces[6] != ' ') && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
         if(spaces[6] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if((spaces[0] != ' ') && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
         if(spaces[0] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if((spaces[1] != ' ') && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
         if(spaces[1] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if((spaces[2] != ' ') && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
         if(spaces[2] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if((spaces[0] != ' ') && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
         if(spaces[0] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else if ((spaces[2] != ' ') && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
         if(spaces[2] == player){
            cout << "YOU WIN" << endl;
        }else{
            cout << "YOU LOSE" << endl;
        }
    }else{
        return false;
    }

    return true;
}

bool Tie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }

    return true;
}