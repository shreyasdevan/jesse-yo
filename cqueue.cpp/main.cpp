/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: shreyasdevan
 *
 * Created on 21 January, 2016, 10:44 PM
 */

//============================================================================
// Name        : ass2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

#define max 5

typedef struct 
{
    char name[10];
    int rollno;
}details;

template <class t>
class cqueue{
    int count;
    int front;
    int rear;
public:
      details arr[max];
    	cqueue()  
	{
		rear=-1;
		front=-1;
                count=0;
	}
    int queuefull();
    int queueempty();
    void cenqueue();
    void cdequeue();
    void display();
};

template <class t>
void cqueue <t> :: display(){
    int temp;
    temp=front;
    if(!queueempty()){
        cout<<"Name\t\troll no.\n";
        while(temp!=rear){
            	cout<<arr[temp].name<<"\t\t"<<arr[temp].rollno<<"\n";
		temp=(temp+1)%max;
        }
        cout<<arr[temp].name<<"\t\t"<<arr[temp].rollno<<"\n";
        cout<<" ";
    }
    else
        cout<<"\n Queue is Empty...!";
}

template <class t>
int cqueue <t> :: queuefull(){
    if(count==max){
    	cout<<"\nQueue full!!";
    }
    else
        return 0;
}

template <class t>
int cqueue <t> :: queueempty(){
    if(front==-1 && rear==-1){
    	return 1;
    }
    else
        return 0;
}

template <class t>
void cqueue <t> :: cenqueue(){
    int nwrear=(rear+1)%max;
    if(front==nwrear)
        queuefull();
    else if(count==max)
    	queuefull();
    else{
        rear=nwrear;
	cout<<"\n Enter name:\t";
	cin>>arr[rear].name;
	cout<<"\n Enter roll.no.:\t";
	cin>>arr[rear].rollno;
	if(front==-1)
		front=0;
        count++;
    }
}


template <class t>
void cqueue <t> :: cdequeue(){

    if(!queueempty()){

           
            if(front==rear)
                front=rear=-1;
            else
            {
                front=(front+1)%max;
            }
        }
    else{
        cout<<"\n Queue is empty..!";
    }
}

int main()
{
	cqueue<int> z;
	int ch,con=0;
	int k,n;
	do
	{
		cout<<"\n\n::THE CIRCULAR QUEUE PROGRAM::\n";
		cout<<"\n1.)Add a record: ";
		cout<<"\n2.)Delete a record:  ";
		cout<<"\n3.)Display the queue: ";
		cin>>ch;
		switch(ch)
		{
		case 3:
			cout<<"\n";
			z.display();
			break;
		case 1:
			z.cenqueue();
                        z.display();
			break;
		case 2:
			z.cdequeue();
                        z.display();
			break;
		default:
			cout<<"\n Invalid choice...!";
		}
		cout<<"\n Do you want to continue?\n 1-Yes\t2-No:\t";
		cin>>con;
	}while(con==1);
	return 0;
}


