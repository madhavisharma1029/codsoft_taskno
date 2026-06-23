#include <iostream>
using namespace std;

char board[10] = {' ','1','2','3','4','5','6','7','8','9'}; 

void displayBoard() {
    cout << "\n";
    cout << " " << board[1] << " | " << board[2] << " | " << board[3] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[4] << " | " << board[5] << " | " << board[6] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[7] << " | " << board[8] << " | " << board[9] << "\n";
    cout << "\n";
}

bool checkWin(char player) {
    int winCombos[8][3] = {
        {1,2,3}, {4,5,6}, {7,8,9}, 
        {1,4,7}, {2,5,8}, {3,6,9}, 
        {1,5,9}, {3,5,7}           
    };

    for (int i = 0; i < 8; i++) {
        int a = winCombos[i][0];
        int b = winCombos[i][1];
        int c = winCombos[i][2];
        if (board[a] == player && board[b] == player && board[c] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw() {
    for (int i = 1; i <= 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; 
        }
    }
    return true;
}

int main() {
    char playAgain;

    do {

        
        for (int i = 1; i <= 9; i++) {
            board[i] = '0' + i;
        }

        char currentPlayer = 'X';
        int move;
        bool gameOver = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

        while (!gameOver) {

            displayBoard();

            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move < 1 || move > 9 || board[move] == 'X' || board[move] == 'O') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[move] = currentPlayer;

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}