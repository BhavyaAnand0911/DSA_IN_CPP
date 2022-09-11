#include<stdio.h>

#define size 5

struct stack{
    int s[size];
    int top;
}st;

int isfull(void){
    if(st.top==size-1)
    return(1);
    else
    return(0);
}

int isempty(void){
     if(st.top==-1)
     return(1);
     else
     return(0);
 }

void push(int item){
     st.top++;
     st.s[st.top]=item;
 }

int pop(){
    int item;
    item=st.s[st.top];
    st.top--;
    return(item);
}

void display(){
    int i;
    if(isempty())
    printf("stack is already empty");
    else
    for(int i = st.top;i> -1 ; i--){
        printf("%d\n",st.s[i]);
    }
}

void main(void){
    int choice,item;
    st.top=-1;
    do{
        printf("\n1.push\n2.pop\n3.display\n4.exit");
        printf("\nenter your choise : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the item u want push: ");
            scanf("%d",&item);
            if(isfull())
            printf("stack is full");
            else
            push(item);
            break;
            case 2:
            if(isempty())
            printf("stack is empty");
            else{
                item=pop();
                printf("the poped element is %d",item);
            }
            break;
            case 3:
            display();
            break;
            case 4:
            continue;
        }
    }
    while(choice!=4);
}