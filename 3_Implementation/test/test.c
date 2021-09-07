#include "unity.h"
#include "unity_internals.h"
#include<math.h>
#include "fun.h"

/* including header file of the project and the project name*/
#include "fun.h"
#define PROJECT_NAME    "ElectronicCircuitAnalyzer"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
/* function definition for all the functions to be tested*/
void test_battery_data(void);
void test_capacitor(void);
void test_inductor(void);
//void test_powerAndLife(MainMenu *battery);
//void test_RLC(MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance);

/* Start of the application test */
int main()
{
  MainMenu *frequency, *capacitance, *inductance, *battery, *resistance, freq, res, induc, cap, bat;
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_battery_data);
  RUN_TEST(test_capacitor);
  RUN_TEST(test_inductor);
  // RUN_TEST(test_powerAndLife);
  // RUN_TEST(test_RLC);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_battery_data(void){
    // test case 1 for battery data
    TEST_ASSERT_EQUAL(0.005, battery_data(1,9,0.005,5,0.2));
    // test case 2 for battery data
    TEST_ASSERT_EQUAL(0.01, battery_data(1,1.5,0.01,5,0.2));
    // test case 3 for battery data
    TEST_ASSERT_EQUAL(0.0075, battery_data(1,4.5,0.03,5,0.3));
    // test case 4 for battery data
    TEST_ASSERT_EQUAL(0.012, battery_data(2,3.7,0.01,3,0.4));
}
void test_capacitor(void){
    // test case 1 for capacitor function
    TEST_ASSERT_EQUAL((3.979), (capacitor(10,4,3,-6)));
    // test case 2 for capacitor function
    TEST_ASSERT_EQUAL((4.547), (capacitor(7,5,6,-9)));
}
void test_inductor(void){
    // test case 1 for inductor function
    TEST_ASSERT_EQUAL(48.066, inductor(17,4.5,5,-6));
    // test case 2 for inductor function
    TEST_ASSERT_EQUAL(0.305, inductor(6.332,7.667,3,-6));
}
/*void test_powerAndLife(MainMenu *battery){
  //test case 1 for powerAndLife function
    battery->voltage = 5;
    battery->reactance = 6.7;
    battery->units = 3;
    TEST_ASSERT_EQUAL((3.731343), (powerAndLife(battery,2)));
    //test case 2 for powerAndLife function
    battery->voltage = 9;
    battery->reactance = 10;
    battery->units = 6;
    TEST_ASSERT_EQUAL((8.100000), (powerAndLife(battery,2)));
}
void test_RLC(MainMenu *inductance, MainMenu *capacitance, MainMenu *frequency, MainMenu *resistance){
  // test case for RLC function
    inductance->val = 5;
    inductance->units = -6;
    capacitance->val = 3;
    capacitance->units = -9;
    resistance->val = 4.5;
    resistance->units = 3;
    resistance->voltage = 5;
    frequency->val = 7;
    frequency->units = 3;
    TEST_ASSERT_EQUAL(0.000000147,RLC(1, inductance, capacitance, frequency, resistance));
}
*/