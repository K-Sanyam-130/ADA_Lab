#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void quickSort(int a[] , int low, int high);
int partition(int a[], int low, int high);
void swap(int *x, int *y);
void quickSort(int a[] , int low, int high){
    if(low<high){
        int p = partition(a,low,high);
        quickSort(a,low,p-1);
        quickSort(a,p+1,high);
    }
}

int partition(int a[], int low, int high){
    int b = a[low];
    int i = low+1;
    int j = high;
    while(1){
        while(i<= high && a[i]<= b){
            i++;
        }
        while(a[j] > b){
            j--;
        }
        if(i<j){
            swap(&a[i] ,&a[j]);
        }
        else{
            break;
        }
        
    }
    swap(&a[low] , &a[j]);
    return j;
}

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int main(){
    int n , i;
    printf("Enter number of elements :");
    scanf("%d",&n);
    int a[n];
    srand(time(NULL));
    for ( i=0;i<n;i++){
        a[i] = rand() % 100000;
    }
    clock_t start , end;
    start = clock();
    quickSort(a,0,n-1);
    end = clock();

    double time = (double)(end-start)*1000 / CLOCKS_PER_SEC;

    /*printf("\n Sorted Array:");
    for(i=0;i<n;i++){
        printf("%d", a[i]);
    }*/
    printf("\n Time taken : %.3f", time);
    return 0;

    
}