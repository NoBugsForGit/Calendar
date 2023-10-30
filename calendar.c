#include <stdio.h>

#define int_1_Byte char
#define bool char
#define true 1
#define false 0
#define SPACE " "

char *week_days[7] = {
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thu",
    "Fri",
    "Sat"};

char *months[12] = {
    "January",
    "February",
    "Marth",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"};

int month_days[12] = {
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31};

void fresh_stdin()
{
    char c;
    while ((c = getchar()) != '\n' && c!= EOF);
}

bool judge_leap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

int_1_Byte get_week(int year)
{

    if (year == 1)
    {
        return 1;
    }

    else
    {
        int result = 0;
        for (int i = 1; i < year; ++i)
        {
            if (judge_leap(i))
            {
                result += 2;
            }
            else
            {
                result += 1;
            }
        }
        result = ++result % 7;
        return result;
    }
}

int main()
{
    int year;
    int_1_Byte start_day;
    int_1_Byte i, j;

    printf("Please input the year,the program will give you the calendar:");
    scanf("%d", &year);
    while (year <= 0)
    {
        printf("Don't input the BCE year!  Reinput:");
        fresh_stdin();
        scanf("%d", &year);
    }
    printf("\n\n");

    start_day = get_week(year);

    if (judge_leap(year))
        month_days[1] = 29;
    else
        month_days[1] = 28;

    printf("\t\t The calendar of %d", year);
    for (i = 0; i < 12; ++i)
    {
        printf("\n\n\n\n%56s\n\n", months[i]);
        for (j = 0; j < 7; ++j)
        {
            printf("%8s", week_days[j]);
        }
        printf("\n");
        for (j = 0; j < start_day; ++j)
        {
            printf("%8s", SPACE);
        }
        for (j = 0; j < month_days[i];)
        {
            printf("%8d", ++j);
            if ((++start_day) == 7)
            {
                start_day = 0;
                putchar('\n');
            }
        }
    }
    printf("\n\n");

    return 0;
}