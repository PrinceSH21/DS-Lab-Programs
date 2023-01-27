#include"stdio.h"
#include"stdlib.h"
void push();
void pop();
void display();
struct node{
    int val;
    struct node *next;
};
struct node *head;
void main(){
    int choice=0;
    printf("\n------STACK OPERATIONS USING LINKED LISTS------\n");
    while(choice!=4){
        printf("\nChoose one option from the below options..\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice...:");
        scanf("%d",&choice);
        switch(choice){
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:printf("Exiting...\n");
                    break;
            default:printf("Please enter valid choice... :");
                    break;
        }   
    };
}
void push(){
    int val;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
        printf("Not able to push the element!..\n");
    else{
        printf("Enter the value :");
        scanf("%d",&val);
        if(head==NULL){
            ptr->val=val;
            ptr->next=NULL;
            head=ptr;
        }
        else{
            ptr->val=val;
            ptr->next=head;
            head=ptr;
        }
        printf("Item pushed\n");
    }
}
void pop(){
    int item;
    struct node *ptr;
    if(head==NULL)
        printf("Underflow..\n");
    else{
        item=head->val;
        printf("Item popped=%d\n",item);
        ptr=head;
        head=head->next;
        free(ptr);
    }
}
void display(){
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
        printf("Stack is empty...\n");
    else{
        printf("Printing stack elements...\n");
        while(ptr!=NULL){
            printf("%d\n",ptr->val);
            ptr=ptr->next;
        }
    }
}

      
    
  
