#include<stdio.h>
int maximum(int arr[],int arr_size){
    int maxi=arr[0];
    for(int i=1;i<arr_size;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    return maxi;
}
int minimum(int arr[],int arr_size){
    int mini=arr[0];
    for(int i=1;i<arr_size;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    return mini;
}
int main(){
    int arr[]={1,2,3,4,5,2,1,6,8,4,7};
    printf("%d is the maximum and %d is the minimum",maximum(arr,sizeof(arr)/sizeof(arr[0])),
    minimum(arr,sizeof(arr)/sizeof(arr[0])));
    return 0;
}