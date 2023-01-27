#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define m 100
struct emp{
    int emp_id;
    char name[30];
};
void Init_HT(struct emp HT[]){
    int i;
    for(i=0;i<m;i++)
        HT[i].emp_id=-1;
    }
void Insert(struct emp HT[],int key,char name[]){
    int h,i;
    h=key%m;
    if(HT[h].emp_id==-1){
        HT[h].emp_id=key;
        strcpy(HT[h].name,name);
        return ;
    }
    printf("\nCollision detected & Linear probing is on.....\n");
    for(i=(h+1)%m;i!=h&&HT[i].emp_id!=-1;i=(i+1)%m);
    if(i==h)
        printf("\nHash Table is full....\n");
    else{
        HT[i].emp_id=key;
        strcpy(HT[i].name,name);
    }
}
void display(struct emp HT[]){
    int i;
    printf("\nRecords in Table....\n");
    printf("\nID\tName\n");
    for(i=0;i<m;i++){
        if(HT[i].emp_id!=-1)
            printf("%d\t%s\n",HT[i].emp_id,HT[i].name);                
    }
}
void main(){
    struct emp HT[m];
    int id,ch;
    char name[30];
    Init_HT(HT);
    while(1){
        printf("\n1.Insert Record\n2.Display\n3.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter Record[ID, Name] : ");
                    scanf("%d%s",&id,name);
                    Insert(HT,id,name);
                    break;
            case 2: display(HT);
                    break;
            case 3: printf("Exiting .....\n");
                    exit(0);
            default:printf("Please enter a valid option ...\n");
                    break;
        }
    }
}     
                
         
       
