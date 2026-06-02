#include<stdio.h>
#include<limits.h>
void main(){
    int n;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the weights and 0 for no edges:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && a[i][j]==0) a[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[i][k]!=INT_MAX && a[k][j]!=INT_MAX){
                    if(a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    printf("Shortest pairs:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==INT_MAX) printf("Infinity ");
            else printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
