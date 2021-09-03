#include "fun.h"
/**
 * @brief Colorcodegenerator for the resistance calculations declared as a global function
 * 
 * @param var - variable value to return the respetive color
 * @return char* 
 */
char * colorCodeGenerator(int var){
    switch(var){
        case 0:
            return "black";
        case 1:
            return "brown";
        case 2:
            return "red";
        case 3:
            return "orange";
        case 4:
            return "yellow";
        case 5:
            return "green";
        case 6:
            return "blue";
        case 7:
            return "violet";
        case 8:
            return "grey";
        case 9:
            return "white";
        default:
            return "Invalid";
    }
}
double reg5band(){
    /**
     * @brief takes the colorcode values from the global function and applies them to find the values for a 4 band resistor
     * 
     */
    for(int i=0;i<=9;i++){
        printf("Press %d for %s \n",i,colorCodeGenerator(i));
    }
    int arr[4];
    int flag=0;
    double value;
    for(int i=0;i<4;i++){
        // user input values
        printf("Enter the value of %d band ",i+1);
        scanf("%d",&arr[i]);
        if(arr[i]>9 || arr[i]<0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        // flag to check if the user has entered the correct values or not
        value = (arr[0]*100 + arr[1]*10 + arr[2])*pow(10,arr[3]);
        return value; 
    }
    else{
        printf("Invalid Choice");
    }
    return 0;
}