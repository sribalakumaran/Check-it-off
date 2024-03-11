#include<iostream>
#include"dateclass.h"
using namespace std;
///Displaying the date
void Date::display_date()
{
    cout<<day<<"/"<<month<<"/"<<year;
}
///Returning the date,month,year
int Date::get_years()
{
    return year;
}
int Date::get_months()
{
    return month;
}
int Date::get_day()
{
    return day;
}
///Comparing the date
///if dates are same returns 2
///if 1st argument date is greater returns 1
///if 2nd argument date is greater returns 2
int compare_date(Date d1,Date d2)
{
    int f;
    if(d1.year>d2.year)
    {
        f=1;
        return f;
    }
    else if(d1.year==d2.year)
    {
        if(d1.month>d2.month)
        {
            f=1;
            return f;
        }
        else if(d1.month==d2.month)
        {
            if(d1.day>d2.day)
            {
                f=1;
                return f;
            }
            else if(d1.day==d2.day)
            {
                f=2;
                return f;
            }
            else
            {
                f=0;
                return f;
            }
        }
        else
        {
            f=0;
            return f;
        }
    }
    else
    {
        f=0;
        return f;
    }
}
