#include<iostream>
using namespace std;

typedef struct node_str{
  int data;
  struct node_str *next;
}Node;

typedef struct list_str{
  Node *first;
  Node *last;
}List;

void insertAtBack(List *l, int val){
  Node *newPtr= (Node*)malloc(sizeof(Node));
  newPtr->data=val;
  newPtr->next=NULL;
  //cout<<"inserting "<<newPtr->data<<endl;
  if(l->first==NULL){
    l->first=l->last=newPtr;
  }else{
    l->last->next=newPtr;
    l->last=newPtr;
  }
}

void removeAtBack(List *l){
  if(l->first!=NULL){
    Node *temp=l->last;
    if(l->first==l->last){
      l->first=l->last=NULL;
    }else{
      Node *temp=l->first;
      while(temp->next!=l->last){
        temp=temp->next;
      }
      l->last=temp;
      temp->next=NULL;
    }
  }
}

void printList(List *l){

  if(l->first!=NULL){
    Node *curr=l->first;
    while(curr!=NULL){
      cout<<curr->data<<"->";
      curr=curr->next;
    }
    cout<<endl;
  }
}
