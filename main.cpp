#include<iostream>
#include<fstream>
#include<time.h>
#include"dateclass.h"
#include"queue.h"
using namespace std;
///Making a menu driven program
int main()
{
    cout<<"----------------------------REMAINDER LIST-------------------------------"<<endl;
    linked_queue l;
    char ch='y';
    int c;
    l.create();
    system("cls");
    while(ch=='y' || ch=='Y')
    {
        cout<<"1.Insert a new note"<<endl;
        cout<<"2.Insert a new note at middle"<<endl;
        cout<<"3.Display all note"<<endl;
        cout<<"4.Completed the top task"<<endl;
        cout<<"5.See Log file"<<endl;
        cout<<"6.Save"<<endl;
        cout<<"7.History"<<endl;
        cout<<"Enter the choice:";
        cin>>c;
        system("cls");
        if(c==1)
        {
            l.insert_ele();
            system("cls");
        }
        else if(c==2)
        {
            l.insert_mid();
            system("cls");
        }
        else if(c==3)
        {
            l.display();
        }
        else if(c==4)
        {
            l.delete_ele_start();
            system("cls");
        }
        else if(c==5)
        {
            system("cls");
            ifstream fin;
            string str;
            fin.open("Log file.txt",ios::in);
            while(fin)
            {
                getline(fin,str);
                cout<<str<<endl;
            }
            fin.close();
        }
        else if(c==6)
        {
            l.save();
        }
        else if(c==7)
        {
            l.showallnote();
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
        cout<<"Do you want to continue(y/n):";
        cin>>ch;
        system("cls");
    }
    return 0;
}
