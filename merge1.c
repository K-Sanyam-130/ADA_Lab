#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int l, int m, int r){
    int i = l, j = m + 1, k = 0;
    int t[r - l + 1];

    while(i <= m && j <= r){
        if(a[i] <= a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }

    while(i <= m)
        t[k++] = a[i++];

    while(j <= r)
        t[k++] = a[j++];

    for(i = l, k = 0; i <= r; i++, k++)
        a[i] = t[k];
}

void mergesort(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;

        mergesort(a, l, m);
        mergesort(a, m + 1, r);

        merge(a, l, m, r);
    }
}

int main(){
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));

    srand(time(NULL));   

    printf("\nGenerated Random Array:\n");
    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000;  
        printf("%d ", a[i]);
    }

    clock_t start = clock();

    mergesort(a, 0, n - 1);

    clock_t end = clock();

    printf("\n\nSorted Array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    double time_taken = (((double)(end - start)*1000.0) / CLOCKS_PER_SEC) ;

    printf("\n\nTime taken: %f milliseconds\n", time_taken);

    free(a);
    return 0;
}