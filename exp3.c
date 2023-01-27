#include"stdio.h"
#include"stdlib.h"
#define MAX 3
int top=-1;
void push(int stack[],int item){
        if(top==(MAX-1))
                printf("\nStack is overflow\n");
        else{
                stack[++top]=item;
        }
}
void pop(int stack[]){
        int ret;
        if(top==-1)
                printf("Stack is underflow\n");
        else{
                ret=stack[top--];
                printf("\nPopped element is %d\n",ret);
        }
}
void display(int stack[]){
        int i;
        if(top==-1)
                printf("Stack is empty\n");
        else{
                printf("The stack contents are : ");
                for(i=top;i>=0;i--)
                printf("\n-----|%d|-----",stack[i]);
                printf("\n");
        }
}
void main(){
        int item,stack[MAX],ch;
        while(1){
                printf("\n-------MAIN MENU-------\n");
                printf("1.Push\n2.Pop\n3.Exit\n");
                printf("Enter your choice:");
                scanf("%d",&ch);
                switch(ch){
                        case 1:printf("Enter the element to be pushed:");
                               scanf("%d",&item);
                               push(stack,item);
                               display(stack);
                               break;
                        case 2:pop(stack);
                               if(top!=-1);
                               display(stack);
                               break;
                        case 3:exit(0);
                               break;
                        default:printf("Invalid choice!....\n");
                                break;
                }
        }
}             
