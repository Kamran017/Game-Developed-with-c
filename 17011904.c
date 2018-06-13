//KAMRAN BALAYEV 17011904
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}
int printMatrix(char gameBoard[100][100],int row,int column){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            printf("| %c |" ,gameBoard[i][j]);
        };
        printf("\n");
    };
}
//recursive function: purpose of this function is to find the same number pairs and make their places empty
//and slide down elements
void recursion(char gameBoard[100][100],int row,int column,int score){
    int i,j,exit,count=0,end,endFlag;
    char flag;
    endFlag=0;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(gameBoard[i][j]==gameBoard[i+1][j]){
                gameBoard[i][j]=' ';
                score++;
                if(gameBoard[i+1][j]==gameBoard[i+2][j]){
                    if(gameBoard[i+2][j]==gameBoard[i+3][j]){
                        gameBoard[i+3][j]=' ';
                        score++;
                    }
                    gameBoard[i+2][j]=' ';
                    score++;
                }
                else if(gameBoard[i+1][j]==gameBoard[i+1][j+1]){
                    if(gameBoard[i+1][j+1]==gameBoard[i+1][j+2]){
                        gameBoard[i+1][j+2]=' ';
                        score++;
                    }
                    else if(gameBoard[i+1][j+1]==gameBoard[i+2][j+1]){
                        gameBoard[i+2][j+1]=' ';
                        score++;
                    }
                    gameBoard[i+1][j+1]=' ';
                    score++;
                }
                else if(gameBoard[i+1][j]==gameBoard[i+1][j-1]){
                    if(gameBoard[i+1][j-1]==gameBoard[i+1][j-2]){
                        gameBoard[i+1][j-2]=' ';
                        score++;
                    }
                    else if(gameBoard[i+1][j-1]==gameBoard[i+2][j-1]){
                        gameBoard[i+2][j-1]=' ';
                        score++;
                    }
                    gameBoard[i+1][j-1]=' ';
                    score++;
                }
                else if(gameBoard[i+1][j]==gameBoard[i-1][j+1]){
                    if(gameBoard[i+1][j]==gameBoard[i-1][j+2]){
                        gameBoard[i-1][j+2]=' ';
                        score++;
                    }
                    gameBoard[i-1][j+1]=' ';
                    score++;
                }
                gameBoard[i+1][j]=' ';
                score++;
            }

            else if(gameBoard[i][j]==gameBoard[i][j+1]){
                gameBoard[i][j]=' ';
                score++;
                if(gameBoard[i][j+1]==gameBoard[i][j+2]){
                    if(gameBoard[i][j+2]==gameBoard[i][j+3]){
                        gameBoard[i][j+3]=' ';
                        score++;
                    }
                    gameBoard[i][j+2]=' ';
                    score++;
                }
                else if(gameBoard[i][j+1]==gameBoard[i+1][j+1]){
                    if(gameBoard[i+1][j+1]==gameBoard[i+2][j+1]){
                        gameBoard[i+2][j+1]=' ';
                        score++;
                    }
                    else if(gameBoard[i+1][j+1]==gameBoard[i+2][j+1]){
                        gameBoard[i+2][j+1]=' ';
                        score++;
                    }
                    else if(gameBoard[i+1][j+1]==gameBoard[i+1][j+2]){
                       gameBoard[i+1][j+2]=' ';
                       score++;
                    }
                    gameBoard[i+1][j+1]=' ';
                    score++;
                }
                gameBoard[i][j+1]=' ';
                score++;
            }
        }
    }
    delay(1);
    printf("\n");
    printMatrix(gameBoard,row,column);printf("\n");
    //slide down elements of matrix in order to add new random values
    for(j=0;j<column;j++){
        for(i=0;i<row;i++){
            count=i;
            if(gameBoard[i+1][j]==' '){
                count++;
                while(count>0){
                    if(gameBoard[count-1][j]!=' '){
                        gameBoard[count][j]=gameBoard[count-1][j];
                        gameBoard[count-1][j]=' ';
                    }
                    count--;
                };
            };
        };
    };
    delay(1);
    printf("\n");
    printMatrix(gameBoard,row,column);printf("\n");
    //continue or exit
    printf("\nIf you want to continue the game please enter 1 otherwise enter 0: ");
    scanf("%d",&end);
    //control the matrix in order to find same numbers and call function
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if((gameBoard[i][j]==gameBoard[i+1][j]) || (gameBoard[i][j]==gameBoard[i][j+1]) ){
                if((gameBoard[i][j]!=' ') && (gameBoard[i+1][j]!=' ')&& (gameBoard[i][j+1]!=' ')){
                     return recursion(gameBoard,row,column,score);
                }
                else{
                    if (end==1){
                        return newRandomElements(gameBoard,row,column,score);
                    }
                    else if(end==0){
                        return printf("\nYour score is: %d\n",score*score);
                    }

                }
            }
        }
    }
    score--;
    selectLocations(gameBoard,row,column,score);
}
void newRandomElements (char gameBoard[100][100],int row,int column,int score){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(gameBoard[i][j]==' '){
                gameBoard[i][j]=(char)('0'+rand()%('9'-'0'+1));
            }
        }
    }
    return recursion(gameBoard,row,column,score);
}

void  selectLocations(char gameBoard[100][100],int row,int column,int score){
    int i,j,flag,rowChange,columnChange,secondRow,secondColumn;
    printf("\n");
    printf("Please select the first row and column numbers consequently:\n");
    scanf("%d %d",&rowChange,&columnChange);
    printf("Please select the second row and column numbers consequently:\n");
    scanf("%d %d",&secondRow,&secondColumn);
    //change elements of matrix
    flag=gameBoard[rowChange-1][columnChange-1];
    gameBoard[rowChange-1][columnChange-1]=gameBoard[secondRow-1][secondColumn-1];
    gameBoard[secondRow-1][secondColumn-1]=flag;
    //call recursion function
    return recursion(gameBoard,row,column,score);

}

int main()
{
    int i,j,k,row,column,flag,score=0;
    char gameBoard[100][100];
    printf("Welcome, Please enter the row and column number: \n");
    scanf("%d\n%d",&row,&column);printf("\n");
    //assign random values to the matrix
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            gameBoard[i][j]=(char)('0'+rand()%('9'-'0'+1));;
            printf("| %c |" ,gameBoard[i][j]);
        };
        printf("\n");
    };
    recursion(gameBoard,row,column,score);
}
