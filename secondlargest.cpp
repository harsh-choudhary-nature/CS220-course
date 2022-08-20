#include<stdio.h>
int secondlargest(int arr[],int arr_size){
    int maxi=arr[0];
    for(int i=0;i<arr_size;i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
    }
    int secondMax=arr[0];
    for(int i=0;i<arr_size;i++){
        if((arr[i]>secondMax)&&(arr[i]<maxi)){
            secondMax=arr[i];
        }
    }
    return secondMax;
}
int main(){
    int arr[]={1,2,3,4,5,2,1,6,8,4,7};
    printf("%d is the second maximum",secondlargest(arr,sizeof(arr)/sizeof(arr[0])));
    return 0;
}