/**
*   Title: DayOfYear
*   Date: 11.01.2021
*   Author: Julian Timmer
**/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    printf("*** Day of the Year ***\n");
    struct date userInput = input_date(); //construct a date with of the users inputs
    printf("Day of the Year: %i\n", day_of_the_year(userInput)); //Returns day of the year

    return 0;
}
