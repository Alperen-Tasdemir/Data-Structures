#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list *next;
};

typedef struct list node;


node *add_f(node *head,int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=head;
    head=temp;
    return head;
}
node *add_l(node *head,int x){
    if(head==NULL)
        head=add_f(head,x);
    else{
        node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        node *temp=(node*)malloc(sizeof(node*));
        temp->data=x;
        temp->next=NULL;
        p->next=temp;
    }
    return head;
}

node *add(node *head, int x){
    if (x%2==0)
        head=add_l(head,x);
    else
        head=add_f(head,x);
  
    return head;
}

void print(node *head){
    node *p =head;
    while(p!=NULL){
        printf("%d \n",p->data);
        p=p->next;
    }
}

int main(){
    node *head=NULL;
    head=add(head,5);
    head=add(head,7);
    head=add(head,6);
    head=add(head,2);
    head=add(head,11);

    print(head);
    return 0;
}