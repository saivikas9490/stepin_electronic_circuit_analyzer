# Requirements
## Introduction
*   Electronic circuit analyzer: The following application will be able to help any electronics engineer to analyse and find the various variables and problems when it comes to circuits. It will be able to do the following :
        1.  Calculate the resistance of individual components and the resistance of the circuit: a) Series b) parallel
        2.  Calculate the overall current in the circuit and the voltage through the components mentioned
        3.  Calculate the impedance based on the type of circuit
        4.  Calculate the power consumed by the whole circuit.

## Research
*   Being an electronics engineer myself, as a student while making projects, it used to be a very tedious task for me especially during handling hardware circuits to balance the resistance and voltage accross the circuit and keep the resistance and current on the overall circuit in check. The main problems occured when the resistances were too many and the calculations differed as per the values in series and paralell. For any electronics engineer, the overalll resistance in the circuit, impedance in RLC and power calculations for the circuit to determine how long will it work for in real time were the major tasks. So, in order to shorten the calculation time and make the process automated and without human-made errors, the following system has been designed. An electronic circuit analyzer is helpful for all who are doing anything with hardware electronic or electrical circuits. It helps in determining the resistor values based on the color codes, helps determining system current based on its series or paralell architecture and also helps in calculating the overall power of the circuit and how long will the circuit work on a given impedance.
*   There exist various applications on the playstore that help you calculate the resistor values based on the color codes, some that help you calculate the current in the circuit and analyze the circuit based on the voltage and current parameters. But this system has integrated all the funstions into one single program and brings you all the basic requirements of circuit analysis into one single, unified system.

### Benefits
The system has the following benefits:
#### Easy and accurate calculations for the people using basic electronic circuits
*   It has often been seen that in circuits involving more than 10 resistors for a configuration as simple as series, human errors are bound to occur even while adding. This system solves that problems and gets the solution to the user in seconds.
#### Very usefull for beginners
*   People who are just starting their college or even in high school, this project is helpfull for all to understand and calculate the basic resistor values, impedance and reactance calculations and also helps them calculate the current and power of basic electronic circuits.
#### Power calculations
*   For electronic engineers, their projects are majorly dependent on the power calculations and how long will the circuit last in practical applications based on the amount of power spplied. This project also calculated the lifetime of the project based on the used inputs. 

## Cost and Functions
    * Considering the evolution of electronic circuits, the measurement parameters have varying costs and they have always been on a higher scale. For example, the multimeter device that is used to measure the curent and voltage parameters costs around Rs. 1000. This systems gets all the integrated functions as mentioned in the table below for very less cost and accuracy is maintained as well. 
    |Feature | Description
    |--------| -----------------------------------------
    |`F1`    | Gives the resistor values based on the color codes
    |`F2`    | GIves the reactance values for capacitor and inductor based on the inputs
    |`F3`    | Gives battery information based on curent input, voltage and circuit type and usage
    |`F4`    | GIves analysis and output for the following types of circuits: 1) Series 2) parallel 3) RLC (resistive, capacitive and inductive all together)
    |`F5`    | Gives the power consumption data of a device and also based on the input predicts how long will the device last

    This system is very cost effective when compared to various other apps because this system integrates all the factors that are present in multiple apps into one and also can interlink and use all these functions after the other.

## Defining Our System
*   The Electronic Circuit Analyzer can perform the following actions:
         1. Provide information on the following:
            a) Resistor values based on the color codes
            b) Impedance and reactance values for one or many components
            c) Battery power consumption information based on the battery type.
         2. Circuit analysis:
            a) Series Circuit analysis - resistance, current, voltage accross individual components
            b) Paralell circuit analysis - resistance, current, voltage accross individual components
            c) Power and lifetime analysis of the whole circuit.

## SWOT ANALYSIS

## Who

    1. All students in high school or college level trying to use electronic circuitory.
    2. All Electronic engineers for power and complex calculations

## What

    Many students face problems while connecting circuits in paralell and calculations become complex when the circuit goes over 10 components in series or paralell. Also, power calculations play a vital role in every project which will be automated by this system to give exact number of days the project will work.

## When

    There is no when for this project as it can be used by generations for centuries untill we need hardware technology in this world. This project will be used for all hardware siulations and resistor coding informations.

## Where

    Engineering institutions, electrical projects, schools, Project development and many more.

## How

    The usage of this project is very simeple as it is an input output application. The user just needs to type in whatever he or she needs for example, if he or she needs to know the current in a particular branch in the circuit, the circuit information has to be provided and the output will be given based on all the modern calculations.

## High Level Requirements
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HLR01 | User will be able to identify the resistor values based on the color code input | Technical | TBD |
| HLR02 | User will be able to identify the impedance and reactance based on the capacitance and inductance values for the circuit | Technical | TBD |
| HLR03 | User will be able to identify the typeof battery, current output, voltage output, power rating of the battery based on the input | Informative | TBD |
| HLR04 | User will be able to calculate the series resistance of a circuit, voltage and current accross the circuit and accross each component | Technical | TBD |
| HLR05 | User will be able to calculate the parallel resistance of a circuit, voltage and current accross the circuit and accross each component | Technical | TBD |
| HLR06 | User will be able to identify the current, voltage, power of the whole circuit | Technical | TBD |
| HLR07 | User will be able to identify the overall resistance/impedance/admittance/reactance of a mixed series/paralell/RLC circuit based on the inputs | Technical | FUTURE |
| HLR08 | User will be able to identify the circuit life in days based on the input battery and power rating | Technical | TBD |

## Low level Requirements
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| LLR01 | The values of the resistor will be displayed based on the type of resistor - 4 band or 5 band | HLR01 | TBD |
| LLR02 | The first three color bands will be used for a 4 band and the first 4 bands will be used for a 5 band | HLR01 | TBD |
| LLR03 | The impedance/admittance/reactance values will be calculated based on given formulas and user input | HLR02 | TBD |
| LLR04 | A dataset will be created for different types of batteries to be used in basic electronic circuits and the same will be provided to the user based on the input battery id | HLR03 | TBD |
| LLR05 | The total series resistance based on the user input will be provided. If the user does not know the resistor values, an intermedicate function will provide the same by asking the color codes | HLR04 | TBD |
| LLR06 | Based on the total series resistance, the total voltage/current accross the circuit/each element f the circuit will be provided according to the user input in the form of resistor values for individual or the whole circuit | HLR04 | TBD |
| LLR07 | The total parallel resistance based on the user input will be provided. If the user does not know the resistor values, an intermedicate function will provide the same by asking the color codes | HLR05 | TBD |
| LLR08 | Based on the total parallel resistance, the total voltage/current accross the circuit/each element f the circuit will be provided according to the user input in the form of resistor values for individual or the whole circuit | HLR05 | TBD |
| LLR09 | Based on resistor value inputs, series/paralell/mixed(optional) selections by the user, the total voltage/current will be calculated for the circuit and the output power of the circuit will be provided | HLR06 | TBD |
| LLR10 | The circuit lfe of the input circuit will be given based on past data of battery life and calculating based on the battery type and current pull of the circuit given by the user | HLR08 | TBD |
