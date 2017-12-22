#include <stdio.h>
#include <stdlib.h>
void err()
{
	printf("Values are incorrect.\n");
	exit(EXIT_FAILURE);
}

typedef struct struct_date
{
	int day;
	int month;
	int year;
} date;

typedef enum day_name_e { sunday, monday, tuesday, wednesday, thursday, friday, saturday } day_name;

int what_day(const struct struct_date* date)
{
	int a = (14 - date->month) / 12;
	int y = date->year - a;
	int m = date->month + 12 * a - 2;
	return ((date->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) + 7000) % 7;
}

void check_date(date d)
{
	if (d.day <= 0 || d.day > 31)
		err();
	else if (d.month <= 0 || d.month > 12)
		err();
	else if (d.year < 1583)
		err();
	int leap_year = d.year % 4 == 0 ? (d.year % 100 == 0 ? (d.year % 400 == 0 ? 1 : 0) : 1) : 0;
	if (d.month == 2)

	{
		if (leap_year && d.day > 29)
			err();
		else if (!leap_year && d.day > 28)
			err();
	}

	else
	{
		int magic_month = d.month < 8 ? d.month : d.month - 8 + 1;
		if (magic_month % 2 == 1 && d.day > 31)
			err();
		else if (magic_month % 2 == 0 && d.day > 30)
			err();
	}
}

const char *get_day_string(day_name day)
{
	switch (day)
	{
	case 0: return "sunday";
	case 1: return "monday";
	case 2: return "tuesday";
	case 3: return "wednesday";
	case 4: return "thursday";
	case 5: return "friday";
	case 6: return "saturday";
	}
	return "";
}

int main()
{
	date d;
	printf("Enter the data.\n");
	char *line = NULL;
	size_t size = 0;
	getline(&line, &size, stdin);
	if (sscanf(line, "%d.%d.%d", &d.day, &d.month, &d.year) != 3)
		err();
	printf("readed date: %d.%d.%d\n\tday: %d\n\tmonth: %d\n\tyear: %d\n", d.day, d.month, d.year, d.day, d.month, d.year);
	check_date(d);
	day_name day = what_day(&d);
	const char *day_string = get_day_string(day);
	printf("Day number: %d\nDay name: %s\n", day == 0 ? 7 : day, day_string);
	return 0;
}
