#include<stdio.h>
#include<stdlib.h>
#include<iostream>
template<class T> class Stack{
private:
    T* ar;
    int size;
public:
    Stack(){
        ar=NULL;
        size=0;
    }
    Stack(int size1,T* arr){
        size=size1;
        ar=(int*)malloc(size*sizeof(T));
        for(int i=0;i<size;i++){
            ar[i]=arr[i];
        }
    }
    Stack(int size1){
        size=size1;
        ar=(T*)malloc(size*sizeof(T));
    }
    void push(T x){
        size++;
        ar=(T*)realloc(ar,(size)*sizeof(T));
        ar[size-1]=x;
    }
    T pop(){
        if(size==0){
            return 0;
        }
        if(size==1){
            T temp=ar[size-1];
            size--;
            return temp;
        }
        size--;
        ar=(T*)realloc(ar,sizeof(T)*size);
        return ar[size];
    }
    void print(){
        for(int i=0;i<size;i++){
            std::cout<<ar[i];
        }
        printf("\n");
    }
};
char* reverse(char* st1){
    int i=0;
    Stack<char> revstk;
    while(st1[i]!='\0'){
        revstk.push(st1[i]);
        i++;
    }
    i=0;
    while(st1[i]!='\0'){
        st1[i]=revstk.pop();
        i++;
    }
    return st1;
}
int main(){
    Stack<char> st;
    st.push('h');
    st.push('a');
    st.push('r');
    st.push('s');
    st.push('h');
    st.pop();
    st.pop();
    st.print();
    //reverse a string
    char st1[]="hello";
    char* st2=reverse(st1);
    printf("%s",st2);
    return 0;
}