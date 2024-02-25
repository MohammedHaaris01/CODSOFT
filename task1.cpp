#include <cstdlib>
#include <iostream>
using namespace std;

int main(){

    int minimum = 0 , maximum = 500;

    int number = ( rand() % ( maximum - minimum + 1 ) ) + minimum ;
    int guessed_number;
    int  attempts = 0 ;
    int difference;

    cout << "-----------NUMBER GUESSING GAME-----------" << endl ;
    cout << "------------------------------------------" << endl ;
    
    while ( 1 ){
        cout << "Enter a number between 0 and 500 : ";
        cin >> guessed_number;
        difference = guessed_number - number;

        if ( difference == 0){
            cout << "Congratulations!!! You have guessed the number in " << attempts << " attempts!!!";
            break;
        }

        else if ( difference <= 5 && difference > 0) {
            cout << "You are it's neighbour!!!" << endl ;
            attempts++;
        }

        else if ( difference <= 10 && difference > 5) {
            cout << "You are so close!!!" << endl ;
            attempts++;
        }

        else if ( difference > 10 && difference <= 25 ) {
            cout << "You are closer!" << endl ;
            attempts++;
        }

        else if ( difference > 25 && difference <= 50 ) {
            cout << "You are close!" << endl ;
            attempts++;
        }

        else if ( difference > 50 && difference <= 100 ) {
            cout << "You are far away!!!" << endl ;
            attempts++;
        }

        else if ( difference > 100 ){
            cout << "You are very far!!!!!" << endl ;
            attempts++;
        }

        else if ( difference >= -5 && difference < 0) {
            cout << "You are it's neighbour!!!" << endl ;
            attempts++;
        }

        else if ( difference >= -10 && difference < -5) {
            cout << "You are so close!!!" << endl ;
            attempts++;
        }

        else if ( difference < -10 && difference >= -25 ) {
            cout << "You are closer!" << endl ;
            attempts++;
        }

        else if ( difference < -25 && difference >= -50 ) {
            cout << "You are close!" << endl ;
            attempts++;
        }

        else if ( difference < -50 && difference >= -100 ) {
            cout << "You are far away!!!" << endl ;
            attempts++;
        }

        else if ( difference < -100 ){
            cout << "You are very far!!!!!!" << endl ;
            attempts++;
        }
    }
  
    return 0; 

}