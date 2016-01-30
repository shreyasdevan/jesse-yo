
#include <iostream>
using namespace std;

#define max 5

template <class t>
struct queue
{
    t data[max];
    int front=-1,rear =-1;
};

template <class t>
class cqueue{
    struct queue <t> q;
    int count=0;
public:
    void queuefull();
    int queueempty();
    void cenqueue(t x);
    t cdequeue(t n);
    void display();
};

template <class t>
void cqueue <t> :: display(){
    int temp;
    temp=q.front;
    if(!queueempty()){
        while(temp!=q.rear){
            cout<<q.data[temp];
            temp=(temp+1)%max;
        }
        cout<<q.data[temp];
    }
    else
        cout<<"\n Queue is Empty...!";
}

template <class t>
void cqueue <t> :: queuefull(){
    if(count == max)
        cout<<"Queue is full..!"<<endl;
    else
        return 0;
}

template <class t>
int cqueue <t> :: queueempty(){
    if(q.front==-1){
        cout<<"Queue is empty...!"<<endl;
    }
    else
        return 0;
}

template <class t>
void cqueue <t> :: cenqueue(t x){

    int nwrear=(q.rear+1)%max;
    if(count == max)
        queuefull();
    else{
        q.rear=nwrear;
        q.data[q.rear]=x;
        if(q.front==-1)
            q.front=0;
        count++;
        cout<<"\n After insertion:\n";
	display();
    }
}

template <class t>
t cqueue <t> :: cdequeue(t n){
    int nwfront;
    if(q.front==-1)
        queueempty();
    else{
            nwfront=(q.front+1)%max;
            n=q.data[q.front];
            if(nwfront==q.rear)
                q.front=q.rear=-1;
            else
            {
                q.front=(q.front+1)%max;
                return n;
            }
        }
}

int main()
{
	cqueue<int> z;
	int ch,con=0,k,n;
	do
	{
		cout<<"\n Enter your choice:\n 1-for Display\n 2-for Insert\n 3-for Delete:\t";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\n";
			z.display();
			break;
		case 2:
			cout<<"\n Enter element you want to insert:\t";
			cin>>k;
			z.cenqueue(k);
			break;
		case 3:
			z.cdequeue(n);
			break;
		default:
			cout<<"\n Invalid choice...!";
		}
		cout<<"\n Do you want to continue?\n 1-Yes\t2-No:\t";
		cin>>con;
	}while(con==1);
	return 0;
}