/**
*   Title: DayOfYear
*   Date: 11.01.2021, Edit 25.01.2021
*   Author: Julian Timmer
**/

#include <stdio.h>
#include <stdlib.h>

/**
 * @param int year
 * return int
 **/
int is_leapyear(int year)
{
    int isLeapYear = 0;

    if (year >= 1582)
    {
        if (year % 4 == 0) isLeapYear = 1;
        if (year % 100 == 0) isLeapYear = 0;
        if (year % 400 == 0) isLeapYear = 1;
    }
    else isLeapYear = -1;

    return isLeapYear;
}

/**
 * @param int month
 * @param int year
 * return int
 **/
int get_days_for_month(int year, int month)
{
    int daysOfMonth = -1;

    //Arrays of days per month
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    daysOfMonth = daysPerMonth[month-1];

    if (is_leapyear(year) == 1 && month == 2)
    {
        daysOfMonth = 29;
    }

    return daysOfMonth;
}

/**
 * @param int day
 * @param int month
 * @param int year
 * return int
 **/
int exists_date(int year, int month, int day)
{
    //boolean for a valid Date, 1 = valid, 0 = invalid
    int validBool = 0;

    if (year >= 1582 && year <= 2400)   //validate year
    {
        if (month >= 1 && month <= 12)      //validate month
        {
            if (day >= 1 && day <= get_days_for_month(year, month))   //validate day
            {
                validBool = 1;
            }
        }
    }

    return validBool;
}

/**
 * @param int day
 * @param int month
 * @param int year
 * return int
 **/
int day_of_the_year(int day, int month, int year)
{
    int dayOfTheYear = 0;

    if (exists_date(year, month, day) == 1)
    {
        //add days for full months, leap year is considered in function get_days_for_month
        for (int i = 1; i < month; i++)
        {
            dayOfTheYear += get_days_for_month(year, i);
        }

        //add days of the input "day"
        dayOfTheYear += day;
    }
    else dayOfTheYear = -1;

    return dayOfTheYear;
}

int main()
{
    //inputs for testing, ignore
//    int year;
//    int month;
//    int day;

    //inputs
//    printf("*** Day of the Year ***\n");
//    printf("Enter Year: ");
//    scanf("%i", &year);
//    printf("Enter Month: ");
//    scanf("%i", &month);
//    printf("Enter Day: ");
//    scanf("%i", &day);
//    printf("\n");

    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2020));

    return 0;
}
