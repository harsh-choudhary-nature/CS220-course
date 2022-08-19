#include<stdio.h>
int sumofarray(int arr[],int sizeof_array){
    int x=0;
    if(sizeof_array==1){    //base case
        return arr[0];  //or return arr[sizeof_array-1];
    }
    x=sumofarray(arr,sizeof_array-1);   //recursive step
    return (x+arr[sizeof_array-1]);
}
int main(){
    const int arr_size=5;
    int ar[arr_size]={1,2,3,4,5};
    printf("The sum of array is %d",sumofarray(ar,arr_size));
}