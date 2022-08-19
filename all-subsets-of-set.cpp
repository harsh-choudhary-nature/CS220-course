#include<stdio.h>
void printsubsets(int arr[],int arr_size,int info[]){
    int flag=0;     //if none element is printed only then flag remains 0
    for(int i=0;i<arr_size;i++){
        if(info[i]==1){
            printf("%d,",arr[i]);
            flag=1;
        }
    }
    if(flag==0){
        printf("empty");    
    }
    printf("\n");
}
void subsets(int arr[],int arr_size,int begin,int info[]){
    //base case is when begin increments till no more element can be accessed, i.e. begin=arr_size
    if(begin==arr_size){
        printsubsets(arr,arr_size,info);
        return;
    }
    info[begin]=0;      //not included case
    subsets(arr,arr_size,begin+1,info);        //recursive call 1
    info[begin]=1;      //include case
    subsets(arr,arr_size,begin+1,info);
    return;
}

int main(){
    const int arr_size=3;
    int arr[arr_size]={1,2,3};
    int info[arr_size];
    int begin=0;
    subsets(arr,arr_size,begin,info);
    return 0;
}