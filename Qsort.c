#include <stdio.h>
#include <stdlib.h>

void swap(int*a, int l, int r){
    int c = a[l];
    a[l] = a[r];
    a[r] = c;
}

void sort(int* a, int n){
    if(n < 2)
        return;
    int o = a[0];
    int l = 1;
    int r = n - 1;
    while(l < r - 1){
        while(a[l] < o && l != r - 1)
            l++;
        while(a[r] > o && l != r - 1)
            r--;
        if(a[l] > a[r]){
            swap(a, l, r);
        }
    }
    int v;
    if (o > a[r]){
        swap(a, r, 0);
        v = r;
    }
    else if(o < a[l]){
        swap(a, 0, l - 1);
        v = l - 1;
    }
    else{
        swap(a, l, 0);
        v = l;
    }
    sort(a, v);
    sort(a + v + 1, n - v - 1);
}

int main()
{
    int n = 10;
    int* a = malloc(sizeof(int) * 10);
    a[0] = 8;
    a[1] = 5;
    a[2] = 13;
    a[3] = 4;
    a[4] = 0;
    a[5] = 65;
    a[6] = 789;
    a[7] = 34;
    a[8] = 2;
    a[9] = 34;
    sort(a, n);
    //for(int i = 0; i < 10; i++){
       // printf("%d ", m[i]);
    //}
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}
