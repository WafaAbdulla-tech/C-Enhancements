/* Write enumerated types that supports dates—such as december 12. Then add a function that produces a next day.  So nextday(date) of december 12 is december 13.*/
#include<stdio.h>

//enum month with jan=1;
typedef enum month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
} month;

//define a string array which stores month names
char mon_str[12][10] = {{"jan"}, {"feb"}, {"mar"},{"apr"},{"may"},{"jun"},{"jul"},{"aug"},{"sep"},{"oct"},{"nov"},{"dec"}};
//define structure
typedef struct date
{
    month mon;
    int d;
}date;
//function next_day will define next day, as input is month and date(m=month, d=date)
date next_day(int m, int d)
{
    date tommorow;
    //check if month is feb and date is 28, then next month is mar , same for all months.
    if (((m == 2) && (d == 28)) || ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d == 31)) || ((m == 4 || m == 6 || m == 9 || m == 11) && (d == 30)))
    {
        m = ((m) + 1) % 12;
        if (m == 0)//condition for december 31
        {
            tommorow.mon = 1;
        }
        else//all other month ends except dec31.
        {
            tommorow.mon = m;
        }

        tommorow.d = 1;//day=day+1
    }
    else //date is not month end then next days month will be same month and date=date+1;
    {
        tommorow.mon = m;
        tommorow.d = d + 1;
    }
    return tommorow;
}



int main()
{
    date d[12],l,n; //d[] is structure array which stores number of days in each month, l will store next date, and n is structure variable which holds input data.
    date next_day(int , int);//function prototype
    month m;//enum variable
    int i, j, mo; //i and j are integer counters and mo is input month in int;
    for (i = 0; i < 13; i++)//for loop to define number of days in each month as struct array.
    {
        d[i].mon = m;
        
        if (d[i].mon == 2)
        {
            d[i].d = 28;
        }
        else if (m == 4 || m== 6 ||m==9 || m==11)
        {
            d[i].d = 30;
        }
        else{
            d[i].d = 31;
        }
        m++;
    }
    printf("input month value between [1-12] and date [1-31]\n");
    scanf("%d,%d",&mo,&n.d);//input month and date
    if (0 <mo < 13  && (n.d <= d[mo].d))//validation (if date is valid then calculates next day)
    {
       l = next_day(mo, n.d);
       printf("today is - %s %d\n", mon_str[mo - 1], n.d);
       printf("next day - is  %s %d\n", mon_str[l.mon-1], l.d);
     
    }
    else //invalid input
    {
        printf("invalid input\n");
    }

    return 0;
}


