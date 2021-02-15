/**
*   Title: DayOfYear
*   Date: 11.01.2021, Edit 25.01.2021
*   Author: Julian Timmer
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    //Declare Variables with -1 for debugging purposes,
    //because negative integer are used to validate in further functions.
    int year = -1;
    int month = -1;
    int day = -1;

    printf("*** Day of the Year ***\n");

    input_date(&year, &month, &day); //Reads and validates user input
    printf("Day of the Year: %i\n", day_of_the_year(day, month, year)); //Returns day of the year

    return 0;
}
