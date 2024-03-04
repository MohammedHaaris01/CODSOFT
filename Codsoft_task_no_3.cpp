#include <iostream>
using namespace std;

int main() {

    string player_1;
    string player_2;

    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    do {
        cout << "----------CONSOLE BASED TIC TAC TOE GAME----------" << endl;
        cout << "Enter Player 1's name: ";
        cin >> player_1;

        cout << "Enter Player 2's name: ";
        cin >> player_2;

        int currentPlayer = 1; // Player 1 starts
        int moves = 0;

        while (true) {
            cout << "Tic Tac Toe Board:" << endl;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << "| " << board[i][j] << " | ";
                }
                cout << endl;
            }

            int move;
            cout << (currentPlayer == 1 ? player_1 : player_2) << ", enter your move (1-9): ";
            cin >> move;

            // Check if move is valid
            if (move < 1 || move > 9) {
                cout << "Invalid move! Please enter a number between 1 and 9." << endl;
                continue;
            }

            // Convert move to row and column indices
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            // Check if cell is already occupied
            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "That cell is already occupied! Please choose another one." << endl;
                continue;
            }

            // Update board with player's move
            if (currentPlayer == 1)
                board[row][col] = 'X';
            else
                board[row][col] = 'O';

            // Check for a winner
            // Winning conditions: Rows, Columns, Diagonals
            if ((board[0][0] == board[0][1] && board[0][0] == board[0][2]) ||
                (board[1][0] == board[1][1] && board[1][0] == board[1][2]) ||
                (board[2][0] == board[2][1] && board[2][0] == board[2][2]) ||
                (board[0][0] == board[1][0] && board[0][0] == board[2][0]) ||
                (board[0][1] == board[1][1] && board[0][1] == board[2][1]) ||
                (board[0][2] == board[1][2] && board[0][2] == board[2][2]) ||
                (board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
                (board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
                cout << (currentPlayer == 1 ? player_1 : player_2) << " wins!" << endl;
                break;
            }

            moves++;

            // Check for a draw
            if (moves == 9) {
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'n' || playAgain == 'N')
            break;

        // Reset the board for the new game
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + i * 3 + j;
            }
        }

    } while (true);

    cout << "Thanks for playing!" << endl;

    return 0;
}
