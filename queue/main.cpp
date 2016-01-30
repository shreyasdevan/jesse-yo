
#include<iostream>
using namespace std;
#define MAX 5

struct arr
{
    int list[MAX];
    int front,rear;
};

typedef struct arr arr;

class Q
{
    arr *p;
   public:

    Q()
    {
        int loop=MAX;
        p=new arr;
        p->front=-1;
        p->rear=-1;
        while(loop--)
            p->list[loop]=0;
    }
        void accept(int num);
        bool isFull();
        bool isEmpty();
        void menu();
        void display();
        void delRec();
};

void Q::display()
{

     if(!isEmpty())
    {
        for(int i=p->front;i!=p->rear;i=(i+1)%MAX)
            cout<<p->list[i]<<"--";

            cout<<endl;
    }
    else
        cout<<"Queue is empty";
}

bool Q::isFull()
{
    if((p->rear+1)%MAX==p->front)
        return true;
    return false;
}

bool Q::isEmpty()
{
    if((p->rear==-1 && p->front==-1)||(p->front==p->rear))
        return true;
    return false;
}

void Q::delRec()
{
    if(!isEmpty())
        p->front=(p->front+1)%MAX;
    else
        cout<<"The Queue is empty";
}

void Q::accept(int num)
{


    if(isEmpty())
    {
        p->front=0;
        p->rear=0;
        p->list[(p->rear++)%MAX]=num;
    }
    else
    if(!isFull())
    {

        p->list[(p->rear++)%MAX]=num;
    }
    else
        {
            cout<<"The queque is full"<<endl;
            p->rear--;
        }

    display();

}

void Q::menu()
{
    int choice,ON=1;
    bool play=true;

    while(play)
    {
        cout<<"Enter your choice:\n1:Add a record\n2:Delete a record\n3:Check if queue is Empty\n4:Check overflow\n5:Exit :"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter 0 to exit accepting numbers";
                    cin>>ON;
                    while(ON)
                    {
                        accept(ON);

                        cin>>ON;
                    }

                    break;
            case 2:delRec();
                    display();
                    break;
            case 3:if(isEmpty())
                        cout<<"The Queque is empty"<<endl;
                    else
                        cout<<"The Queque is not empty"<<endl;
                    break;
            case 4:if(isFull())
                        cout<<"\nThe queue is full"<<endl;
                     else
                        cout<<"The Queque is not full"<<endl;
                    break;
            case 5:play=false;
                    break;
            default:cout<<"wrong choice entered";
        }
    }
}

int main()
{
    Q obj;

    obj.menu();

    return 0;
}


