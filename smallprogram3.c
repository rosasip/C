

#include <stdio.h>  // preprocessor directive
#include <math.h>

int creditCheck(double itemPrice);  // Function #1 prototype
void universityAdmission(double gradeAverage, int admissionScore); // Function #2 prototype
void keyPad (); // Function #3 prototype

int baseCharge = 30; // Problem 4  starts here
char oakInput;
int charInput;
char goldLeafInput;
double totalCost;

double carpenter();   // Funtion 4 prototype 

int main()
{
    double itemPrice; // Problem #1 starts here
    printf("Enter the price: "); 
    scanf("%lf", &itemPrice);  // collect price input 
    int result = creditCheck(itemPrice); // calls and store function

    double gradeAverage;  // Problem #2 starts here
    int admissionScore; 

    printf("Welcome to the University Admission System!\n");
    printf("Enter the GPA: ");
    scanf("%lf", &gradeAverage);
    printf("Enter the test score: ");
    scanf("%d", &admissionScore);  

    universityAdmission(gradeAverage, admissionScore); // Calls #2 function 

    keyPad(); // Calls function #3

    printf("Welcome to Bruce's Carpentry Services!\n"); // problem 4 output
    double chargePrice = carpenter();   // calls function 4
           
    return 0;
}
 // Problem #1 Function 
int creditCheck(double itemPrice)
{
    int creditLimit = 9000;
    
    if (itemPrice < 0){
    printf("Error!\n"); // for negative price display error
    } 
    else if (itemPrice <= creditLimit){
    printf("Approved!\n"); // if price is within credit limit
    }
    else {
    printf("Not Approved!\n");
    }
    return 0;
}
// Problem #2 Function
void universityAdmission(double gradeAverage, int admissionScore) {
    if ((gradeAverage < 0 || gradeAverage > 4.0) || (admissionScore < 0)) {
        printf("Invalid Input!\n");
    } 
    else if (gradeAverage >= 3.00 && admissionScore >= 60) { // checks GPA and admission score.
        printf("Admissions is Approved!\n");
        if (gradeAverage >= 3.50 && admissionScore >= 70) { // checks if approved for scholarships
            printf("Consider for Scholarship Award!\n");
        }
    } 
    else if (gradeAverage >= 2.00 && admissionScore >= 80) {
        printf("Admissions is Approved!\n");
    } 
    else {
        printf("Admissions is Denied!\n"); 
    }
}

// Function Problem #3 starts here
void keyPad (){    
    int optionInput;  
    
    printf("Welcome to the Crazy Keypad!\n");
    printf("Select one of the following options for a message.\n");
    printf("Option 1\n");
    printf("Option 2\n");
    printf("Option 3\n");
    printf("Option 4\n");
    printf("Option 5\n");
    printf("Option Selected: ");
    scanf("%d", &optionInput); // collects the input
    
    if (optionInput== 1)  // option chosen input by user
        printf("Opening Vault 712...\n"); // display reponse for user input
    else if (optionInput== 2)
        printf("Opening Secret Elevator...\n");
    else if (optionInput== 3)
        printf("Calling the Boss...\n");
    else if (optionInput== 4)
        printf("Backup on the way...\n");
    else if (optionInput== 5)
        printf("Alarm activated...\n");
    else 
        printf("System Locked...\n");
}

// Function Problem #4 starts here
double carpenter() {
    
totalCost = baseCharge;    // Initialize totalCost with base charge

printf("Would you like the sign made out of oak?\n");
    printf("Enter y for yes or n for no: "); 
    scanf(" %c", &oakInput); // collects input
    if (oakInput == 'y' || oakInput == 'Y') {
        totalCost += 15.0;  // Add oak cost if chosen
    }                         
    else if (oakInput != 'n' && oakInput != 'N') {
        printf("Could not compute cost...");
        return -1;
    }
    printf("Enter the number of characters on the sign: ");
    scanf("%d", &charInput);
    if (charInput<0) {  
        printf("Could not compute cost...");   // prints if negative
        return -1; 
    } 
    else if (charInput > 5) {
        totalCost += 2 * (charInput - 5); // Add character cost 
    }
    printf("Would you like gold-leaf lettering?\n"); // Prompts for input
    printf("Enter y for yes or n for no: ");
    scanf(" %c", &goldLeafInput);
    if (goldLeafInput == 'y' || goldLeafInput == 'Y') {
        totalCost += 12.0; // Add gold-leaf cost if chosen
    } 
    else if (goldLeafInput != 'n' && goldLeafInput != 'N') {
        printf("Could not compute cost...");
        return -1; 
    }
    if (totalCost >= 0) {
        printf("Bruce will charge $%.2lf.", totalCost); // Display total cost

    return totalCost; // Return calculated total cost
    }
}

