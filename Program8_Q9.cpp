#include<iostream>
#include<iomanip>
using namespace std;
void hours_payrate_wages(long int emp[], double pay[], int hrs[], double wage[]);
void display_gross_wages(long int emp[], double wage[]);//function prototypes
const int SIZE = 7;//universal constant for size of array
int main()
{
    int hours[SIZE];//array with 7 elements
    long int empId[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};//array with seven elements, initialized
    double payRate[SIZE], wages[SIZE];                                                //with employee id numbers
    hours_payrate_wages(empId, payRate, hours, wages);//calling functions
    display_gross_wages(empId, wages);
    return 0;
}
void hours_payrate_wages(long int emp[], double pay[], int hrs[], double wage[])//function to gather user input
{
    for(int i = 0; i < SIZE; i++)//for loop to fill all seven elements of array
    {
        int minPay = 15, minHours = 0;//variables for input validation
        cout << "EMPLOYEE #" << emp[i] << endl << "Pay rate: $";//names [i] employee (i increases by 1 with each loop iteration)
        cin >> pay[i];//gets [i] employee's pay
        while(pay[i] < minPay)//input validation, must be at least $15
        {   cout << endl << "ERROR: MINIMUM PAY IS $15. ENTER VALUE OF 15 OR GREATER." << endl;
            cout << "Pay rate: $";
            cin >> pay[i];
        }
        cout << "Hours worked: ";
        cin >> hrs[i];//gets employee [i]'s hours worked
        while(hrs[i] < minHours)//input validation, must be at least 0 hours
        {   cout << endl << "ERROR: MINIMUM HOURS IS 0. PLEASE ENTER ONLY POSITIVE VALUES." << endl;
            cout << "Hours worked: ";
            cin >> hrs[i];
        }
        wage[i] = pay[i] * hrs[i];//valculates employee [i]'s wage and stores in corresponding spot in wage array
        cout << endl;
    }
}
void display_gross_wages(long int emp[], double wage[])//function to display wages
{
    cout << "EMPLOYEE ID #  |  GROSS WAGES" << endl;
    cout << "-----------------------------" << endl;
    cout << setprecision(2) << fixed;
    for(int i = 0; i < SIZE; i++)//repeats for each of the seven employees
    {   cout << "    " << emp[i] << "    |    $" << wage[i] << endl;
    }
}
