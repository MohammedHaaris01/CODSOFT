#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

    int minimum = 0, maximum = 0;
    int level;
    int number, guessed_number;
    int attempts = 0;
    int difference;

    cout << "-----------NUMBER GUESSING GAME-----------" << endl;
    cout << "------------------------------------------" << endl;

    // Selecting difficulty level
    cout << "Choose difficulty level:" << endl;
    cout << "1. Easy (Range: 1-100)" << endl;
    cout << "2. Medium (Range: 1-500)" << endl;
    cout << "3. Hard (Range: 1-1000)" << endl;
    cout << "Enter your choice: ";
    cin >> level;

    switch (level) {
        case 1:
            minimum = 1;
            maximum = 100;
            break;
        case 2:
            minimum = 1;
            maximum = 500;
            break;
        case 3:
            minimum = 1;
            maximum = 1000;
            break;
        default:
            cout << "Invalid choice, setting difficulty to Easy." << endl;
            minimum = 1;
            maximum = 100;
            break;
    }

    
    number = rand() % (maximum - minimum + 1) + minimum;

    while (true) {
        cout << "Enter a number between " << minimum << " and " << maximum << ": ";
        cin >> guessed_number;
        difference = guessed_number - number;

        if (difference == 0) {
            cout << "Congratulations!!! You have guessed the number in " << attempts << " attempts!!!" << endl;
            break;
        } else if (difference > 0) {
            cout << "The number is higher!" << endl;
        } else {
            cout << "The number is lower!" << endl;
        }

        if (abs(difference) <= 5) {
            cout << "You are very close!!!" << endl;
        } else if (abs(difference) <= 10) {
            cout << "You are close!" << endl;
        } else if (abs(difference) <= 25) {
            cout << "You are getting there!" << endl;
        } else if (abs(difference) <= 50) {
            cout << "You are far away!" << endl;
        } else {
            cout << "You are very far!" << endl;
        }

        attempts++;
    }

    return 0;
}
