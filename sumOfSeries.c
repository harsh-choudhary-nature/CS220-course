#include<stdio.h>
int pow(int a,int b){
    int power=1;
    for(int i=0;i<b;i++){
        power*=a;
    }
    return power;
}
int calcSum(int n){
    int num=0;
    int temp;
    for(int i=1;i<=n;i++){      
        temp=i;
        while(temp!=0){
            num=num+pow(10,temp-1);
            temp--;
        }
    }
    return num;
}
int main(){
    //printf("%d",pow(8,3));
    printf("%d",calcSum(4));
    return 0;
}
