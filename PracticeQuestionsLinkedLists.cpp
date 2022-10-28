#include<stdio.h>
#include<stdlib.h>
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
        void addFront(int dat){
            if(head==NULL){
                head=new Node(dat,NULL);
                tail=head;
                length++;
                return;
            }
            head=new Node(dat,head);
            length++;
        }
        void printList(){
            Node* iter;
            for(iter=head;iter->next!=NULL;iter=iter->next){
                printf("%d->",iter->elem);
            }
            printf("%d\n",iter->elem);
            printf("%dlength of linked list\n",length);
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
            if(head==NULL){
                head=new Node(dat,NULL);
                tail=head;
                length++;
                return;
            }
            if(dat<head->elem){ //for both single or multiple element linked list
                printf("Smallest element\n");
                head=new Node(dat,head);
                length++;
                return;
            }
            Node* iter;
            for(iter=head;iter->next!=NULL;iter=iter->next){
                if(dat<iter->next->elem){
                    Node* temp=new Node(dat,iter->next);
                    iter->next=temp;
                    length++;
                    return;
                }
            }
            // printf("%d\n",head->elem);
            addBack(dat);
            printf("%d",length);
            // printf("%d\n",head->elem);

        }
        int NthNode(int n){
            if(n>=length){
                printf("Length is %d\n",length);
                return -1;
            }
            printf("Length is %d\n",length);

            Node* iter=head;
            for(int i=0;i<n;i++,iter=iter->next){
                continue;
            }
            return iter->elem;
        }
        void removeBack(){
            // printf("tail is %d\n",tail->elem);
            if(tail==NULL){
                // printf("inside tail==NULL\n");
                return;
            }
            if(head==tail){
                // printf("Deleting single element list\n");
                head=NULL;tail=NULL;length--;
                return;
            }
            Node* iter=head;
            for(iter=head;iter->next->next!=NULL;iter=iter->next){
                // printf("iter is %d",iter->elem);
                continue;
            }
            // printf("outside for loop\n");
            Node* temp=iter->next;
            iter->next=NULL;
            tail=iter;
            length--;
            delete temp;
            // printf("over and out\n");
        }
        void deleteNode(Node* ptr){
            //deletes the next node of ptr
            if(ptr->next->next==NULL || ptr->next==NULL|| ptr==NULL ){
                removeBack();
                printf("inside delete node%d\n",ptr->elem);
                printf("After deleting all nodes length of linked list is %d",length);
                return;
            }
            printf("imside delete node %d\n",ptr->elem);
            Node* temp=ptr->next;
            ptr->next=ptr->next->next;
            delete temp;
            length--;
            printf("After deleting all nodes length of linked list is %d",length);
        }
        void makeSet(){
            Node* iter=head;
            if(iter==NULL || iter->next==NULL){
                printf("After deleting all nodes length of linked list is %d",length);
                return;
            }
            while(iter->next!=NULL){
                if(iter->elem==iter->next->elem){
                    deleteNode(iter);
                }else{
                    iter=iter->next;
                }
            }
            printf("deleteNode: After deleting all nodes length of linked list is %d",length);
        }
        void mid(int* store){
            printf("\n inside mid and length is %d\n",length);
            class Node* iter=head;
            int cnt=0;
            while(cnt!=(length-1)/2){
                iter=iter->next;
                cnt++;
            }
            // printf("\n%d %d",store[0],store[1]);
            store[0]=iter->elem;
            store[1]=-1;
            printf("\n%d %d",store[0],store[1]);
            if(length%2==0){
                store[1]=iter->next->elem;
            }
            printf("\n%d %d",store[0],store[1]);
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
int getNthNode(LinkedList ll,int n){
    return ll.NthNode(n);
}
void removeDuplicate(class LinkedList &ll){
    ll.makeSet();
    printf("removeDuplicate: The length of new linked list is %d\n",len(ll));

}
int* middle(class LinkedList ll){
    // printf("\nInside middle\n");
    int* middleptr=(int*)malloc(2*sizeof(int));
    ll.mid(middleptr);
    return middleptr;
}
LinkedList* operator +(LinkedList ll1,LinkedList ll2){
    class LinkedList* res=new LinkedList();
    // res->addBack(50);
    // res->printList();
    int n1=len(ll1)-1;
    int n2=len(ll2)-1;
    int cin=0;
    while(n1!=-1 && n2!=-1){
        int tempsum=getNthNode(ll1,n1)+getNthNode(ll2,n2)+cin;
        res->addFront(tempsum%10);
        cin=tempsum/10;
        n1--;n2--;
    }
    if(n1>n2){
        while(n1!=-1){
            int tempsum=getNthNode(ll1,n1)+cin;
            res->addFront(tempsum%10);
            cin=tempsum/10;            
            n1--;
        }
    }else{
        while(n2!=-1){
            int tempsum=getNthNode(ll2,n2)+cin;
            res->addFront(tempsum%10);
            cin=tempsum/10;            
            n2--;
        }
    }
    if(cin!=0){
        res->addFront(cin);
    }
    return res;
}
bool isPalindrome(LinkedList ll){
    int n=len(ll);
    for(int i=0;i<n/2;i++){
        if(getNthNode(ll,i)!=getNthNode(ll,n-i-1)){
            return false;
        }
    }
    return true;
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
    int N;
    printf("Enter the index you want:");
    scanf("%d",&N);
    printf("The value in %dth node of linked list is %d\n",N,getNthNode(ll,N));
    // ll.removeBack();
    removeDuplicate(ll);
    printf("The length of new linked list is %d\n",ll.len());
    printf("The LinkedList without duplicate entry:-\n");
    print(ll);
    printf("The middle element of given linked list is ");
    int* midptr=(int*)malloc(2*sizeof(int));
    midptr=middle(ll);
    printf("\n%d %d",midptr[0],midptr[1]);
    free(midptr);
    printf("\n***************************************************\n");
    class LinkedList ll1;
    class LinkedList ll2;
    ll1.addBack(5);ll1.addBack(6);ll1.addBack(3);ll1.addBack(3);ll1.addBack(3);
    print(ll1);
    ll2.addBack(8);ll2.addBack(4);ll2.addBack(2);ll2.addBack(9);
    print(ll2);
    class LinkedList* result=new LinkedList();
    result=ll1+ll2;
    printf("The sum Linked List is \n");
    result->printList();
    class LinkedList ll3;
    ll3.addBack(3);ll3.addBack(3);ll3.addBack(4);ll3.addBack(33);
    printf("ll3 is %d\n",isPalindrome(ll3));
    
    printf("Bye!\n");
    return 0;
}
