#include "fun.h"

double powerAndLife(MainMenu *battery, int check){
    double hours,days;
    /**
     * @brief current calculation using pointers as arguments from the structure typedef globally
     * 
     */
    battery->current = (battery->voltage)/(battery->reactance * pow(10,battery->units));

    printf("The current in the circuit is: %0.9lf",battery->current);
    printf("\n");

// Function to calculate lifetime operation and time of battery death
    switch(check){

        case 1: printf("Enter the battery power rating (in AH): ");
                scanf("%lf",&battery->val);

                printf("Enter the total time(in hours) the circuit will be on in a day: ");
                scanf("%lf",&hours);

                printf("Enter (approx) number of times it will be used in a day (Enter 1 if it will stay on 24*7): ");
                scanf("%lf",&days);

                printf("\n\n");
                // The system returns the number of days accurately
                printf("The circuit will run for: %0.9lf days\n",(battery->units)/(hours * days * battery->current));

                return ((pow(battery->current,2))*(battery->reactance * pow(10,battery->units)));
                break;

        case 2: return ((pow(battery->current,2))*(battery->reactance * pow(10,battery->units)));

        default: printf("Invalid Input, restart the program\n");

        break;
    }
}