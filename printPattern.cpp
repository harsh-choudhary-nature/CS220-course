#include<stdio.h>
void func(int n){
    for(int i=0;i<n;i++){
        //spaces
        for(int j=0;j<i;j++){
            printf(" ");
        }
        //stars
        for(int j=0;j<n-i;j++){
            printf("*");
        }
        printf("\n");
    }
}
int main(){
    func(9);
    return 0;
}