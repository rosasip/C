

#include <stdio.h>  // preprocessor directive
#include <math.h>
#define c sqrt(a*a + b*b) // macro 

//prototypes for problem 1 .
double a;
double b;
double calcHypotenuse( double a,  double b);  

// prototypes for problem 2 . 
int numDays;
double teslaPrice = 46.48;
double chevroletPrice = 49.53;
double nissanPrice = 50.72;
void rentalPrices(); 

// Prototypes for problem 3.
int seconds ;
int hoursDisplay ;
int minutesDisplay ;
int secondsDiplay;
void timeDisplay(int seconds);

// Prototypes for problem 4.
int n;
double mathFunction( int n);

int main() 
{
    //Problem 1.
    printf("Enter the value for a: ");
    scanf("%lf", &a);
    printf("Enter the value for b: ");
    scanf("%lf", &b);
    
    double result1 = calcHypotenuse(a, b);  // Calls and store function 1.
 
    // Problem 2 
    printf("Hello Luis!\n");
    printf("Thank you for considering Hertz for your car rental needs.\n");
    printf("You have asked to compare prices for three vehicles.\n");
    printf("Please enter the number of days you plan to rent the vehicle: "); // Ask user for input
    scanf("%d", &numDays); 
    printf("Here are the prices excluding tax.\n"); 
    
    rentalPrices();  // Calls function 2.

    // Problem 3
    printf("Enter the seconds: ");
    scanf("%d",&seconds);
    timeDisplay( seconds);  // calls out function.

    // Problem 4
    printf("Enter the value for n: ");
    scanf("%d", &n);
   
    double result2 = mathFunction(n); // Calls function

    return 0; 
}

// Function 1 starts here.
double calcHypotenuse( double a,  double b) 
{
    printf("If a = %.3lf and b = %.3lf, then that means the hypotenuse is %.3lf.\n", a, b, c); // output calculations to user
    return c; // Return the hypotenuse value.
}

// Function 2 starts here.
void rentalPrices()
{
  double totalTeslaPrice = teslaPrice * numDays;  // calculations for tesla total price
  double totalChevroletPrice = chevroletPrice * numDays ;
  double totalNissanPrice =  nissanPrice * numDays;

  printf("Tesla Model 3 Standard Range: $%.2lf\n",totalTeslaPrice ); // output tesla total price.
  printf("Chevrolet Malibu: $%.2lf\n",totalChevroletPrice );
  printf("Nissan Rogue: $%.2lf\n", totalNissanPrice); 

 }

 // Function 3 starts here.
void timeDisplay(int seconds)
{
    int day = 86400;  //seconds in a day
    int hours = 3600;  // 86400 seconds divided 24 hours 
    int minutes = 60;
    
    int hoursDisplay = seconds / hours;
    int secondsLeft = seconds % hours;    // remainder of the hours calculated.
    int minutesDisplay =  secondsLeft / 60;
    int secondsDiplay =  secondsLeft  % 60;

   printf("%d seconds is %d hours, %d minutes, and %d seconds.\n", seconds, hoursDisplay, minutesDisplay, secondsDiplay );
}

// Function 4 starts here.
double mathFunction( int n)
{
    double step1 = pow(n, n)-pow (2, n);
    double step2 = sqrt(n) * pow (n, 4);
    double step3 = exp(n - 2) + 9;
    double step4 = 8 * n;
    double num = step1/ (step2/step3) - step4;
    
    printf("The function computes the value %.3lf.", num);
    
    return (num); 

}