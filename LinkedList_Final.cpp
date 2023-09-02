#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node{
    int data;
    Node * next;
};
void ListTraversal(Node * ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
Node * insertAtBeg(struct Node* Head,int val){
    Node * p=new Node;
    p->data=val;
    p->next=Head;
    return p;
}
 Node * insertAtEnd(struct Node* Head,int val){
    struct Node* p= new Node;
    struct Node*  ptr=Head;
    p->data=val;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=p;
    p->next=NULL;
    return Head;
}
Node * insertAtNode(struct Node* Head,int val,int pos){
    struct Node* ptr=Head;
    struct Node* p= new Node;
    p->data=val;
    for (int i = 1; i < pos-1; i++)
    {
        ptr=ptr->next;
    }
    p->next=ptr->next;
    ptr->next=p;
    return Head;
}
struct Node* deleteFromBeg(struct Node* Head){
    struct Node* p=Head;
    Head=p->next;
    free(p);
    return Head;
}
struct Node * deleteFromEnd(struct Node* Head){
    struct Node* ptr= Head;
    struct Node* p=Head->next;
    while(p->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(p);
    return Head;

}
struct Node* deleteFromNode(struct Node* Head,int pos){
    struct Node* ptr=Head;
    struct Node* p=Head->next;
    for (int i = 0; i < pos-1; i++)
    {
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return Head;
} 
struct Node* deleteByValue(struct Node* Head, int val){
    struct Node* ptr=Head;
    struct Node* p=Head->next;
    if(ptr->data==val){
        Head=ptr->next;
        free(ptr);
        return Head;
    }
    else{
    while(p->data!=val&&p->next!=NULL){
        p=p->next;
        ptr=ptr->next;
    }
    if(p->data == val){
        ptr->next = p->next;
        free(p);
    }
    }
    return Head;
}
int main(){
    struct Node * head = new struct Node;
    head=NULL;
    cout<<"List with beginning insertion is : "<<endl;
    head=insertAtBeg(head,1);
    head=insertAtBeg(head,2);
    head=insertAtBeg(head,3);
    head=insertAtBeg(head,4);
    head=insertAtBeg(head,5);
    head=insertAtBeg(head,6);
    ListTraversal(head);
    cout<<"List after end insertion is : "<<endl;
    head=insertAtEnd(head,50);
    head=insertAtEnd(head,55);
    ListTraversal(head);
    cout<<"List after end insertion at a given position is : "<<endl;
    head=insertAtNode(head,100,3);
    head=insertAtNode(head,100,5);
    head=insertAtNode(head,100,7);
    ListTraversal(head);
    cout<<"List after deletion from beginning is : "<<endl;
    head=deleteFromBeg(head);
    ListTraversal(head);
    cout<<"List after deletion from End is : "<<endl;
    head=deleteFromEnd(head);
    ListTraversal(head);
    cout<<"List after deletion from Node is : "<<endl;
    head=deleteFromNode(head,5);
    ListTraversal(head);
    cout<<"List after deletion by value is : "<<endl;
    head=deleteByValue(head,50);
    ListTraversal(head);
}