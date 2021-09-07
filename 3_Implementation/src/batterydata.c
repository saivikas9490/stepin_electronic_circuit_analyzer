#include "fun.h"
#include<math.h>
/**
 * @brief To find the types of batteries to be used in a circuit as per the arguent conditions
 * 
 * @param R - for rechargeable or non-rechargeable batteries
 * @param voltage - for voltage calculations
 * @param current - for current calculations
 * @param days - to calculate how many days will the battery last
 * @param times - to calculate how many times in a day will the circuit be used and battery consumed
 * @return double - power rating of the battery returned
 */
double battery_data(int R, double voltage, double current, double days, double number){
    double powerRating = (days*number*current);
    /**
     * @brief Construct a new if object in case of rechargeable and non rechargeable battery types denoted by R
     * 
     */
    if(R == 1){
        /**
         * @brief Construct a new if object depending on voltage for Rechargeable battery (part 1)
         * 
         */
        if(voltage == 9){
            if(powerRating <= 0.2 && current<=0.01){
                printf("Use a Lithium Coin Cell - Voltage = 3V * 3 (in series), Power Rating = 200mAH\n");
            }
            else if(powerRating <= 0.5 && current <= 0.03){
                printf("Use a 9V PPS battery - Voltage = 9V, Power Rating = 500mAH\n");
            }
            else if(powerRating <= 1 && current<=0.01){
                printf("Use series combination of Alkaline AAA batteries - Voltage = 1.5V * 6, power Rating = 1000mAH\n");
            }
            else if(powerRating <= 2.5 && current<=0.05){
                printf("Use series combination of Alkaline AA batteries - Voltage = 1.5V * 6, power Rating = 2500mAH\n");
            }
            else if(powerRating <= 8 && current <= 0.1){
                printf("Use series combination of Alkaline C batteries - Voltage = 1.5V * 6, power Rating = 8000mAH\n");
            }
            else{
                printf("A non-rechargeable battery for the given configuration is not available\n");
            }
        }
        /**
         * @brief Changing voltage condition and battery type accordingly
         * 
         * @return else 
         */
        else if(voltage < 9 && voltage >= 1.5){
            if(remainder(voltage,3) == 0){
                /**
                 * @brief Segregation based on power rating, current and voltage values for both
                 *          rechargeable and non-rechargeable batteries
                 */
                if(powerRating <= 0.2 && current<=0.01){
                    printf("Use a Lithium Coin Cell - Voltage = 3V * %lf, Power Rating = 200mAH\n", voltage/3);
                }
                else if(powerRating <= 1 && current<=0.01){
                    printf("Use series combination of Alkaline AAA batteries - Voltage = 1.5V * %lf, power Rating = 1000mAH\n",voltage/3);
                }
                else if(powerRating <= 2.5 && current<=0.05){
                    printf("Use series combination of Alkaline AA batteries - Voltage = 1.5V * %lf, power Rating = 2500mAH\n",voltage/3);
                }
                else if(powerRating <= 8 && current <= 0.1){
                    printf("Use series combination of Alkaline C batteries - Voltage = 1.5V * %lf, power Rating = 8000mAH\n",voltage/3);
                }
                else{
                    printf("A non-rechargeable battery for the given configuration is not available\n");
                }
            }
            /**
             * @brief Remainder function used instead of % because it is of type double which is not accpeted by %
             * 
             */
            else if(remainder(voltage,1.5) == 0){
                if(powerRating <= 1 && current<=0.01){
                    printf("Use series combination of Alkaline AAA batteries - Voltage = 1.5V * %lf, power Rating = 1000mAH\n",voltage/1.5);
                }
                else if(powerRating <= 2.5 && current<=0.05){
                    printf("Use series combination of Alkaline AA batteries - Voltage = 1.5V * %lf, power Rating = 2500mAH\n",voltage/1.5);
                }
                else if(powerRating <= 8 && current <= 0.1){
                    printf("Use series combination of Alkaline C batteries - Voltage = 1.5V * %lf, power Rating = 8000mAH\n",voltage/1.5);
                }
                else{
                    printf("A non-rechargeable battery for the given configuration is not available\n");
                }
            }
        }
        /**
         * @brief Print this if the user gives a flase input
         * 
         */
        else{
            printf("Enter the Voltage between [1.5V to 9V], restart the program\n");
        }
    }
    /**
     * @brief Case 2 for non-rechargeable batteries depending on voltage, current and power rating
     * 
     * @return else 
     */
    else if(R == 2){
        if(voltage >= 3.7){
            if(remainder(voltage,3.7) == 0 || remainder(voltage,1.5) == 0){
                if(powerRating <= 6){
                    printf("Use series combination of Lithium ion (LiFeS2) batteries - Voltage = 3.7V or 1.5V, power Rating = 6000mAH\n");
                }
                else{
                    printf("A Rechargeable battery for the given configuration is not available\n");
                }
            }
            else if(remainder(voltage,1.2) == 0){
                if(powerRating <= 2.7){
                    printf("Use series combination of NiCd or NiMH batteries - Voltage = 1.2V*%lf, power Rating = 2700mAH\n",remainder(voltage,1.2));
                }
                else{
                    printf("A Rechargeable battery for the given configuration is not available\n");
                }
            }
        }
    }
    else{ 
        printf("Invalid Input, restart the program\n");
    }
    return powerRating;
}