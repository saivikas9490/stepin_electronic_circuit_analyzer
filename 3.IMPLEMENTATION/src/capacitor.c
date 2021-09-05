#include "fun.h"
#include<math.h>
/**
 * @brief This function defines the formula to find the capacitance for the given values
 * 
 * @param fval - gives the frequency value
 * @param cval - gives the capacitor value
 * @param funits - gives the frequency units (KHz, MHz etc in the form of digits)
 * @param cunits - gives the capacitance units (uF, pF etc in the form of digits)
 * @return double - returns the resultant capacitive reactance value
 */
double capacitor(double fval, double cval, double funits, double cunits){
    double value = (1/(2*pi*fval*cval))*(1/(pow(10,funits)*pow(10,cunits)));    //formula practically validated
    return value;
}
// edit