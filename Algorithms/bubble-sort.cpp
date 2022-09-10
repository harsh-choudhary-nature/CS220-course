#include<stdio.h>
int main(){
    const int size=5;
    int arr[size]={7,8,3,1,2};
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;   
}