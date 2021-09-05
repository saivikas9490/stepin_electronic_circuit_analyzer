#include "fun.h"
    
double paralell(int res, MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance){
    /**
     * @brief Case 1: For a parallel resistance circuit with known and unknown resistance values
     * 
     */
    if(res == 1){
        // Total number of resistors used in the config
        printf("Enter the number of resistors : ");
        scanf("%d",&resistance->number);

        printf(" Do you know the values of the resistors?(1.y/2.n): ");
        scanf("%d",&resistance->days);

        resistance->reactance = 0;

        switch(resistance->days){
            /**
             * @brief Case 1: for known resistance values
             * 
             */
            case 1:   for(int i=0;i<resistance->number;i++){
                            printf("Enter value for resistor[%d] : ",i+1);
                            scanf("%lf",&resistance->array[i]);
                            printf("Enter  power of the units(for example: for kohm enter 3): ");
                            scanf("%lf",&resistance->units);
                            // saving reactance values as per the formulas
                            resistance->reactance += 1/(resistance->array[i]*pow(10,resistance->units));
                        }
                        break;
            /**
             * @brief Case 2: for unknown resistance values
             * 
             */
            case 2:   for(int i=0;i<resistance->number;i++){
                            printf(" Enter the number of bands in resistor[%d}: ",i+1);
                            scanf("%lf",&resistance->units);
                            /**
                             * @brief saving resistance values in array and then converting those values to the double type
                             * 
                             */
                            if(resistance->units == 4){

                                resistance->array[i] = reg4band();
                                resistance->reactance += 1/(resistance->array[i]);

                            }
                            else if(resistance->units == 5){

                                resistance->array[i] = reg5band();
                                resistance->reactance += 1/(resistance->array[i]);

                            }
                        }
                        break;
            default: printf("Invalid Input, restart the program\n");
            break;
        }
        //formula for parallel resistance calculation
        resistance->reactance = pow(resistance->reactance,-1);

        printf("Total Series resistance accross the circuit : %0.9lf ohms\n", resistance->reactance);
        Sres = resistance->reactance;

        printf(" Enter the voltage supplied to the circuit to find the current: ");
        scanf("%lf",&resistance->voltage);

        printf("The current (in amperes) throught the circuit is: ");
        /**
         * @brief return the current value
         * 
         */
        return (resistance->voltage/resistance->reactance);
    }
    /**
     * @brief For inductance values
     * 
     * @return else 
     */
    else if(res == 2){
        printf("Enter number of Inductors : ");
        scanf("%d",&inductance->number);

        printf("Enter frequency: ");
        scanf("%lf",&frequency->val);

        printf("Enter the power of the units(for example: for KHz enter 3): ");
        scanf("%lf",&frequency->units);

        printf("\n");

        inductance->reactance = 0;
        // taking user input
        for(int i=0;i<inductance->number;i++){

            printf("[%d] : ",i+1);

            printf("Enter Inductance value: ");
            scanf("%lf",&inductance->val);

            printf("Enter the power of the units(for example: for microHenry enter -6): ");
            scanf("%lf",&inductance->units);

            inductance->array[i] = inductor(frequency->val,inductance->val,frequency->units,inductance->units);

            inductance->reactance += 1/(inductance->array[i]);
            //storing inductance values
        }
        inductance->reactance = pow(inductance->reactance,-1);

        printf("Total Series Inductance accross the circuit : %0.9lf ohms\n", inductance->reactance);
        Sres = inductance->reactance;

        printf(" Enter the voltage supplied to the circuit to find the current: ");
        scanf("%lf",&inductance->voltage);

        printf("\n");

        printf("The current (in amperes) throught the circuit is: ");
        /**
         * @brief return the output current value
         * 
         */
        return (inductance->voltage/inductance->reactance);
    }
    /**
     * @brief for capacitive circuits
     * 
     * @return else 
     */
    else if(res == 3){
        printf("Enter number of Capacitors : ");
        scanf("%d",&capacitance->number);

        printf("\n");

        capacitance->reactance = 0;

        for(int i=0;i<capacitance->number;i++){
            printf("[%d] : ",i+1);

            capacitance->array[i] = capacitor(frequency->val,capacitance->val,frequency->units,capacitance->units);

            capacitance->reactance += capacitance->array[i];
        }

        printf("Total Series Capacitance accross the circuit : %0.9lf ohms\n", capacitance->reactance);

        Sres = capacitance->reactance;

        printf(" Enter the voltage supplied to the circuit to find the current: ");
        scanf("%lf",&capacitance->voltage);

        printf("\n");
        /**
         * @brief return output capacitive current
         * 
         */
        printf("The current (in amperes) throught the circuit is: ");
        return (capacitance->voltage/capacitance->reactance);

    }
    else if(res == 4){
        /**
         * @brief inputs for series RLC circuit and function call
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
    
        printf("\n\n");

        return RLC(2, inductance, capacitance, frequency, resistance);  ;
    }
    else{
        printf("Invalid Input, restart the program\n");
        return 0;
    }
}    