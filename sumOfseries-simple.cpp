#include<stdio.h>
int calcSum(int n){
    int temp=1,sum=0;
    for(int i=0;i<n;i++){
        sum=sum+temp;
        temp=temp*10+1;
    }
    return sum;
}
int main(){
    printf("%d",calcSum(3));
    return 0;
}
