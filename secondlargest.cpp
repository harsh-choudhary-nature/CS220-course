#include<stdio.h>
int secondlargest(int arr[],int arr_size){
    int maxi=arr[0];
    int sec=arr[0];
    int i=1;
    while((sec==maxi)&&(i<arr_size)){
        printf("%d\n",i);
        sec=arr[i];
        i++;
    }
    if(sec==maxi){
        printf("Second amx not exists");
        return -101010101010101;    //any random number
    }

    for(int i=0;i<arr_size;i++){
        if(((arr[i]>maxi)||(arr[i]>sec))&&(arr[i]!=maxi)){
            if(arr[i]<maxi){
                sec=arr[i];
                continue;
            }
            sec=maxi;
            maxi=arr[i];
        }
    }
    return sec;
}
int main(){
    int arr[]={15,15,15,2,3,4,5,2,1,6,8,4,7,9,15,15,15,14};
    printf("%d is the second maximum",secondlargest(arr,sizeof(arr)/sizeof(arr[0])));
    return 0;
}
