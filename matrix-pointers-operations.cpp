#include<stdio.h>
#include<stdlib.h>

void printMatrix(int** ptr1,int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d  ",ptr1[i][j]);
        }
        printf("\n");
    }
}
int** multMatrix(int** ptr1,int** ptr2,int row1,int col1,int row2,int col2){
    if(col1!=row2){
        // printf("\ninvalid");
        return NULL;
    }
    int** ptrres=(int**)malloc(row1*sizeof(int*));
    for(int i=0;i<row1;i++){
        ptrres[i]=(int*)calloc(col2,sizeof(int));
        // printf("\nerror");
        for(int j=0;j<col1;j++){
            for(int k=0;k<row2;k++){
                ptrres[i][j]+=ptr1[i][k]*ptr2[k][j];
                // printf("\nerror");

            }
        }
    }
    return ptrres;
}
int** addMatrix(int** ptr1,int** ptr2,int row1,int col1,int row2,int col2){
    if((row1!=row2) || (col1!=col2)){
        return NULL;
    }
    int** ptrres=(int**)malloc(row1*sizeof(int*));
    for(int i=0;i<row1;i++){
        ptrres[i]=(int*)malloc(col1*sizeof(int));
        for(int j=0;j<col1;j++){
            ptrres[i][j]=ptr1[i][j]+ptr2[i][j];
        }
    }
    return ptrres;
}
int** formMatrix(int rows,int cols){
    int** ptr1=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        ptr1[i]=(int*)malloc(cols*sizeof(int));
        for(int j=0;j<cols;j++){
            printf("\nEnter:");
            scanf("%d",&ptr1[i][j]);
        }
        // ptr1[i]=ptr2; 
        // free(ptr2);
    }
    // printf("hello%d",ptr1[0][0]);
    return ptr1;
}
int main(){
    int rows1,cols1;
    printf("\nEnter the number of rows:");
    scanf("%d",&rows1);
    printf("\nEnter the number of columns:");
    scanf("%d",&cols1);
    int** pmtr1=formMatrix(rows1,cols1);
    printf("\nPrinting your matrix1!\n");
    printMatrix(pmtr1,rows1,cols1);
    
    int rows2,cols2;
    printf("\nEnter the number of rows:");
    scanf("%d",&rows2);
    printf("\nEnter the number of columns:");
    scanf("%d",&cols2);
    int** pmtr2=formMatrix(rows2,cols2);
    printf("\nPrinting your matrix2!\n");
    printMatrix(pmtr2,rows2,cols2);
    
    int** sumMatrix=addMatrix(pmtr1,pmtr2,rows1,cols1,rows2,cols2);
    if(sumMatrix==NULL){
        printf("\nInvalid orders");
    }else{
        printf("\nPrinting your matrix sum!\n");
        printMatrix(sumMatrix,rows2,cols2);
    }
    // printf("\nError");
    int** prodMatrix=multMatrix(pmtr1,pmtr2,rows1,cols1,rows2,cols2);
    if(multMatrix==NULL){
        printf("\nInvalid orders");
    }else{
        printf("\nPrinting your matrix product!\n");
        printMatrix(prodMatrix,rows2,cols2);
    }
    free(pmtr1);
    free(pmtr2);
    free(sumMatrix);
    free(prodMatrix);
    return 0;
}