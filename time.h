/**
*   Title: time
*   Date: 15.02.2021
*   Author: Julian Timmer
**/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

//This struct saves a year int, a month int and a day int together as an date
struct date
{
    int year;
    int month;
    int day;
};

//Include Prototypes from all functions of time.c
int is_leapyear(int year);
int get_days_for_month(int year, int month); //Does not use struct date as param, because day_of_the_year() uses integer in for-loop.
int exists_date(struct date inputDate);
int day_of_the_year(struct date inputDate);
struct date input_date();

#endif // TIME_H_INCLUDED
