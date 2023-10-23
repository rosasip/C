

#include <stdio.h>

void countEvenOdd();  // Function 1 prototype
void drawShape(); // Function 2 prototype
void toyPhone(); // Function 3 prototype
void costPreview(int years, int percentage); // Function 4 prototype

int main() {
    countEvenOdd(); //call problem 1 function
    
    drawShape(); //call problem 2 function
    
    toyPhone(); //call problem 3 function
    
    // Function 4 starts here
    int years;       
    int percentage;

    while (1) {
        printf("Enter the number years to observe: "); 
        scanf("%d", &years); // store years input

        printf("Enter the percentage rate to increase by per year: ");
        scanf("%d", &percentage); // store percentage input

        if (years <= 0 || percentage <= 0) {
            printf("Invalid input.\n");
            continue; //keeps going when input invalid
        } 
        else {
            costPreview(years, percentage);
            break; //exit loop
        }
    }

    return 0; 
}

// Problem 1 Starts here
void countEvenOdd() {
    int num; // Declare variable that store input
    int evenNum = 0; // Initialize even numbers count
    int oddNum = 0; // Initialize odd numbers count
    int evenSum = 0; // Initialize even numbers sum count
    int oddSum = 0; // Initialize odd numbers sum count

    while (1) { // infinite loop but breaks
        printf("Enter a positive integer: "); // Prompt the user for input
        scanf("%d", &num); // store input in 'num'

        if (num < 0) { // Check for negative input
            printf("That's a negative number!\n"); 
            continue; 
        }
        if (num == 0) { // Check if input is zero
            break; // Exit the loop
        }
        if (num % 2 == 0) { // Check if input is even
            evenNum++; // Increment count of even numbers
            evenSum += num; // Add even number to sum 
        } 
        else { 
            oddNum++; // Increment odd numbers count
            oddSum += num; // Add odd num to sum 
        }
    }
    if (evenNum > 0) { 
        double evenTotal = (double) evenSum / evenNum; //  calculation with different scenario
        printf("%d even numbers were entered and the average is %.6lf\n", evenNum, evenTotal);
    } 
    else {
        printf("0 even numbers were entered and the average is 0.000000\n");
    }
    if (oddNum > 0) {
        double oddTotal = (double) oddSum / oddNum; //  calculation with different scenario
        printf("%d odd numbers were entered and the average is %.6lf\n", oddNum, oddTotal);
    } 
    else {
        printf("0 odd numbers were entered and the average is 0.000000\n");
    }
}

// Problem 2 Starts here
void drawShape() {
    int numRows;

    while (1) {
        printf("How many rows would you like the shape to have?: ");
        scanf("%d", &numRows); // collect input from user

        if (numRows <= 0) {
            printf("Invalid Input. Please try again.\n");
            continue; // keeps going
        }
        for (int currentRow = 1; currentRow <= numRows; currentRow++) {
            for (int currentColumn = 1; currentColumn <= numRows; currentColumn++) { // nested for loop with conditions
                if (currentRow == 1 || currentRow == numRows || currentColumn == 1 || currentColumn == numRows || currentRow == currentColumn ) {
                    printf("*"); // print this according to condition
                } 
                else {
                    printf(" ");
                }
            }
            printf("\n"); // new line after each row
        }
        break;
    }
}

// Problem 3 Starts here
void toyPhone() {
     int button;
    
    printf("Welcome to the Toy Phone!\n"); // output this message

    while (1) {
        printf("Enter a button: ");
        scanf("%d", &button); // collects user input 
        
        // conditions based on user button input
        if (button == 1) { 
            printf("Hello!\n");
        } else if (button == 2) {
            printf("Loopy Loops!\n");
        } else if (button == 3) {
            printf("Programming is fun!\n");
        } else if (button == 4) {
            printf("Semicolons can be a pain to forget!\n");
        } else if (button == 5) {
            printf("Are you ready for pointers?\n");
        } else if (button == 6) {
            printf("Goodbye!\n");
            break; // exit loop when 6 chosen
        } else {         // if 1-6 not inputted 'invalid'
            printf("Invalid option.\n");
            continue; 
        }
    }
}

// Problem 4 starts here
void costPreview(int years, int percentage) {
    double currentTuition = 20000.00; // The initial tuition cost.

    printf("Current Tuition: $%.2lf\n", currentTuition); // shows current tuition cost.

     for (int year = 1; year <= years; year++) {
        double tuitionIncrease = currentTuition * (percentage / 100.0); // calculate tuition
        currentTuition += tuitionIncrease;  // Update current year tuition cost.
        printf("Year %d: $%.2lf\n", year, currentTuition); // output current year tuition cost.
    }
}