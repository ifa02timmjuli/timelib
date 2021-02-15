/**
*   Title: time
*   Date: 15.02.2021
*   Author: Julian Timmer
**/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

//Include Prototypes from all functions of time.c
int is_leapyear(int year);
int get_days_for_month(int year, int month);
int exists_date(int year, int month, int day);
int day_of_the_year(int day, int month, int year);
void input_date(int *pointerY, int *pointerM, int *pointerD);

#endif // TIME_H_INCLUDED
