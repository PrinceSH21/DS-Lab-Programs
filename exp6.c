#include"stdio.h"
#include"stdlib.h"
struct node{
    struct node *llink;
    int id;
    char name[20];
    char branch[20];
    char area[20];
    struct node *rlink;
};
struct node *first =NULL;
struct node *last=NULL;
struct node *getnode(){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter ID, Name, Branch and Area of specialization : ");
    p->llink=p->rlink=NULL;
    scanf("%d%s%s%s",&p->id,p->name,p->branch,p->area);
    return p;
}
void insertfront(void){
    struct node *p;
    p=getnode();
    if(first==NULL)
        first=last=p;
    else{
        p->rlink=first;
        first->llink=p;
        first=p;
    }
}
void insertlast(){
    struct node *p;
    p=getnode();
    if(first==NULL)
        first=last=p;
    else{
        last->rlink=p;
        p->llink=last;
        last=p;
    }
}
void deletefront(){
    struct node *p=first;
    if(first==NULL){
        printf("List is empty..\n");
        return;
    }
    if(first==last)
        first=last=NULL;
    else{
        first=first->rlink;
        first->llink=NULL;
    }
    printf("Deleted record is : \n");
    printf("%d\t%s\t%s\t%s\t",p->id,p->name,p->branch,p->area);
    free(p);
}
void deletelast(){
    struct node *p=last;
    if(first=NULL){
        printf("List is empty..\n");
        return;
    }
    if(first==last)
        first=last=NULL;
    else{
        last=last->llink;
        last->rlink=NULL;
    }
    printf("Deleted record is : \n");
    printf("%d\t%s\t%s\t%s\t",p->id,p->name,p->branch,p->area);
    free(p);
}
void dispforward(){
    struct node *p;
    int cnt=0;
    if(first==NULL){
        printf("List is empty..\n");
        return;
    }
    printf("\nStatus of list...\n");
    printf("ID\tNAME\tBRANCH\tAREA OF SPECIALIZATION\n");
    for(p=first;p!=NULL;p=p->rlink,cnt++){
        printf("%d\t%s\t%s\t%s\t",p->id,p->name,p->branch,p->area);
        printf("\n");
    }
    printf("\nTotal number of elements in list: %d\n",cnt);
}
void main(){
    int ch;
    while(1){
        printf("\n------MAIN MENU------");
        printf("\n1.Insert Front\n2.Insert Last\n3.Delete Front\n4.Delete Last\n5.Display\n6.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: insertfront();
                    break;
            case 2: insertlast();
                    break;
            case 3: deletefront();
                    break;
            case 4: deletelast();
                    break;
            case 5: dispforward();
                    break;
            case 6: printf("Exiting....\n");
                    exit(0);
                    break;
        }
    }
}
 
