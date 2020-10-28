#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void addFirst(int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=head;
    head=newNode;
}
void addLast(int val){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct node *lastNode=head;
        while(lastNode->next!=NULL){
            lastNode=lastNode->next;
        }
        lastNode->next=newNode;
    }
}
struct node *deleteFirst(struct node *head){
    if(head==NULL)
        return NULL;
    struct node *temp=head;
    head=temp->next;
    free(temp);
    return head;
}
struct node *deleteLast(struct node *head){
    if(head==NULL)  
        return NULL;
    if(head->next ==NULL){
        free(head);
        return NULL;
    }
    struct node *secondLast=head;
    while(secondLast->next->next!=NULL)
        secondLast=secondLast->next;
    free(secondLast->next);
    secondLast->next=NULL;
    return head;
    
}
void printList(struct node* head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    addFirst(10);
    addFirst(20);
    addFirst(30);
    deleteFirst(head);
    printList(head);
}
