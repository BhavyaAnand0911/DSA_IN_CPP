#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct Stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct Stack p){
    if(p.top==-1)
    return 1;
    else 
    return 0;
}
int isFull(struct Stack p){
    if(p.top==p.size-1)
    return 1;
    else
    return 0;
}
void push(struct Stack p, int val){
    if(isFull(p)){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        ++p.top;
        p.arr[p.top]=val;
    }
}
int pop(struct Stack p){
    int val;
    if(isEmpty(p)){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        val=p.arr[p.top];
        p.top--;
        return val;
    }

}
void display(struct Stack p){
    if(isEmpty(p)){
    cout<<"Stack is Empty"<<endl;
    }
    else{
        for(int i=p.top;i>0;i--){
            cout<<p.arr[i]<<endl;
        }
        cout<<p.arr[p.top];
    }
    }


int main(){
    struct Stack s;
    s.size=5;
    s.top=-1;
    s.arr=new int(s.size);
    char a;
    int b;
    cout<<"Enter y to use stack n to end "<<endl;
    cin>>a;
    do{
        cout<<" \n Enter \n 1. For push \n 2. For pop \n 3. For Display \n 4. To Exit"<<endl;
        cin>>b;
        int pp;
        switch (b)
        {
        case 1:
            cout<<"Enter the value you want to push in stack"<<endl;
            int v;
            cin>>v;
            push(s,v);
            break;
        case 2:
             pp=pop(s);
            cout<<"The Element on given index is-"<<pp<<endl;
            break;
        case 3:
            display(s);
            break;
        case 4:
            cout<<"Enter y to continue n to leave"<<endl;
            cin>>a;
        default:
            cout<<"Invalid Input > Try Again";
            break;
        }


    }while(a!='n');
    return 0;
}