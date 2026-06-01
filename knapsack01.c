#include<stdio.h>

int max (int a , int b){
    return (a>b) ? a : b;
}

int knapsack(int W,int wt[], int val[], int n){
    int dp[n+1][W+1];
    
    for(int i = 0; i<=n ; i++){
        for(int w = 0; w<= W ; w++){
            if(w == 0 || i == 0){
                dp[i][w] = 0;
            }
            else if (wt[i-1] <= w){
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // Display the DP matrix
    printf("\nDP Matrix:\n");
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            printf("%4d", dp[i][w]);
        }
        printf("\n");
    }

    return dp[n][W];
}

int main(){
    int n , W;

    printf("\nEnter no of items : ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("\nEnter weights : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &wt[i]);
    }

    printf("\nEnter values : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &val[i]);
    }

    printf("\nEnter capacity : ");
    scanf("%d", &W);

    int res = knapsack(W, wt, val, n);

    printf("\nMaximum value = %d\n", res);

    return 0;
}