#include<stdio.h>
int palindrome(char str[],int size){
    int beg=0,end=size-1;
    while(beg<=end){
        if(str[beg]!=str[end]){
            return 0;
        }
        beg++;end--;
    }
    return 1;   //plaindrome
}
int main(){
    char st[]="MALAYALAMa";
    //printf("%d",sizeof(st)/sizeof(char));
    printf("%d",palindrome(st,sizeof(st)/sizeof(char)-1));
    return 0;
}