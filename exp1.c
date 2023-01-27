#include"stdio.h"
#include"stdlib.h"
int n=0;
void create(int a[]){
        int i;
        printf("Enter the elements : ");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
}
void display(int a[]){
        int i;
        printf("The array elements are :\n");
        for(i=0;i<n;i++)
                printf("%4d",a[i]);
        printf("\n");
}
void main(){
        int a[100];
        int choice;
        while(1){
                printf("\n------MAIN MENU------\n");
                printf("1.Create\n2.Display\n3.Exit\n");
                printf("Enter Your choice: ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:printf("Enter the size of array:");
                               scanf("%d",&n);
                               create(a);
                               break;
                        case 2:display(a);
                               break;
                        case 3:exit(0);
                               break;
                        default:printf("Invalid Choice.....\n");
                                break;
                }
        }
}                             
