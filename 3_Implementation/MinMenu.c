#include "fun.h"

int main(){
    MainMenu *frequency, *capacitance, *inductance, *battery, *resistance, freq, res, induc, cap, bat;
    frequency = &freq;
    capacitance = &cap;
    inductance = &induc;
    resistance = &res;
    battery = &bat;
    int level1;
    printf("***                 Electronic Circuit Analyzer             ***\n\n");
    printf("    Select which option you want to choose from the following: \n\n");
    printf("    1. Information about cicuit devices\n");
    printf("    2. Circuit peripheral calculations\n\n");

    printf("    Please Enter Your Choice: ");
    scanf("%d",&level1);

    switch(level1){
        case 1: printf(" Out of the following information, what do you want to know?\n\n");
                printf(" 1. Resistor color codes\n");
                printf(" 2. Reactance of the circuit component\n");
                printf(" 3. Battery and charging information\n\n");

                printf(" Please enter your choice here: ");
                scanf("%d", &level1);

                switch(level1){
                    case 1: printf(" What type of resistor band do you have?\n\n");
                            printf(" 1. 4 band resistor\n");
                            printf(" 2. 5 band resistor\n");

                            printf(" Enter your choice here: ");
                            scanf("%d",&level1);

                            switch(level1){
                                case 1: printf("The value of the Resistor is: %0.3lf ohms\n",reg4band());

                                break;

                                case 2: printf("The value of the resistor is: %0.3lf ohms\n",reg5band());

                                break;

                                default: printf("Invalid input, please restart the program\n");

                                break;
                            }
                    break;

                    case 2: printf(" Which circuit component do you have?\n\n");
                            printf(" 1. Capacitor\n");
                            printf(" 2. Inductor\n");

                            printf(" Enter your choice here: ");
                            scanf("%d",&level1);

                            switch(level1){
                                case 1: printf("Enter capacitance: ");
                                        scanf("%lf",&capacitance->val);

                                        printf("Enter the power of the units(for example: for microfarad enter -6): ");
                                        scanf("%lf",&capacitance->units);

                                        printf("Enter frequency: ");
                                        scanf("%lf",&frequency->val);

                                        printf("Enter the power of the units(for example: for KHz enter 3): ");
                                        scanf("%lf",&frequency->units);

                                        printf("The Reactance of the capacitor is: %0.3lf Ohms\n", capacitor(frequency->val,capacitance->val,frequency->units,capacitance->units));
                                break;
                                case 2: printf("Enter Inductance value: ");
                                        scanf("%lf",&inductance->val);

                                        printf("Enter the power of the units(for example: for microHenry enter -6): ");
                                        scanf("%lf",&inductance->units);

                                        printf("Enter frequency: ");
                                        scanf("%lf",&frequency->val);

                                        printf("Enter the power of the units(for example: for KHz enter 3): ");
                                        scanf("%lf",&frequency->units);

                                        printf("The Reactance of the inductor is: %0.3lf Ohms\n", inductor(frequency->val,inductance->val,frequency->units,inductance->units));
                                
                                break;

                                default: printf("Invalid input, please restart the program\n");

                                break;
                            }
                    break;

                    case 3: printf("Disclaimer: The battery data shown is only for the batteries allowed to use in normal circuits.\n");
                            printf("Major and high power batteries are not included in this program.\n\n");
                            printf("WHat type of battery do you want?: 1. Rechargeable  2. Non-Rechargeable\n");

                            printf("Enter your choice: ");
                            scanf("%d",&level1);

                            printf("Enter voltage to be provided by the battery: ");
                            scanf("%lf",&(battery->voltage));

                            printf("Enter the number of hours per day you want the device to work: ");
                            scanf("%lf",&battery->days1);

                            printf("Enter the number of times per day the device will be used: ");
                            scanf("%lf",&battery->number1);

                            printf("Enter the minimum current drawn by the entire circuit in Amps(example: 10mA = 0.01): ");
                            scanf("%lf",&battery->current);

                            printf("\n");            
                            printf("The power rating of the battery is %lf AH\n",battery_data(level1, battery->voltage, battery->current, battery->days1, battery->number1));

                    break;

                    default: printf("Invalid input, please restart the program\n");

                    break;
                }
        break;

        case 2: printf(" Which of the following circuit peripherals do you want to calculate?\n\n");
                printf(" 1. Series circuit with Voltage\n");
                printf(" 2. Paralell circuit with current\n");
                printf(" 3. Power calculation for the circuit and lifetime of the circuit\n");

                printf(" Enter your choice here: ");
                scanf("%d",&level1);

                switch(level1){
                    case 1: printf(" Which series circuit would you like to go for? \n\n");
                            printf(" 1. Series Resistors\n");
                            printf(" 2. Series Inductors\n");
                            printf(" 3. Series Capacitors\n");
                            printf(" 4. Series RLC\n");

                            printf(" Enter your choice: ");
                            scanf("%d",&level1);

                            printf("%0.9lf\n",series(level1, inductance, capacitance, frequency, resistance));

                    break;

                    case 2: printf(" Which parallel circuit would you like to go for? \n\n");
                            printf(" 1. Parallel Resistors\n");
                            printf(" 2. Parallel Inductors\n");
                            printf(" 3. Parallel Capacitors\n");
                            printf(" 4. Parallel RLC\n");

                            printf(" Enter your choice: ");
                            scanf("%d",&level1);

                            printf("%0.9lf\n", paralell(level1, inductance, capacitance, frequency, resistance));

                    break;

                    case 3:     printf("\n\n");

                                printf("Enter the voltage supplied to the whole circuit (irrespective of the type): ");
                                scanf("%lf",&battery->voltage);

                                printf("Enter value of the overall resistance in the circuit: ");
                                scanf("%lf",&battery->reactance);

                                printf("Enter the power of the units(for example: for kohm enter 3): ");
                                scanf("%d",&battery->units);

                                printf("\n");
                                printf("Do you want to know the lifetime operation of your circuit?(1. yes/2. No): ");
                                scanf("%d",&level1);

                                printf("Total power in the circuit is: %lf Watts",powerAndLife(battery,level1));

                    break;

                    default: printf("Invalid input, please restart the program\n");

                    break;
                }

        break;

        default: printf("Invalide input, restart the program");

        break;
    }
}
