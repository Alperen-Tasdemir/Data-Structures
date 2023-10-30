#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{ //listenin kendisi
    int yas;
    char isim[100];
    int id;
    struct list *next;
};

typedef struct list node;


node *add_node(node *head,const char isim[100],int yas,int id){ //listeye düğüm eklemek için kullanılan fonksiyon
    node *temp=(node*)malloc(sizeof(node));
    temp->yas=yas;
    temp->id=id;
    strcpy(temp->isim,isim);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
}
return head;
  }
  
node *search(node *head){ //liste üzerinde arama yapmak için kullanılan fonksiyon//
  node *p=head;
  char aranan[100];
  printf("Aranacak kelimeyi giriniz: ");
  scanf("%s",&aranan);
  while(p!=NULL){
      if(strcmp(aranan,p->isim)==0){
          printf("Aradiginiz kelime bulunmaktadir.\n");
          break;
      }
      p=p->next;
  }
  if(p==NULL){
      printf("Aradiginiz kelime bulunmamaktadir\n");
  }
  return head;
}
node *search_and_delete(node *head){ //liste üzerinde arama ve silme işlemi uygulayan fonksiyon//
    node *p = head;
    char aranan[100];
    int cnt = 0;
    printf("Aradiginiz kelime nedir: ");
    scanf("%s", aranan);
    node *c = NULL;
    while(p != NULL){
        if(strcmp(aranan, p->isim) == 0){
            cnt = 1;
            if (c == NULL) {
                head = p->next;
            } else {
                c->next = p->next;
            }
            node *temp = p;
            p = p->next;
            free(temp);
        } else {
            c = p;
            p = p->next;
        }
    }
    if(!cnt){
        printf("Aradiginiz kelime bulunamadi\n");
    }
    return head;
}

void print(node *head){ //listeyi yazdıran fonksiyon//
    node *p=head;
    int x=1;
    while(p!=NULL){
        printf("%d- %s %d %d\n", x, p->isim, p->yas, p->id);
        p=p->next;
        x++;
    }
}

node *max_len_name(node *head){ //listedeki en uzun ismi yazdıran fonksiyon//
    if (head == NULL) {
        printf("Liste bos\n");
        return NULL;
        }
    node *p = head;
    int max_uzunluk = strlen(p->isim);
    node *max_len_name = p;

    while(p != NULL){
        int uzunluk = strlen(p->isim);
        if(uzunluk > max_uzunluk){
            max_uzunluk = uzunluk;
            max_len_name = p;
        }
        p = p->next;
    }

    printf("En uzun isim= %s\n", max_len_name->isim);
    return head;
}




int main(){
    node *head = NULL;
    int x;
    printf("1-listede arama yapma\n2-listeden eleman silme\n3-listeye yeni eleman ekleme\n4-Listedeki en uzun isim\n5-listeyi yazdirmak ");
    scanf("yapmak istediginiz islem nedir: %d",&x);
    int yas,id;
    char isim[50];
    switch (x)
    {
    case 1:
        search(head);
        break;
    case 2:
        search_and_delete(head);
        break;
    case 3:
        scanf("yas: %d, id: %d, isim: %s",&yas,&id,&isim[50]);
        add_node(head,isim,yas,id);
        break;
    case 4:
        max_len_name(head);
        break;
    case 5:
        print(head);
        break;
    default:
        printf("hatali giris");
        break;
    }
    return 0;
}