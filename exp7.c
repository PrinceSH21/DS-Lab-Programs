#include"stdio.h"
#include"stdlib.h"
#define MAX_SIZE 25
struct treenode{
    int val;
    struct treenode *left;
    struct treenode *right;
};
struct treenode *root=NULL;

void insert(int);
int height(struct treenode*);
void levelorder();

int main(){
    int choice,node_data,node;
    while(1){
        printf("\n\n-----BINARY TREE-----\n\n");
        printf("1.Insert\n2.Height\n3.Levelorder Traversal\n4.Exit\n");
        printf("Enter your choice : "); 
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1: printf("Enter the number of nodes: ");
                    scanf("%d",&node);
                    for(int i=0;i<node;i++){
                        printf("\nEnter data for a new node : ");
                        scanf("%d",&node_data);
                        insert(node_data);
                    }
                    break;
            case 2: printf("Height of the tree is %d",height(root));
                    break;
            case 3: printf("Level order traversal \n\n");
                    levelorder();
                    break;
            case 4: printf("Program Terminated!...\n");
                    exit(0);
            default:printf("Invalid choice!....\n");
                    break;
        }
    }
    return 0;
}
struct treenode *create(int data){
    struct treenode *new_node=(struct treenode*)malloc(sizeof(struct treenode));
    if(new_node==NULL){
        printf("Memory can't be allocated for new node\n");
        return NULL;
    }
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->val=data;
    return new_node;
}
void insert(int data){
    if(root==NULL){
        struct treenode *new_node=create(data);
        if(new_node){
            root=new_node;
            printf("Node with data %d was inserted\n",data);
        }
        return;
    }
    struct treenode *queue[MAX_SIZE];
    struct treenode *new_node=NULL;
    int front=-1;
    int rear=-1;
    queue[front+1]=root;
    front=rear=0;
    while(front<=rear){
        struct treenode *temp=queue[front];
        front++;
        if(temp->left!=NULL){
            queue[++rear]=temp->left;
        }
        else{
            new_node=create(data);
            if(new_node){
                temp->left=new_node;
                printf("Node with data %d was inserted \n",data);
            }
            return;
        }
        if(temp->right!=NULL){
            queue[++rear]=temp->right;
        }
        else{
            new_node=create(data);
            if(new_node){
                temp->right=new_node;
                printf("Node with data %d was inserted \n",data);
            }
            return;
        }
    }
}
int height(struct treenode *root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}
void levelorder(){
    if(root==NULL){
        printf("Tree is empty\n");
    }
    struct treenode *queue[MAX_SIZE];
    int front=-1;
    int rear=-1;
    queue[front+1]=root;
    front=rear=0;
    while(front<=rear){
        struct treenode *temp=queue[front];
        front++;
        printf("\t%d",temp->val);
        if(temp->left!=NULL){
            queue[++rear]=temp->left;
        }
        if(temp->right!=NULL){
            queue[++rear]=temp->right;
        }
    }
}
