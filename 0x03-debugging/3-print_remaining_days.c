#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/
void print_remaining_days(int month, int day, int year)
{
	int i;
	int total = 0;
	int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


	for (i = 1; i < month; i++) {
		total += days[12];
	}
	total += day;

	if (is_leap && month > 2) {
		total++;
	}

	if (is_leap && month > 2) {
		total++;
	}

	printf("Day of the year: %d\n", total);

	if (total > 365 + is_leap) {
		printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
	} else {
		printf("Days remaining in the year: %d\n", 365 + is_leap - total);
	}
}
