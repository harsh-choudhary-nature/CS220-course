#include<stdio.h>
#define size 3
#define blank '_'
#define win 1
#define lose 0
#define draw -1
//int xmove(char board[size][size]);
int omove(char board[size][size]);
void printboard(char board[size][size]){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("\t%c",board[i][j]);
        }
        printf("\n");
    }
}
int isWin(char board[size][size], char position){
    int count;
    //checking for a row
    for(int i=0;i<size;i++){
        count=0;
        for(int j=0;j<size;j++){
            if(board[i][j]==position){count++;}
        }
        if(count==3){return 1;}
    }
    //checking for a col
    for(int i=0;i<size;i++){
        count=0;
        for(int j=0;j<size;j++){
            if(board[j][i]==position){count++;}
        }
        if(count==3){return 1;}
    }
    if((board[0][0]==position)&&(board[1][1]==position)&&(board[2][2]==position)){return 1;}
    if((board[0][2]==position)&&(board[1][1]==position)&&(board[2][0]==position)){return 1;}
    return 0;
}
/*takes board and
1. if the player x can win, returns position he should move so that he may win (in 1-9 numbers)
2. if player x cannnot win, then it returns 0(lose)
3. if the game is draw, then it returns -1(draw)
*/

int xmove(char board[size][size]){
    int success;
    int full=1;     //assume that board initially has no position to move
    int outcome=lose;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]!=blank){continue;}
            //reached here means board[i][j]==blank, so board is not full
            full=0;
            board[i][j]='x';
            if(isWin(board,'x')==1){        //base case here also
                board[i][j]=blank;
                return (i*3+j+1);
            }
            //by changing to x, player x did not win, so we check if it can win or not based on moves of player y
            //note that for x to win, result of player y should be lose, and else x will draw; so success either draw or lose is favorable to us
            success=omove(board);
            if(success==lose){
                board[i][j]=blank;
                return (i*3+j+1);
            }
            if(success==draw){
                outcome=draw;
            }
            board[i][j]=blank;
        }
    }
    if(full==1){        //Base case-means no more place to move
        return draw;
    }
    return outcome;
}
int omove(char board[size][size]){
    int success;
    int full=1;     //assume that board initially has no position to move
    int outcome=lose;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]!=blank){continue;}
            //reached here means board[i][j]==blank, so board is not full
            full=0;
            board[i][j]='o';
            if(isWin(board,'o')==1){        //base case here also
                board[i][j]=blank;
                return (i*3+j+1);
            }
            //by changing to x, player x did not win, so we check if it can win or not based on moves of player y
            //note that for x to win, result of player y should be lose, and else x will draw; so success either draw or lose is favorable to us
            success=xmove(board);
            if(success==lose){
                board[i][j]=blank;
                return (i*3+j+1);
            }
            if(success==draw){
                outcome=draw;
            }
            board[i][j]=blank;
        }
    }
    if(full==1){        //Base case-means no more place to move
        return draw;
    }
    return outcome;
}
int main(){
    char board[size][size]={{'x',blank,'x'},
                            {blank,blank,blank},
                            {'o',blank,blank}};
    printboard(board);
    printf("The next place for o is %d",omove(board));
    return 0;
}
