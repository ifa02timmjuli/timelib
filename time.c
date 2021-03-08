/**
*   Title: time
*   Date: 15.02.2021
*   Author: Julian Timmer
**/

#include <stdio.h>
#include "time.h"

/**
 * Function is given a year and returns 0 if it is NOT a leap year,
 * 1 if it IS a leap year and -1 if the year is earlier than 1581
 *
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
 * Function is given a year and a month and returns the full days of the given month
 * The days for a February of a leap year are considered.
 *
 * @param int month
 * @param int year
 * return int
 **/
int get_days_for_month(int year, int month)
{
    int daysOfMonth = -1;

    //Arrays of days per month in a year e.G. 31 for January on index 0 etc
    int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    daysOfMonth = daysPerMonth[month-1];

    if (is_leapyear(year) == 1 && month == 2) //sets days of moth to 29, if year is a leap year and the month is february
    {
        daysOfMonth = 29;
    }

    return daysOfMonth;
}

/**
 * Function validates a given struct date. Year has to be between 1582 and 2400.
 * The Month has to be between 1 and 12. The day between 1 and max. day of given month.
 * Returns 1 if date is valid and 0 if not.
 *
 * @param struct date
 * return int
 **/
int exists_date(struct date inputDate)
{
    //int for a valid Date, 1 = valid, 0 = invalid
    int validBool = 0;

    if (inputDate.year >= 1582 && inputDate.year <= 2400)   //validate year
    {
        if (inputDate.month >= 1 && inputDate.month <= 12)      //validate month
        {
            if (inputDate.day >= 1 && inputDate.day <= get_days_for_month(inputDate.year, inputDate.month))   //validate day
            {
                validBool = 1;
            }
        }
    }

    return validBool;
}

/**
 * Function is given a struct date and returns the day of the year.
 *
 * @param struct date inputDate
 * return int
 **/
int day_of_the_year(struct date inputDate)
{
    int dayOfTheYear = 0;
    int year = inputDate.year; //initialize int year, so the struct value year can be passed to the get_days_for_month function

    //add days for full months, leap year is considered in function get_days_for_month
    for (int i = 1; i < inputDate.month; i++)
    {
        dayOfTheYear += get_days_for_month(year, i);
    }

    //add days of the inputDate
    dayOfTheYear += inputDate.day;

    return dayOfTheYear;
}

/**
 * Function initializes a struct date and writes user inputs to year, month and day of this struct
 * until the user inputs are valid
 *
 * return struct date
 **/
struct date input_date()
{
    struct date inputDate; //declare a struct date

    do
    {
        //get user inputs and store in struct date inputDate
        printf("Enter Year: ");
        scanf("%i", &inputDate.year);
        printf("Enter Month: ");
        scanf("%i", &inputDate.month);
        printf("Enter Day: ");
        scanf("%i", &inputDate.day);
        printf("\n");

        if (exists_date(inputDate) != 1) //validating date
        {
            printf("\nInput is not a valid date. Please try again.\n\n\n");
        }
    }
    while (exists_date(inputDate) != 1); //demand new user input until date is valid

    return inputDate;
}
