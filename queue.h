#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<iostream>
#include"dateclass.h"
using namespace std;
///Node of the linked list
struct node
{
    int priority;
    string content;
    Date d;
    struct node *link;
};
class linked_queue
{
    struct node *start;
    struct node *last;
    struct node *ptr;
public:
    void create();
    void insert_ele();
    void insert_mid();
    void delete_ele_start();
    void save();
    void showallnote();
    void display();
};
#endif // QUEUE_H_INCLUDED
