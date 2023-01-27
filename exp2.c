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
void insert(int a[],int ele, int pos){
        int i;
        for(i=n-1;i>=pos;i--)
        a[i+1]=a[i];
        a[pos]=ele;
        n=n+1;
}
int delete(int a[], int pos){
        int i,ele;
        ele=a[pos];
        for(i=pos;i<n-1;i++)
        a[i]=a[i+1];
        n=n-1;
        return ele;
}
void main(){
        int a[100],ele,pos;
        int choice;
        while(1){
                printf("\n------MAIN MENU------\n");
                printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice){
                        case 1:printf("Enter the size of array :");
                               scanf("%d",&n);
                               create(a);
                               break;
                        case 2:display(a);
                               break;
                        case 3:printf("Enter the valid position of element :");
                               scanf("%d",&pos);
                               printf("Enter the element to be inserted :");
                               scanf("%d",&ele);
                               insert(a,ele,pos);
                               break;
                        case 4:printf("Enter the element to be deleted:");
                               scanf("%d",&pos);
                               delete(a,pos);
                               printf("The deleted element is %d\n",pos);
                               break;
                        case 5:exit(0);
                               break;
                        default:printf("Invalid choice!....\n");
                                break;
                }
        }
}
                               
                               
                        
        
