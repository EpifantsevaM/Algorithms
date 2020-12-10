#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 10;
    int m[10] = {8,5,13,4,0,65,789,34,2,34};
    for(int d = n/2; d >= 1; d /= 2){
        for(int i = d; i < n; i++){
            for(int j = i; j > 0 && m[j-d]>m[j]; j-=d && j>=d){
                m[j - d] += m[j];
                m[j] = m[j - d] - m[j];
                m[j - d] -= m[j];
            }
        }
    }
    for(int i = 0; i < 10; i++)
        printf("%d ", m[i]);
}
