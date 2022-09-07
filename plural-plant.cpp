#include<stdio.h>
#include<stdlib.h>  
void plural(char* ptr){
    int length=0;
    while(ptr[length]!='\0'){
        length++;
    }
    // printf("\n%d",length);
    ptr[length]='s';
    ptr[length+1]='\0';
}
int main(){
    int size;
    printf("\n Enter size:");
    scanf("%d",&size);
    char* st;
    st=(char*)malloc((size+1)*sizeof(char));
    printf("\n Enter the name of plant:");
    scanf("%s",st);
    // printf("%s",st);
    plural(st); //function call
    printf("\nplural is: %s",st);
    free(st);
    return 0;
}