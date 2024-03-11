#ifndef DATECLASS_H_INCLUDED
#define DATECLASS_H_INCLUDED
#include<iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int year;
public:
    Date()
    {
        day=0;
        month=0;
        year=0;
    }
    Date(int a,int b,int c)
    {
        day=a;
        month=b;
        year=c;
    }
    int get_day();
    int get_months();
    int get_years();
    friend int compare_date(Date d1,Date d2);
    void display_date();
};


#endif // DATECLASS_H_INCLUDED
