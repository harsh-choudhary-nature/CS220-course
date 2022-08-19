#include<iostream>
using namespace std;
template<class t>
void search(t arr[],t element,int ar_size){
    //linear search
    bool flagg=true;
    for(int i=0;i<ar_size;i++){
        if(arr[i]==element){
            cout<<"Found at index"<<i<<endl;
            flagg=false;
            break;
        }
    }
    if(flagg){
        cout<<"Not Found"<<endl;
    }
}
int main(){
    const int ar_size=7;
    int a[ar_size]={1,2,3,4,5,6,7};
    search(a,10,ar_size);   
    return 0;
}