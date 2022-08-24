#include<stdio.h>
void printUnion(int a[],int b[],int sizea,int sizeb){
    bool flag=true;
    for(int i=0;i<sizea;i++){
        printf("%d ",a[i]);
    }
    for(int i=0;i<sizeb;i++){
        for(int j=0;j<sizea;j++){
            if(b[i]==a[j]){
                flag=false;
                break;
            }
            flag=true;
        }
        if(flag){
            printf("%d ",b[i]);
        }
    }
}
void printIntersection(int a[],int b[],int sizea,int sizeb){
    for(int i=0;i<sizea;i++){
        for(int j=0;j<sizeb;j++){
            if(a[i]==b[j]){
                printf("%d ",a[i]);
                break;
            }
        }
    }
}
int main(){
    int a[]={1,2,3,4,5};
    int b[]={1,2,3,6};
    printUnion(a,b,5,4);
    printf("\n");
    printIntersection(a,b,5,4);
    return 0;
}