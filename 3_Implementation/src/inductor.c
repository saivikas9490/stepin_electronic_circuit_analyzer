#include "fun.h"
#include<math.h>
/**
 * @brief This function defines the formula to find the inductance for the given values
 * 
 * @param fval - gives the frequency value
 * @param cval - gives the inductor value
 * @param funits - gives the frequency units (KHz, MHz etc in the form of digits)
 * @param cunits - gives the inductance units (mH, uH etc in the form of digits)
 * @return double - returns the resultant inductive reactance value
 */
double inductor(double fval, double ival, double funits, double iunits){
    double value = (2*pi*ival*fval)*pow(10,iunits)*pow(10,funits);      //frmula validated practically
    return value;
}