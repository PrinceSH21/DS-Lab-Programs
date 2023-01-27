#include"stdio.h"
#include"stdlib.h"
struct node{
    int data;
    struct node *next;
};
struct node *front =NULL;
struct node *rear=NULL;

void iqueue(int value){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    if((front==NULL)&&(rear==NULL)){
        front=rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    printf("\tNode is inserted \n");
}
int dqueue(){
    if(front==NULL){
        printf("Underflow\n");
        return -1;
    }
    else{
        struct node *temp=front;
        int temp_data=front->data;
        front=front->next;
        free(temp);
        return temp_data;
    }
}
void display(){
    struct node *temp;
    if((front==NULL)&&(rear==NULL)){
        printf("Queue is empty\n");
    }
    else{
        printf("The queue is :\n");
        temp=front;
        printf("\t");
        while(temp){
            printf("|%d|-->",temp->data);
            temp=temp->next;
        }
        printf("|NULL|\n\n");
    }
}
void search(int key){
    struct node *temp;
    int flag=0;
    temp=front;
    if((front==NULL)&&(rear==NULL)){
        printf("\tEmpty list\n");
    }
    else{
        while(temp!=NULL){
            if(temp->data==key)
                flag=1;
                temp=temp->next;
        }
    }
    if(flag==1)
        printf("\tSearch is successfull\n");
    else
        printf("\tSearch is unsuccessfull\n");
}
int main(){
    int choice,value,key;
    printf("------Implementation of Queue using linked list------\n");
    while(1){
        printf("\n1.Queue insertion\n2.Deletion at Queue\n3.Display\n4.Search\n5.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to insert :");
                    scanf("%d",&value);
                    iqueue(value);
                    break;
            case 2: printf("\tDeleted element is %d\n",dqueue());
                    break;
            case 3: display();
                    break;
            case 4: printf("Enter the key to be searched : ");
                    scanf("%d",&key);
                    search(key);
                    break;
            case 5: printf("\tExiting....\n");
                    exit(0);
                    break;
            default:printf("\tPlease enter a valid choice....!\n");
                    break; 
        }
    }
    return 0;
}
