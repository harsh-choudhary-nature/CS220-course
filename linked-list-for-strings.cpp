#include<stdio.h>
class letter{
private:
    char c;
    letter* next;
    letter(){
        next=NULL;
    }
    letter(char entry){
        c=entry;
        next=NULL;
    }
    letter(char entry,letter* nxt){
        c=entry;
        next=nxt;
    }
    friend class word;
};
class word{
private:
    letter* beg;
    int length;
public:
    word(){
        beg=NULL;
        length=0;
    }
    // word(char c1,letter* nxt){
    //     beg=new letter(c1,nxt);
    //     nextw=NULL;
    // }
    // word(char c1,letter* nxt,word* nextword){
    //     beg=new letter(c1,nxt);
    //     nextw=nextword;
    // }
    void addLetterFront(char let){
        beg=new letter(let,beg);
        length++;
    }
    void removeLetterFront(){
        if(beg==NULL){
            return;
        }
        letter* temp=beg;
        beg=beg->next;
        delete temp;
        length--;
    }
    void addLetterBack(char let){
        if(beg==NULL){
            beg=new letter(let,NULL);
            length++;
            return;
        }
        letter* iter=beg;
        for(;iter->next!=NULL;iter=iter->next){
            continue;
        }
        iter->next=new letter(let,NULL);
        length++;
    }
    void removeLetterBack(){
        if(beg==NULL){
            return;
        }
        if(beg->next==NULL){
            letter* temp=beg;
            beg=NULL;
            delete temp;
            length--;
        }
        letter* iter=beg;
        for(;iter->next->next!=NULL;iter=iter->next){
            continue;
        }
        letter* temp=iter->next;
        iter->next=NULL;
        delete temp;
        length--;
    }
    void print(){
        letter* iter=beg;
        while(iter!=NULL){
            printf("%c",iter->c);
            iter=iter->next;
        }
        printf("\n");
    }
    friend class Snode;
};
class Snode{
private:
    word w;
    Snode* nextw;
    Snode(){
        nextw=NULL;
    }
    Snode(word wor){
        w=wor;
        nextw=NULL;
    }
    Snode(word wor,Snode* nxtw){
        w=wor;
        nextw=nxtw;
    }
    friend class sentence;
};
class sentence{
private:
    Snode* head;
    int len;
public:
    sentence(){
        len=0;
        head=NULL;
    }
    void addWordFront(word w){
        head=new Snode(w,head);
        len++;
    }
    void addWordBack(word w){
        if(head==NULL){
            head=new Snode(w,NULL);
            len++;
            return;
        }
        Snode* iter=head;
        for(;iter->nextw!=NULL;iter=iter->nextw){
            continue;
        }
        iter->nextw=new Snode(w,NULL);
        len++;
    }
    void removeFront(){
        if(head==NULL){
            return;
        }
        Snode* temp=head;
        head=head->nextw;
        delete temp;
        len--;
    }
    void removeBack(){
        if(head==NULL){
            return;
        }
        if(head->nextw==NULL){
            // Snode* temp=head;
            // delete temp;
            delete head;
            head=NULL;
            len--;
        }
        Snode* iter=head;
        for(;iter->nextw->nextw!=NULL;iter=iter->nextw){
            continue;
        }
        delete iter->nextw;
        iter->nextw=NULL;
        len--;
    }
    void print(){
        Snode* iter=head;
        for(;iter!=NULL;iter=iter->nextw){
            iter->w.print();
        }
        printf("\n");
    }
};
int main(){
    word firstname;
    firstname.addLetterFront('H');
    firstname.addLetterBack('a');
    firstname.addLetterBack('r');
    firstname.addLetterBack('s');
    firstname.addLetterBack('h');
    firstname.print();
    word lastname;
    lastname.addLetterBack('C');
    lastname.addLetterBack('h');
    lastname.addLetterBack('o');
    lastname.addLetterBack('u');
    lastname.addLetterBack('d');
    lastname.addLetterBack('h');
    lastname.addLetterBack('a');
    lastname.addLetterBack('r');
    lastname.addLetterBack('y');
    lastname.print();
    sentence name;
    name.addWordBack(firstname);
    name.addWordBack(lastname);
    name.print();
    return 0;
}