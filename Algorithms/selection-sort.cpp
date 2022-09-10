#include<stdio.h>
int main(){
    const int size=5;
    int arr[size]={7,8,3,1,2};
    for(int i=0;i<size-1;i++){      //remember size-1
        int smallest=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[smallest]){
                smallest=j;
            }
        }
        //swap smallest and current i
        int temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }   
    return 0;
}