#include<stdio.h>
#define originalsize 5
void insert(int arr[],int ele,int size){
    if((size==0)||(arr[size-2]<=ele)){
        if(size==0){
            arr[0]=ele;
            return;
        }
        arr[size-1]=ele;
        return;
    }
    arr[size-1]=arr[size-2];
    arr[size-2]=ele;
    insert(arr,ele,size-1);
    return;
}
void sort(int arr[],int size){
    if(size==1){
        return;
    }
    int ele=arr[size-1];
    sort(arr,size-1);
    insert(arr,ele,size);
    return;
}
int main(){
    int arr[originalsize]={1,2,3,4,5};
    for(int i=0;i<originalsize;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    sort(arr,originalsize);
    for(int i=0;i<originalsize;i++){
        printf("%d ",arr[i]);
    }
}
