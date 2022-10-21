#include<stdio.h>
template<class T> class Node{
    private:
        T elem;
        class Node* next;
    public:
        Node(T x){
            elem=x;
            next=NULL;
        }
        Node(T x,Node* ptr){
            elem=x;
            next=ptr;
        }
        template<class U> friend class Stack;
};
template<class U> class Stack{
    private:
        Node<U>* top;
        int length;
    public:
        Stack(){
            top=NULL;
            length=0;
        }
        void push(U x){ 
            top=new Node<U>(x,top);
            length++;
        }
        U pop(){
            if(top==NULL){
                printf("Empty so get a garbage value\n");
                U x;    //random garbage value of data type T
                return x;
            }
            Node<U>* temp=top;
            top=top->next;
            U x=temp->elem;
            delete temp;
            length--;
            return x;
        }
        int len(){
            return length;
        }
        bool isEmpty(){
            if(length==0){
                return true;
            }
            return false;
        }
        U topElm(){
            if(top==NULL){
                printf("Empty so get a garbage value\n");
                U x;
                return x;
            }
            return top->elem;
        }
};
int main(){
    Stack<float> stkf;
    printf("%d\n",stkf.isEmpty());
    stkf.push(10.5);
    stkf.push(12.5);
    stkf.push(11.5);
    printf("%d\n",stkf.isEmpty());
    printf("%0.2f\n",stkf.topElm());
    printf("%d\n",stkf.len());
    printf("%0.2f\n",stkf.pop());
    printf("%0.2f\n",stkf.topElm());
    printf("===================================================\n");
    Stack<int> stki;
    printf("%d\n",stki.isEmpty());
    stki.push(10);
    stki.push(12);
    stki.push(11);
    printf("%d\n",stki.isEmpty());
    printf("%d\n",stki.topElm());
    printf("%d\n",stki.len());
    printf("%d\n",stki.pop());
    printf("%d\n",stki.topElm());    
    printf("===================================================\n");
    Stack<char> stkc;
    printf("%d\n",stkc.isEmpty());
    stkc.push('a');
    stkc.push('b');
    stkc.push('c');
    printf("%d\n",stkc.isEmpty());
    printf("%c\n",stkc.topElm());
    printf("%d\n",stkc.len());
    printf("%c\n",stkc.pop());
    printf("%c\n",stkc.topElm());
    printf("Ending\n");
    return 0;
}