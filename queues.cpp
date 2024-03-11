#include<iostream>
#include<fstream>
#include<time.h>
#include"queue.h"
///Creating a new node and make it as start
void linked_queue::create()
{
    int th,tm,ts,dd,dm,dy,pri;
    string con;
    struct node *n=new node;
    cout<<"Enter the priority(1-5):";
    cin>>pri;
    try
    {
        if(pri>5 || pri<0)
        {
            throw pri;
        }
    }
    catch(int pri)
    {
        cout<<"Invalid priority(priority should be between 1 to 5)"<<endl;
        exit(1);
    }
    cout<<"Enter the content:";
    cin>>con;
    n->priority=pri;
    n->content=con;
    cout<<"Enter the date(dd mm yyyy):";
    cin>>dd>>dm>>dy;
    try
    {
        if(dd>31 || dd<0)
        {
            throw dd;
        }
    }
    catch(int dd)
    {
        cout<<"Invalid date(Date lies between 1 to 31"<<endl;
        exit(1);
    }
    try
    {
        if(dm>12 || dm<0)
        {
            throw dm;
        }
    }
    catch(int dm)
    {
        cout<<"Invalid Month(Month lies between 1 to 12)"<<endl;
        exit(1);
    }
    try
    {
        if(dy<0 || dy<2020)
        {
            throw dy;
        }
    }
    catch(int dy)
    {
        cout<<"Invalid Year"<<endl;
        exit(1);
    }
    Date tempd(dd,dm,dy);
    n->d=tempd;
    n->link=NULL;
    start=n;
    last=start;
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Start is created"<<endl;
    fout.close();
}
///Inserting a new node at the beginning or at the end
void linked_queue::insert_ele()
{
    int th,tm,ts,dd,dm,dy,pri;
    string con;
    struct node *n=new node;
    cout<<"Enter the priority:";
    cin>>pri;
    try
    {
        if(pri>5 || pri<0)
        {
            throw pri;
        }
    }
    catch(int pri)
    {
        cout<<"Invalid priority(priority should be between 1 to 5)"<<endl;
        exit(1);
    }
    cout<<"Enter the content:";
    cin>>con;
    n->priority=pri;
    n->content=con;
    cout<<"Enter the date(dd mm yyyy):";
    cin>>dd>>dm>>dy;
    try
    {
        if(dd>31 || dd<0)
        {
            throw dd;
        }
    }
    catch(int dd)
    {
        cout<<"Invalid date(Date lies between 1 to 31"<<endl;
        exit(1);
    }
    try
    {
        if(dm>12 || dm<0)
        {
            throw dm;
        }
    }
    catch(int dm)
    {
        cout<<"Invalid Month(Month lies between 1 to 12)"<<endl;
        exit(1);
    }
    try
    {
        if(dy<0 || dy<2020)
        {
            throw dy;
        }
    }
    catch(int dy)
    {
        cout<<"Invalid Year"<<endl;
        exit(1);
    }
    Date tempd(dd,dm,dy);
    n->d=tempd;
    n->link=NULL;
    if(compare_date(start->d,n->d)==2)
    {
        if(start->priority>=n->priority)
        {
            n->link=start;
            last=start;
            start=n;
        }
        else if(start->priority<n->priority && start->link==NULL)
        {
            n->link=NULL;
            start->link=n;
            last=n;
        }
    }
    else if(compare_date(start->d,n->d)==1)
    {
        n->link=start;
        last=start;
        start=n;
    }
    else if(compare_date(start->d,n->d)==0 && start->link==NULL)
    {
        n->link=NULL;
        start->link=n;
        last=n;
    }
    else if(compare_date(last->d,n->d)==2)
    {
        if(last->priority<n->priority && last->link==NULL)
        {
            last->link=n;
            n->link=NULL;
            last=n;
        }
    }
    else if(compare_date(last->d,n->d)==0 && last->link==NULL)
    {
        last->link=n;
        n->link=NULL;
        last=n;
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Element is added"<<endl;
    fout.close();
}
///Inserting a new node at the middle
void linked_queue::insert_mid()
{
    int th,tm,ts,dd,dm,dy,pri;
    string con;
    struct node *n=new node;
    cout<<"Enter the priority:";
    cin>>pri;
    try
    {
        if(pri>5 || pri<0)
        {
            throw pri;
        }
    }
    catch(int pri)
    {
        cout<<"Invalid priority(priority should be between 1 to 5)"<<endl;
        exit(1);
    }
    cout<<"Enter the content:";
    cin>>con;
    n->priority=pri;
    n->content=con;
    cout<<"Enter the date(dd mm yyyy):";
    cin>>dd>>dm>>dy;
    try
    {
        if(dd>31 || dd<0)
        {
            throw dd;
        }
    }
    catch(int dd)
    {
        cout<<"Invalid date(Date lies between 1 to 31"<<endl;
        exit(1);
    }
    try
    {
        if(dm>12 || dm<0)
        {
            throw dm;
        }
    }
    catch(int dm)
    {
        cout<<"Invalid Month(Month lies between 1 to 12)"<<endl;
        exit(1);
    }
    try
    {
        if(dy<0 || dy<2020)
        {
            throw dy;
        }
    }
    catch(int dy)
    {
        cout<<"Invalid Year"<<endl;
        exit(1);
    }
    Date tempd(dd,dm,dy);
    n->d=tempd;
    n->link=NULL;
    ptr=start;
    while(ptr!=NULL)
    {
        if(compare_date(ptr->d,n->d)==2 && compare_date(ptr->link->d,n->d)==2)
        {
            if(ptr->priority<n->priority && ptr->link->priority>=n->priority)
            {
                n->link=ptr->link;
                ptr->link=n;
                break;
            }
        }
        else if(compare_date(ptr->d,n->d)==2 && compare_date(ptr->link->d,n->d)==1)
        {
            n->link=ptr->link;
            ptr->link=n;
            break;
        }
        else if(compare_date(ptr->d,n->d)==0 && compare_date(ptr->link->d,n->d)==2)
        {
            if(n->priority<=ptr->link->priority)
            {
                n->link=ptr->link;
                ptr->link=n;
                break;
            }
        }
        else if(compare_date(ptr->d,n->d)==0 && compare_date(ptr->link->d,n->d)==1)
        {
            n->link=ptr->link;
            ptr->link=n;
            break;
        }
        ptr=ptr->link;
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Element is added"<<endl;
    fout.close();
}
///Deleting the top node
void linked_queue::delete_ele_start()
{
    struct node *prev;
    ptr=start;
    start=start->link;
    delete ptr;
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Top note is deleted"<<endl;
    fout.close();
}
///Save a set of nodes
void linked_queue::save()
{
    ofstream fout;
    fout.open("Linked.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Saved"<<endl;
    ptr=start;
    while(ptr!=NULL)
    {
        fout<<ptr->priority<<"\t"<<ptr->content<<"\t"<<ptr->d.get_day()<<"/"<< ptr->d.get_months()<<"/"<<ptr->d.get_years()<<endl;
        ptr=ptr->link;
    }
    fout.close();
}
///Shows the history of notes
void linked_queue::showallnote()
{
    ifstream fin;
    string str;
    fin.open("Linked.txt",ios::in);
    while(fin)
    {
        getline(fin,str);
        cout<<str<<endl;
    }
    fin.close();
}
///Displays the current working notes
void linked_queue::display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->priority<<"\t"<<ptr->content<<"\t";
        ptr->d.display_date();
        cout<<endl;
        ptr=ptr->link;
    }
}
