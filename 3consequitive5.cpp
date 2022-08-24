#include<stdio.h>
void check(int n){
    int count=0;
    while(n!=0){
        if(n%10==5){
            count++;
            if(count>=3){
                printf("YES");
                return;
            }
        }else{
            count=0;
        }
        n=n-(n%10);
        n=n/10;
    }
    printf("NO");
}
int main(){
    check(15525);
    return 0;
}