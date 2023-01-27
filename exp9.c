#include"stdio.h"
#include"stdlib.h"
int a[20][20], visited[20],n;
void bfs(int v){
    int queue[20],i,f=-1,r=-1;
    printf("%d\t",v);
    queue[++r]=v;
    visited[v]=1;
    while(f!=r){
        v=queue[++f];
        for(i=0;i<n;i++){
            if(a[v][i]&&!visited[i]){
                printf("%d\t",i);
                queue[++r]=i;
                visited[i]=1;
            }
        }
    }
}
void main(){
    int v,j,i;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nEnter graph data in matrix form\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter the starting vertices : ");
    scanf("%d",&v);
    printf("\nThe nodes which are reachable : \n");
    bfs(v);
    printf("\n");
}
