#include "fun.h"

double series(int res, MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance){
    /**
     * @brief Case 1 for known and unknown series resistance values for a resistive circuit
     * 
     */
    if(res == 1){
        //user input
        printf("Enter number of resistors : ");
        scanf("%d",&resistance->number);
        printf(" Do you know the values of the resistors?(1.y/2.n): ");
        scanf("%d",&resistance->days);
        resistance->reactance = 0;
        // calculating resistance values based on user knowledge
        switch(resistance->days){
            // user knows the values
            case 1:   for(int i=0;i<resistance->number;i++){
                            printf("Enter value for resistor[%d] : ",i+1);
                            scanf("%lf",&resistance->array[i]);
                            printf("Enter the power of the units(for example: for kohm enter 3): ");
                            scanf("%lf",&resistance->units);
                            resistance->reactance += (resistance->array[i] * pow(10,(resistance->units)));
                        }
            break;
            //user does not know the values
            case 2:   for(int i=0;i<resistance->number;i++){
                /* Calculate the values based on the resistor bands: 4 and 5 bands */
                            printf(" Enter the number of bands in resistor[%d}: ",i+1);
                            scanf("%lf",&resistance->units);
                            if(resistance->units == 4){
                                resistance->array[i] = reg4band();
                                resistance->reactance += resistance->array[i];
                            }
                            else if(resistance->units == 5){
                                resistance->array[i] = reg5band();
                                resistance->reactance += resistance->array[i];
                            }
                        }
                        break;
            default: printf("Invalid Input, restart the program\n");
            break;
        }
        // Print the total resistance and current values
        printf("Total Series resistance accross the circuit : %0.9lf ohms\n", resistance->reactance);
        Sres = resistance->reactance;
        printf(" Enter the voltage supplied to the circuit to find the current: ");
        scanf("%lf",&resistance->voltage);
        printf("The current (in amperes) throught the circuit is: ");
        return (resistance->voltage/resistance->reactance);
    }
    /**
     * @brief Case 2 series inductance calculation with known inductance values
     * 
     * @return else 
     */
    else if(res == 2){
        //user input
        printf("Enter number of Inductors : ");
        scanf("%d",&inductance->number);
        printf("Enter frequency: ");
        scanf("%lf",&frequency->val);
        printf("Enter the power of the units(for example: for KHz enter 3): ");
        scanf("%lf",&frequency->units);
        printf("\n");
        inductance->reactance = 0;
        for(int i=0;i<inductance->number;i++){
            printf("[%d] : ",i+1);
             printf("Enter Inductance value: ");
            scanf("%lf",&inductance->val);
            printf("Enter the power of the units(for example: for microHenry enter -6): ");
            scanf("%lf",&inductance->units);
            // inductance calculation stored in array then stored in the reactance variable of the structure pointer
            // same process followed for resistor and capacitor
            inductance->array[i] = inductor(frequency->val,inductance->val,frequency->units,inductance->units);
            inductance->reactance += inductance->array[i];
        }
        printf("Total Series Inductance accross the circuit : %0.9lf ohms\n", inductance->reactance);
        Sres = inductance->reactance;
        printf(" Enter the voltage supplied to the circuit to find the current: ");
        scanf("%lf",&inductance->voltage);
        printf("\n");
        printf("The current (in amperes) throught the circuit is: ");
        /**
         * @brief current value returned
         * 
         */
        return (inductance->voltage/inductance->reactance);
    }
    /**
     * @brief Case 3: Capacitor series calculation, formula used will be similar to that of a resistor in paralell
     * 
     * @return else 
     */
    else if(res == 3){
        //user input
        printf("Enter number of Capacitors : ");
        scanf("%d",&capacitance->number);
        printf("\n");
        capacitance->reactance = 0;
        for(int i=0;i<capacitance->number;i++){
            printf("[%d] : ",i+1);
            capacitance->array[i] = capacitor(frequency->val,capacitance->val,frequency->units,capacitance->units);
            capacitance->reactance += 1/(capacitance->array[i]);
        }
        // overall resistance in series
        capacitance->reactance = pow(capacitance->reactance,-1);
        printf("Total Series Capacitance accross the circuit : %0.9lf ohms\n", capacitance->reactance);
        Sres = capacitance->reactance;
        printf(" Enter the voltage supplied to the circuit to find the current: ");
        scanf("%lf",&capacitance->voltage);
        printf("\n");
        printf("The current (in amperes) throught the circuit is: ");
        /**
         * @brief return the current value
         * 
         */
        return (capacitance->voltage/capacitance->reactance);
    }
    else if(res == 4){
        /**
         * @brief Function call for Series RLC circuit value calculation based on the below mentioned input parameters
         * 
         */
        printf("Enter Equivalent Resistance value: ");
        scanf("%lf",&resistance->val);

        printf("Enter the power of the units(for example: for kohm enter 3): ");
        scanf("%lf",&resistance->units);

        printf("Enter Equivalent Inductance value: ");
        scanf("%lf",&inductance->val);

        printf("Enter the power of the units(for example: for microHenry enter -6): ");
        scanf("%lf",&inductance->units);

        printf("Enter Equivalent capacitance value: ");
        scanf("%lf",&capacitance->val);

        printf("Enter the power of the units(for example: for microfarad enter -6): ");
        scanf("%lf",&capacitance->units);

        printf("Enter Equivalent frequency: ");
        scanf("%lf",&frequency->val);

        printf("Enter the power of the units(for example: for KHz enter 3): ");
        scanf("%lf",&frequency->units);

        printf("Enter voltage accross the circuit(enter 0 if you know only current): ");

        scanf("%lf",&resistance->voltage);
    
        printf("\n\n");
        /**
         * @brief return RLC serie current value
         * 
         */
        return RLC(1, inductance, capacitance, frequency, resistance);
    }
    else{
        printf("Invalid Input, restart the program\n");
        return 0;
    }
}    