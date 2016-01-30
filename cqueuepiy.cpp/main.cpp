#include<iostream>
using namespace std;

#define max 3

typedef struct{            //for creating record
	char name[10];
	char div[3];
	char mb[11];
}database;

template<class t>
class queue
{
int front,rear;
public:
	database arr[max];
	queue()  //constructor for initializing front and rear to -1
	{
		rear=-1;
		front=-1;
	}

 int isFull();
 int isEmpty();
 void queinsert();
 void quedelete();
 void display();
};

template<class t>
int queue<t>::isEmpty()
{
if(front==-1 && rear==-1)
	return 1;
else
	return 0;
}

template<class t>
int queue<t>::isFull()
{
	int newr=(rear+1)%max;
	if(newr==rear)
		return 1;
	else
		return 0;
}

template<class t>
void queue<t>::queinsert()		//inserting record at end
{
	int newrear;
	newrear=(rear+1)%max;
	if(front==newrear)
		cout<<"\n Queue if full...!";
	else
	{
		rear=newrear;
		cout<<"\n Enter name:\t";
		cin>>arr[rear].name;
		cout<<"\n Enter division:\t";
		cin>>arr[rear].div;
		cout<<"\n Enter mobile number:\t";
		cin>>arr[rear].mb;
		if(front==-1)
			front=0;
	}
}

template<class t>
void queue<t>::quedelete()		//deleting record from front
{
	int newfront;
	if(!isEmpty())
	{
		newfront=(front+1)%max;
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=newfront;
		}
	}
	else
		cout<<"\n Queue is empty..!";
}

template<class t>
void queue<t>::display() //displaying records in the queue
{
	int d=front;
if(!isEmpty())
	{
	cout<<"Name\t\tMobile_no\t\tDivision\n";
		while(d!=rear)
		{
			cout<<arr[d].name<<"\t\t"<<arr[d].mb<<"\t\t"<<arr[d].div<<"\n";
			d=(d+1)%max;
		}
		cout<<arr[d].name<<"\t\t"<<arr[d].mb<<"\t\t"<<arr[d].div<<"\n";
	}
else
	cout<<"\n Queue is Empty...!";
}

int main()
{
	queue<int> z;
	int choice,con=0;
	do
	{
		cout<<"\n Enter your choice:\n 1-for Display\n 2-for Insert\n 3-for Delete:\t";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"\n";
			z.display();
			break;
		case 2:
			z.queinsert();
			cout<<"\n After insertion:\n";
			z.display();
			break;
		case 3:
			z.quedelete();
			cout<<"\n Queue after deletion is:\n";
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
