#include<stdio.h>
class Vector{
private:
    int x;
    int y;
    int z;
public:
    Vector(int,int,int);
    Vector();
    void printVector();
    int sqNorm();
    int sqdistance(Vector);
    Vector operator +(Vector);  //operator must be any valid c++ operator only
    int operator *(Vector);
    Vector operator -(Vector); 
    Vector operator ++();
    Vector operator --();
    Vector operator *(int);     //scaling the vector
    Vector crossProduct(Vector);
    ~Vector();                  //destructor
};
Vector::Vector(int a,int b,int c){
    x=a;y=b;z=c;
}
Vector::Vector(){
    x=0;y=0;z=0;
}
void Vector::printVector(){
    printf("(x,y,z)=(%d,%d,%d)\n",x,y,z);
}
int Vector::sqNorm(){
    return(x*x+y*y+z*z);
}
int Vector::sqdistance(Vector v1){
    return((x-v1.x)*(x-v1.x)+(y-v1.y)*(y-v1.y)+(z-v1.z)*(z-v1.z));
}
Vector Vector::operator +(Vector v1){
    Vector v2(0,0,0);
    v2.x=x+v1.x;
    v2.y=y+v1.y;
    v2.z=z+v1.z;
    return v2;
}
Vector Vector::operator -(Vector v1){
    Vector v2(0,0,0);
    v2.x=x-v1.x;
    v2.y=y-v1.y;
    v2.z=z-v1.z;
    return v2;
}
Vector Vector::operator ++(){
    x++;y++;z++;
    Vector v2(x,y,z);
    return v2;
}
Vector Vector::operator --(){
    x--;y--;z--;
    Vector v2(x,y,z);
    return v2;
}
int Vector::operator *(Vector v1){
    return(x*v1.x+y*v1.y+z*v1.z);
}
Vector Vector::operator *(int scale){
    Vector v2(0,0,0);
    v2.x=x*scale;v2.y=y*scale;v2.z=z*scale;
    return v2;
}
Vector Vector::crossProduct(Vector v1){
    Vector v3;      //when not passing parameter, don't put parantheses
    v3.x=(v1.y)*(z)-(y)*(v1.z);
    v3.y=-1*((v1.x)*(z)-(x)*(v1.z));
    v3.z=(v1.x)*(y)-(x)*(v1.y);
    return v3;
}
Vector::~Vector(){
    //printf("Destroying vector object");
    //this->printVector();
}
int main(){
    Vector* V=new Vector(2,5,10);
    V->printVector();
    delete V;
    Vector v1(3,4,5);
    v1.printVector();
    printf("\nThe squared norm of vector is %d",v1.sqNorm());
    Vector v2(3,8,5);
    v2.printVector();
    printf("\nThe squared distance between vectors is %d",v1.sqdistance(v2));
    printf("\nThe dot product between vectors is %d",v1*v2);
    printf("\nThe sum of vectors is ");
    (v1+v2).printVector();
    printf("\nThe difference between vectors is ");
    (v1-v2).printVector();
    printf("\nThe cross product between vectors is ");
    (v1.crossProduct(v2)).printVector();
    printf("Incremented vector v1 is ");
    Vector vr=++v1;
    vr.printVector();
    printf("Decremented vector v1 is ");
    vr=--v1;
    vr.printVector();
    printf("two times scaled vector v1 is ");
    vr=v1*2;
    vr.printVector();
    return 0;
}