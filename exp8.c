#include"stdio.h"
#include"stdlib.h"
struct btree{
    struct btree *lchild;
    int data;
    struct btree *rchild;
};
struct btree *insert(struct btree *root,int ele){
    struct btree *temp,*prev=NULL,*cur;
    temp=(struct btree*)malloc(sizeof(struct btree));
    temp->data=ele;
    temp->lchild=temp->rchild=NULL;
    if(root==NULL)return(root=temp);
    cur=root;
    while(cur!=NULL){
        prev=cur;
        if(ele<cur->data)
            cur=cur->lchild;
        else
            cur=cur->rchild;
    }
    if(ele<prev->data)
        prev->lchild=temp;
    else
        prev->rchild=temp;
    return root;
}
void inorder(struct btree *ptr){
    if(ptr!=NULL){
        inorder(ptr->lchild);
        printf("%d\t",ptr->data);
        inorder(ptr->rchild);
    }
}
void preorder(struct btree *ptr){
    if(ptr!=NULL){
        printf("%d\t",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void postorder(struct btree *ptr){
    if(ptr!=NULL){
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d\t",ptr->data);
    }
}
int search(struct btree *root,int key){
    struct btree *cur=root;
    while(cur!=NULL){
        if(key==cur->data)
            return 1;
        else if(key<cur->data)
            cur=cur->lchild;
        else
            cur=cur->rchild;
    }
    return 0;
}
void main(){
    struct btree *root=NULL;
    int i,ch,n,key,flag,ele;
    while(1){
        printf("\n\n-----MAIN MENU-----\n1.Insert\n2.Traversel\n3.Search\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the number of elements : ");
                    scanf("%d",&n);
                    printf("\nEnter the elements to be inserted : ...");
                    for(i=0;i<n;i++){
                        scanf("%d",&ele);
                        root=insert(root,ele);
                    }
                    break;
            case 2: printf("\nPreorder Sequence...\n");
                    preorder(root);
                    printf("\nInorder Sequence ...\n");
                    inorder(root);
                    printf("\nPostorder Sequence...\n");
                    postorder(root);
                    break;
            case 3: printf("\nEnter key to be searched:..\n");
                    scanf("%d",&key);
                    flag=search(root,key);
                    if(flag)
                        printf("\nKey is found..\n");
                    else
                        printf("key is not found..\n");
                    break;
            case 4: printf("Exiting...\n");            
                    exit(0);
        }
    }
}

