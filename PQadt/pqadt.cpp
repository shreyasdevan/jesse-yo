/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>


template <class t>
struct queue{
    t data;
    struct queue <t> *next;
};

template <class t>
class que{
    queue <t> *front=0;
    queue <t> *rear=0;
    int count=0;
public:
    int isempty();
    void enqueue(t x);
    t dequeue();
    void display();
};

template <class t>
int que <t> :: isempty(){
    if(front==0)
        return 1;
    else 
        return 0;
}

template <class t>
void que <t> :: enqueue(t x){
    queue <t> *nw;
    nw = new queue <t>;
    nw->data=x;
    nw->next=0;
    if(front==0){
        front=nw;
    }
    else{
        rear->next=nw;
        rear=nw;
    }
    count++;
}

template <class t>
t que <t> :: dequeue(){
    t y;
    queue <t> temp;
    while(!isempty()){
        temp=front;
        y=front->data;
        front=front->next;
        delete temp;
        count--;
    }       
}

template <class t>
void que <t> :: display(){
    queue <t> temp;
    if(!isempty()){
        temp=front;
        while(temp!=0){
            cout<<temp->data;
        }
    }
    else
        cout<<"queue is empty";
}