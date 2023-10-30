#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list{
    int data;
    struct list *next;
};

typedef struct list node;

node *add_num_random(node *head){
    srand(time(NULL));
    for(int i=0;i<=100;i++){
        int x=rand()%998+1;
        node *temp=(node*)malloc(sizeof(node));
         temp->data=x; temp->next=NULL;
        if(head==NULL || x< head->data) {
            temp->next=head;
            head=temp;
        }
        else{
            node *c=head;
            while(c->next!=NULL&& x>c->next->data){
                c=c->next;
            }
            temp->next=c->next;
            c->next=temp;
        }
        
    }
    return head;
}

void print(node *head){
    node *d=head;
    while(d!=NULL){
        printf("%d ",d->data);
        d=d->next;
    }
}

int main(){
    node *head=NULL;
    head=add_num_random(head);
    print(head);
    return 0;
}