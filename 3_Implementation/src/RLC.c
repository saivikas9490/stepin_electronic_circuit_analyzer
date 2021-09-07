#include "fun.h"

double RLC(int n, MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance){

    double par,parameter;
    /**
     * @brief all three reactances calculated via input structure pointers and stored in dynamic memory
     * 
     */
    resistance->reactance = resistance->val * pow(10,resistance->units);

    inductance->reactance = 2*pi*inductance->val*frequency->val*pow(10,inductance->units)*pow(10,frequency->units);

    capacitance->reactance = 1/(2*pi*capacitance->val*frequency->val*pow(10,capacitance->units)*pow(10,frequency->units));
    /**
     * @brief Case 1 for calculating series RLC parameters
     * 
     */
    if(n == 1){

        printf("The parameters for Series RLC Connections are as follows: \n\n");

        parameter = sqrt(pow(resistance->reactance,2)*pow((inductance->reactance-capacitance->reactance),2));

        Sres = parameter;

        par = Sres;

        printf("The Impedance is: %0.9lf ohm\n",parameter);

        printf("The power factor of the circuit is: %0.9lf\n", resistance->reactance/Sres);

        printf("The phase angle is: %0.9lf degrees\n", (((acos(resistance->reactance/Sres))*180)/pi));

    }
    /**
     * @brief Case 2 for calculating RLC parallel parameters
     * 
     */
    else{

        parameter = pow((sqrt(pow((1/resistance->reactance),2) + pow(((1/inductance->reactance)-(1/capacitance->reactance)),2))),-1);

        Pres = parameter;

        par = Pres;

        printf("The Impedance is: %0.9lf ohm\n",parameter);

        printf("The power factor of the circuit is: %0.9lf\n", Pres/resistance->reactance);

        printf("The phase angle is: %0.9lf degrees\n", (((acos(Pres/resistance->reactance))*180)/pi));

    }
    /**
     * @brief returning current and voltage values depending on the user
     * 
     */
    
    parameter = resistance->voltage;

    if(parameter != 0){

        printf("The current (in Ampere) in the circuit is: ");

        return parameter/par;
    }
    else{

        printf("Enter the value of Current: ");

        scanf("%lf",&parameter);

        printf("The voltage (in Volts) accross the circuit is: ");

        return parameter * par;
    }
}