#include<stdio.h>
void rev_arr(int arr[],int size);
int main(){
    const int size=7;
    int ar[7]={1,2,3,4,5,6,7};
    for(int i=0;i<size;i++){
        printf("%d",ar[i]);
    }
    printf("\n");
    rev_arr(ar,size);
    for(int i=0;i<size;i++){
        printf("%d",ar[i]);
    }
    return 0;
}