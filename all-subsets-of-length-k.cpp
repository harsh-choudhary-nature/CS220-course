#include<stdio.h>
void printsubsets(int arr[],int arr_size,int info[],int k){
    int flag=0;     //if none element is printed only then flag remains 0
    int counter=0;     
    for(int i=0;i<arr_size;i++){
        if(info[i]==1){
            counter+=1;
        }    
    }
    if(counter==k){
        for(int i=0;i<arr_size;i++){
            if(info[i]==1){
                printf("%d,",arr[i]);
            }
        }
        printf("\n");
    }
}
void subsets(int arr[],int arr_size,int begin,int info[],int k){
    //base case is when begin increments till no more element can be accessed, i.e. begin=arr_size
    if(begin==arr_size){
        printsubsets(arr,arr_size,info,k);
        return;
    }
    info[begin]=0;      //not included case
    subsets(arr,arr_size,begin+1,info,k);        //recursive call 1
    info[begin]=1;      //include case
    subsets(arr,arr_size,begin+1,info,k);
    return;
}

int main(){
    const int arr_size=2;
    int k=1;
    int arr[arr_size]={1,2};
    int info[arr_size];
    int begin=0;
    subsets(arr,arr_size,begin,info,k);
    return 0;
}