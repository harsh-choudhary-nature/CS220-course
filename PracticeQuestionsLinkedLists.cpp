#include<stdio.h>
class Node{
    private:
        int elem;
        class Node* next;
    public:
        Node(){
            next=NULL;
        }
        Node(int dat){
            elem=dat;
            next=NULL;
        }
        Node(int dat,Node* ptr){
            elem=dat;
            next=ptr;
        }
    friend class LinkedList;
};
class LinkedList{
    private:
        class Node* head;
        class Node* tail;
        int length;
    public:
        LinkedList(){
            head=NULL;
            tail=NULL;
            length=0;
        }
        void addBack(int dat){
            if(tail==NULL){
                tail=new Node(dat,NULL);
                head=tail;
                length++;
                return;
            }
            tail->next=new Node(dat,NULL);
            tail=tail->next;
            length++;
        }
        void printList(){
            length=0;
            Node* iter;
            for(iter=head;iter->next!=NULL;iter=iter->next){
                printf("%d->",iter->elem);
                length++;
            }
            printf("%d",iter->elem);
            length++;
        }
        int len(){
            return length;
        }
        void sort(){
            // printf("Inside sort\n");
            for(int i=0;i<length;i++){
                // printList();
                class Node* iter=head;
                class Node* prev=NULL;
                if(iter==NULL || iter->next==NULL){
                    // printf("Leaving sort\n");
                    continue;
                }
                if(iter->next->next==NULL){
                    if((iter->elem)>(iter->next->elem)){
                        // printf("2 element only\n");
                        tail=head;
                        prev=head->next;
                        prev->next=head;
                        head->next=NULL;
                        head=prev;
                        continue;
                    }
                }
                for(;iter->next->next!=NULL;){
                    //printf("%d\n",iter->elem);
                    bool swapped=false;
                    if((iter->elem)>(iter->next->elem)){
                        swapped=true;
                        Node* temp=iter->next->next;
                        iter->next->next=iter;
                        if(prev==NULL){
                            head=iter->next;
                            prev=iter->next;
                        }else{
                            prev->next=iter->next;
                            prev=iter->next;
                        }
                        iter->next=temp;
                    }
                    if(swapped==false){
                        prev=iter;
                        iter=iter->next;
                    }
                }
                //sort last two elements;
                if((iter->elem)>(iter->next->elem)){
                    prev->next=iter->next;
                    iter->next->next=iter;
                    tail=iter;
                    iter->next=NULL;
                }
                continue;
            }
            // printf("Leaving sort\n");
            return;
        }
        void insert(int dat){
            length++;
            if(head==NULL){
                head=new Node(dat,NULL);
                return;
            }
            if(dat<head->elem){ //for both single or multiple element linked list
                printf("Smallest element\n");
                head=new Node(dat,head);
                return;
            }
            Node* iter;
            for(iter=head;iter->next!=NULL;iter=iter->next){
                if(dat<iter->next->elem){
                    Node* temp=new Node(dat,iter->next);
                    iter->next=temp;
                    return;
                }
            }
            // printf("%d\n",iter->elem);
            addBack(dat);
        }
};
void print(class LinkedList ll){
    printf("Printing linked list\n");
    ll.printList();
    printf("\n");
}
int len(class LinkedList ll){
    return ll.len();
}
void insert(LinkedList &ll,int dat){
    ll.sort();
    // print(ll);
    ll.insert(dat);
    // print(ll);
}
int main(){
    LinkedList ll;
    printf("Input size:");
    int size,temp;
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        scanf("%d",&temp);
        printf("Adding to linked list\n");
        ll.addBack(temp);
    }
    print(ll);
    printf("Length of ll is %d\n",len(ll));
    // ll.sort();
    // print(ll);
    int key;
    printf("Enter the value to enter:");
    scanf("%d",&key);
    // ll.insert(key);
    insert(ll,key);
    print(ll);
    printf("Bye!\n");
    return 0;
}