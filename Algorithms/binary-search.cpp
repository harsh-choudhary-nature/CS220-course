#include<stdio.h>
#define notFound -1
int BinarySearch(int* arr,int key,int size){
    //only for sorted arrays
    int beg=0,end=size-1;
    int mid;
    while(beg<end){
        // printf("Not found!\n");
        mid=(beg+end)/2;
        if(arr[mid]>key){
            end=mid;        //learn
        }else{
            beg=mid+1;      //learn
        }
    }
    if(arr[mid]==key){
        return mid+1; 
    }
    return notFound;
}
int main(){
    const int size=7;
    int arr[size]={1,2,3,4,5,6,7};
    int search=5;
    int found=BinarySearch(arr,search,size);
    if(found==notFound){
        printf("Not found!");
    }else{
        printf("Found at %dth position from left!",found);
    }
    return 0;   
}