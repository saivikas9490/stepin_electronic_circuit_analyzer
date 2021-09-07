/**
 * @file fun.h
 * @author  saivikas9490
 * @brief Header file for the project containing all the function definitions
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __FUN_H__
#define __FUN_H__

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/**
 * @brief global variables for the whole program to access
 * 
 */
double Sres;
/**
 * @brief Structure initialization for all the function using common object pointers
 * 
 */
typedef struct MainMenu{
    int number,days;
    double val,units,voltage,current,array[100],reactance,days1,number1;

}MainMenu;
/**
 * @brief global variable for parallel resistance calculation
 * 
 */
double Pres;
/**
 * @brief funtions to identify the resistor values based on the color codes, 4 band
 * 
 * @return double 
 */
double reg4band();
/**
 * @brief funtions to identify the resistor values based on the color codes, 5 band
 * 
 * @return double 
 */
double reg5band();
/**
 * @brief This function defines the formula to find the capacitance for the given values
 * 
 * @param fval - gives the frequency value
 * @param cval - gives the capacitor value
 * @param funits - gives the frequency units (KHz, MHz etc in the form of digits)
 * @param cunits - gives the capacitance units (uF, pF etc in the form of digits)
 * @return double - returns the resultant capacitive reactance value
 */
double capacitor(double fval, double cval, double funits, double cunits);
/**
 * @brief This function defines the formula to find the inductance for the given values
 * 
 * @param fval - gives the frequency value
 * @param cval - gives the inductor value
 * @param funits - gives the frequency units (KHz, MHz etc in the form of digits)
 * @param cunits - gives the inductance units (mH, uH etc in the form of digits)
 * @return double - returns the resultant inductive reactance value
 */
double inductor(double fval, double ival, double funits, double iunits);
/**
 * @brief This function defines the formula to find the RLC series/arallel circuit values for the given values of components
 * 
 * @param n - to determine series or parallel
 * @param inductance - for inductance calculation
 * @param capacitance - for capacitance calculation
 * @param frequency - for frequency calculation
 * @param resistance - for resistance calculation
 * @return double - to return the current value
 */
double RLC(int n, MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance);
/**
 * @brief This function defines the formula to find the series resistance of a given circuit for the given values of the components
 * 
 * @param res - to determine resistive, inductive or capacitive
 * @param inductance - for inductance calculation
 * @param capacitance - for capacitance calculation
 * @param frequency - for frequency calculation
 * @param resistance - for resistance calculation
 * @return double - to return the current value
 */
double series(int res, MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance);
/**
 * @brief This function defines the formula to find the parallel resistance of a given circuit for the given values of the components
 * 
 * @param res - to determine resistive, inductive or capacitive
 * @param inductance - for inductance calculation
 * @param capacitance - for capacitance calculation
 * @param frequency - for frequency calculation
 * @param resistance - for resistance calculation
 * @return double - to return the current value
 */
double paralell(int res, MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance);
/**
 * @brief function to calculate the power and lifetime of the circuit
 * 
 * @param battery - battery function pointer
 * @param check - if the personwants to know the number of days te device will work 
 */
double powerAndLife(MainMenu *battery, int check);
/**
 * @brief To find the types of batteries to be used in a circuit as per the arguent conditions
 * 
 * @param R - for rechargeable or non-rechargeable batteries
 * @param voltage - for voltage calculations
 * @param current - for current calculations
 * @param days - to calculate how many days will the battery last
 * @param times - to calculate how many times in a day will the circuit be used and battery consumed
 * @return double - returns power rating of the battery
 */
double battery_data(int R, double voltage, double current, double days, double times);
/**
 * @brief global variable pi for calculations
 * 
 */
#define pi 3.14159265
/**
 * @brief end of file
 * 
 */
#endif  /* __FUN_H__  */