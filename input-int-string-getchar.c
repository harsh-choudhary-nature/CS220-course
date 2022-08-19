#include<stdio.h>
#define arr_size 15         //defining a constant in global scope (extern variable)
char str_arr[arr_size];
int getnum(){
    char c;
    int i;
    int sum=0;
    c=getchar();
    //what if user simply pressed enter without entering, still sum=0 would be returned, so handle that also
    if(c=='\n'){
        return -1;
    }
    while(c!='\n'){
        i=c-'0';       //i now stores actual digit in number sequence rather than the ascii code of c as ascii code of '0' is subtracted from it
        //but what if user has entered letters also, as ascii code exists for letters also and so our program may also return something for those cases
        //but for char c storing '0' through '9' digits, only allowed no's in i=0,1,2,3,4,5,6,7,8,9
        if((i<0)||(i>9)){
            return -1;  //handled in main()
        }
        
        sum=sum*10+i;
        c=getchar();
    }
    return sum;

}
int getstr(){
    //we need to build a char array to create a string from inputs
    //we define char array in global scope as an array can't be the return value of any function and so creating in local scope of function may be useless
    char c;
    int i=0;
    c=getchar();
    while(c!='\n'){
        str_arr[i]=c;
        i++;
        c=getchar();
    }
    str_arr[i]='\0';        //creating a string which is an array of characters with last character as end of string
    return 0;
}
int main(){
    int num;
    printf("Enter the input number:");
    num=getnum();
    if(num!=-1){
        printf("num=%d\n",num);
    }else{
        printf("Enter the valid numbers\n");
    }
    printf("Enter the string you want to enter:");
    getstr();
    printf("The string entered by you is %s\n",str_arr);   
    return 0; 
}