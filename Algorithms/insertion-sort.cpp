#include<stdio.h>
int main(){
    const int size=5;
    int arr[size]={7,8,3,1,2};
    for(int i=1;i<size;i++){
        int current=arr[i];
        int j=i-1;
        while(j>=0 && current<arr[j]){
            //swap
            arr[j+1]=arr[j];
            j--;            
        }
        arr[j+1]=current;
        
    }
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;   
}