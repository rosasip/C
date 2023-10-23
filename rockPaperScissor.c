
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define ROUNDS 5  // pre-determines overall number of rounds.

void greeting(); // display welcome to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round

int main()
{
greeting(); //call greeting function.

//setup random generator
int seed;
printf("Before we start, pick a number to determine how random I will be.\n");
scanf("%d", &seed);
srand(seed);
printf("All set now!\n");

for(int x = 0; x < ROUNDS; ++x) { // Play multiple rounds
playRound(x + 1);
}

int userPick; // declaring this variable
userPick = pickOne(); //  stores in variable and calls function.

int computerpickOne= computerPick();  //  stores in variable and calls function.

int player1;
int player2;
battle( player1, player2);  //  stores in variable and calls function.

result(player1,player2);   // calls result function to display

printf("********************************************************\n");
printf("Thank you for playing!\n");

return 0;
}

void greeting(){   // welcome output
    printf("********************************************************\n");
    printf("Welcome to rock paper scissor game!\n");
    printf("Here are the rules.\n");
    printf("You and I will get to choose rock, paper, or scissor.\n");
    printf("After we made a decision we will reveal it and determine the winner based on these rules.\n");
    printf("Rock beats Scissor!\n");
    printf("Paper beats Rocks!\n");
    printf("Scissor beats Paper!\n");
    printf("If we both pick the same option, then it is a tie.\n");
    printf("Ready to play?...Here we go!\n");
    printf("********************************************************\n");
}

int pickOne() {  // 
    int userSelection;

    printf("1---Rock\n");
    printf("2---Paper\n");
    printf("3---Scissor\n");
    printf("Make your selection: \n"); // ask and store user input.
    scanf("%d", &userSelection);
    
    if (userSelection <= 0 || userSelection > 3){ // making sure input is valid
        printf("I'm making my decision now.\n");
        printf("Someone made an invalid choice.\n");
        printf("Choose between 1, 2, and 3.\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        printf("Player 1 has won 0 time(s).\n");
        printf("Player 2 has won 0 time(s).\n");
    return -1;
        
    }
    return userSelection;
}

int computerPick() { // player2 picks random number
    int computerSelection = rand() % 3 + 1;
    printf("I'm making my decision now.\n");
    
    return computerSelection;
}

void playRound(int round) {
    printf("Welcome to a new round %d!\n", round);
    printf("Best out of three...Let's go!\n");
    printf("********************************************************\n");
    printf("Player 1 has won 0 time(s).\n");
    printf("Player 2 has won 0 time(s).\n");
    
    int p1wins = 0;
    int p2wins = 0;
    
    // Play rounds until one player wins three times
    while (p1wins != 3 && p2wins != 3) {
        
        int player1Wins = 0; 
        int player2Wins = 0;
        
        int userChoice = pickOne(); 
        if (userChoice == -1) { // if input invalid skip round
            continue; 
        }
        int computerChoice = computerPick();
        int winner = battle(userChoice, computerChoice);
        
        if (winner == 1) {
            p1wins++;  //  p1wins = p1wins + 1;
        } else if (winner == 2) {
            p2wins++;
        }
        printf("Player 1 has won %d time(s).\n", p1wins);
        printf("Player 2 has won %d time(s).\n", p2wins);
 
    if (p1wins == 3 || p2wins == 3) {
            result(p1wins, p2wins); 
            break; 
        }
    }
}

// Determine the winner of a round
int battle(int player1, int player2) {  

    if (player1 == player2) { // Different Conditions and Scenarios.
        printf("Player1 and Player2 both used ");
        if (player1 == 1) {
            printf("Rock!\n");
        } else if (player1 == 2) {
            printf("Paper!\n");
        } else {
            printf("Scissor!\n");
        }
        printf("Draw!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 0; 
    } 
    else if (player1 == 1 && player2 == 3) {
        printf("Player 1 used Rock and Player 2 used Scissor!\n");
        printf("Rock beats Scissor!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 1;
    }
    else if (player1 == 2 && player2 == 1) {
        printf("Player 1 used Paper and Player 2 used Rock!\n");
        printf("Paper beats Rock!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 1;
    }
    else if (player1 == 3 && player2 == 2) {
        printf("Player 1 used Scissor and Player 2 used Paper!\n");
        printf("Scissor beats Paper!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 1;
    } 
   else if (player2 == 1 && player1 == 3) {
        printf("Player 1 used Scissor and Player 2 used Rock!\n");
        printf("Rock beats Scissor!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 2;
   }
    else if (player2 == 2 && player1 == 1) {
        printf("Player 1 used Rock and Player 2 used Paper!\n");
        printf("Paper beats Rock!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 2;
    }
    else if (player2 == 3 && player1 == 2) {
        printf("Player 1 used Paper and Player 2 used Scissor!\n");
        printf("Scissor beats Paper!\n");
        printf("********************************************************\n");
        printf("********************************************************\n");
        return 2; 
    }
     return 0;
}

void result(int player1, int player2) {    
    if (player1 > player2) {  // display message depends on winner.
        printf("You won! I'll let you have this one.\n");
    } 
    else {
        printf("I won! Haha better luck next time!\n");
    }
}




















