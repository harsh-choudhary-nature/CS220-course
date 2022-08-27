#include<stdio.h>
#define maxSize 50
int palindrome(char* st1){
    int length=0;
    while(st1[length]!='\0'){
        length++;
    }
    char temp[length];
    for(int i=0;i<length;i++){
        temp[length-i-1]=st1[i];
    }
    // for(int i=0;i<length;i++){
    //     printf("%c",temp[i]);
    // }
    for(int i=0;i<length;i++){
        if(st1[i]!=temp[i]){
            return 0;
        }
    }
    // printf("%d",length);
    return 1;
}
int main(){
    char str[maxSize];
    printf("Enter:");
    scanf("%s",str);
    // printf("%s",str);
    int result=palindrome(str);
    if(result==0){
        printf("Not palindromes");
    }else{
        printf("palindromes");
    }
    return 0;
}
