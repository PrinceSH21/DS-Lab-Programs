#include"stdio.h"
#include"stdlib.h"
struct node{
	int data;
	struct node *next;
};
void display(struct node *head){
    struct node *temp;
    temp=head;
    if(temp==NULL)
        printf("Empty list..\n");
    else{
        printf("\n\t\t-------CONCATINATION-------\n");
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void concat(struct node *a,struct node *b){
    if(a!=NULL && b!=NULL){
        if(a->next==NULL)
            a->next=b;
        else
            concat(a->next,b);
    }
    else
        printf("Either a or b is NULL \n");
}
int main(){
    struct node *prev,*a,*b,*p;
    int n,i,key;
    printf("Number of nodes in a : ");
    scanf("%d",&n);
    printf("Enter %d of elements : ",n);
    a=NULL;
    for(i=0;i<n;i++){
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(a==NULL)
            a=p;
        else
            prev->next=p;
            prev=p;
    }
    printf("Number of nodes in b:");
    scanf("%d",&n);
    printf("Enter %d of elements :",n);
    b=NULL;
    for(i=0;i<n;i++){
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(b==NULL)
            b=p;
        else
            prev->next=p;
            prev=p;
    }
    concat(a,b);
    display(a);
    printf("\n");
    return 0;
}
       
