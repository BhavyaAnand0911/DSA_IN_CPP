#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};
Node* insertAtHead(Node * Head,Node** tail,int data){
  if(Head==NULL){
   Node * newNode=new Node;
   newNode->data=data;
   newNode->next=NULL;
   newNode->prev=NULL;
   *tail=newNode;
   return newNode;
  }
  else{
  Node * newNode=new Node;
  newNode->data=data;
  newNode->next=Head;
  Head->prev=newNode;
  Head=newNode;
  return Head;
  }
}
Node *insertAtEnd(Node *tail,int data){
  if(tail==NULL){
   Node * newNode=new Node;
   newNode->data=data;
   newNode->next=NULL;
   newNode->prev=NULL;
   return newNode;
  }
  else{
  Node * newNode=new Node;
  newNode->data=data;
  tail->next=newNode;
  newNode->prev=tail;
  newNode->next=NULL;
  tail=newNode;
  return tail;
  }
}
Node* insertAtPosition(Node *head,Node *tail,int pos,int val){
  if(pos==1){
    insertAtHead(head,&tail,val);
    return head;
  }
  int cnt=1;
  Node* temp=new Node;
  while(cnt<pos-1){
    cnt++;
    temp=temp->next;
  }
  if(temp->next==NULL){
    insertAtEnd(tail,val);
    return head;
  }
  Node* nodeToInsert=new Node;
  nodeToInsert->data=val;  
  nodeToInsert->next=temp->next;
  temp->next->prev=nodeToInsert;
  temp->next=nodeToInsert;
  nodeToInsert->prev=temp;
  return head;

}
void ListTraversal(Node * ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}
int main() {
  struct Node* head = NULL;
  struct Node* tail= NULL;
  cout<<"After insertion at beginning."<<endl;
  head=insertAtHead(head,&tail,20);
  head=insertAtHead(head,&tail,21);
  head=insertAtHead(head,&tail,22);
  head=insertAtHead(head,&tail,23);
  ListTraversal(head);
  cout<<"After insertion at end"<<endl;
  tail=insertAtEnd(tail,1);
  tail=insertAtEnd(tail,2);
  tail=insertAtEnd(tail,3);
  tail=insertAtEnd(tail,4);
  tail=insertAtEnd(tail,5);
  tail=insertAtEnd(tail,6);
  ListTraversal(head);
  cout<<"After insertion at position"<<endl;
  head=insertAtPosition(head,tail,1,45);
  ListTraversal(head);
}