#include<stdio.h>
#define notFound -1
int linearSearch(int* arr,int key,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i+1;
        }
    }
    return notFound;
}
int main(){
    const int size=7;
    int arr[size]={1,2,3,4,5,6,7};
    int search=30;
    int found=linearSearch(arr,search,size);
    if(found==notFound){
        printf("Not found!");
    }else{
        printf("Found at %dth position from left!",found);
    }
    return 0;   
}
