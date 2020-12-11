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
    int co = 1;
    int l = 1;
    int r = n - 1;
    while(l < r - 1){
        while(a[l] <= o && l != r - 1){
            if(a[l] == o){
                swap(a, co, l);
                co++;
            }
            l++;
        }
        while(a[r] >= o && l != r - 1) {
            if(a[r] == o){
                swap(a, co, r);
                co++;
                if (co > l)
                    l = co;
            }
            else
                r--;
        }

        if(a[l] > a[r]){
            swap(a, l, r);
        }
    }


    int v;
    if(o > a[r]){
        for(int i = 0; i < co; i++){
            swap(a, r - i, i);
        }
        v = r - co + 1;
    }
    else if(o < a[l]){
        for(int i = 0; i < co; i++){
            swap(a, i, l - 1 - i);
        }
        v = l - co;
    }
    else{
        for(int i = 0; i < co; i++){
            swap(a, l - i, i);
        }
        v = l - co + 1;
    }
    sort(a, v);
    sort(a + v + co, n - v - co);
}

int main(int argc, char* argv[])
{
    if(argc != 3)
        return 0;
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL)
        return 1;
    int n;
    fscanf(fp, "%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    sort(a, n);
    fp = fopen(argv[2], "w");
    if(fp == NULL)
        return 2;
    for(int i = 0; i < n; i++){
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    return 0;
}
