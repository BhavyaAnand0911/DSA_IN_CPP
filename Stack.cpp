// Implementation of stack using arrays.

#include <iostream>
#include <string.h>
using namespace std;
 struct Stack
 {
    int size;
    int top;
    int *arr;
 };
 int isEmpty(struct Stack S){
    if(S.top==-1){
        return 1;
    }
    else
    return 0;
}
int isFull(struct Stack S){
    if(S.top==S.size-1)
    return 1;
    else 
    return 0;
}
int main(){
    struct Stack s; //here s is a normal structure variable.
    s.size=80;
    s.top=-1;
    s.arr=new int[s.size];
    // Here s is a structure pointer variable, so that we can use call by reference easily and call/pass a function easily.
    // struct Stack *s;
    // s->size=10;
    // s->top=-1;
    // s->arr=new int[s->size];
    //Getting a segmentation error (core dumped).
    // To check if the stack is empty or not.
    if(isEmpty(s)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    // To check if the stack is full or not.
    if(isFull(s)){
        cout<<"Stack is full"<<endl;
    }
    else 
    {
        cout<<"Stack is not full"<<endl;
    }
    return 0;
}
        S->arr=(int *)malloc(S->size * sizeof(int));
