#include<stdio.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';



void resetBoard();
void printBoard();
int chekfreespaces();
void playermove();
void computermove();
char checkwinner();
void printwinner(char);


int main(){
    
    char winner = ' ';
    int response;

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();

        while (winner == ' ' && chekfreespaces() !=0)
        {
            printBoard();

            playermove();
            winner = checkwinner();
            if (winner != ' ' || chekfreespaces() == 0)
            {
                break;
            }

            computermove();
            winner = checkwinner();
            if (winner != ' ' || chekfreespaces() == 0)
            {
                break;
            }
        
        }
    
        printBoard();
        printwinner(winner);

        printf("\nWould you like to play again (1=yes/N):");
        scanf("%d", &response);
       
        
    } while (response == 1);
    
        printf("Thanks for playing!");

    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    

}
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}
int chekfreespaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--; 
            }
            
        }
        
    }
    return freeSpaces;

}
void playermove()
{
    int x; 
    int y;

    do
    {
        printf("Enter row#(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter columns#(1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ')
        {
        printf("INVALID MOVE!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    
    } while (board[x][y] != ' ');
    
    
}
void computermove()
{

    srand(time(0));
    int x;
    int y;

    if (chekfreespaces()>0)
    {
        do
        {
           x = rand() % 3;
           y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] =  COMPUTER ;      
    }
    else
    {
        printwinner(' ');
    }
    

}
char checkwinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
          return board[i][0];
        }
        
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
          return board[0][i];
        }
        
    }

    if (board[0][0]== board[1][1] && board[0][0] == board[2][2])
    {
       return board[0][0];
    }
    
    if (board[0][2]== board[1][1] && board[0][2] == board[2][0])
    {
       return board[0][2];
    }

    return ' ';
    }
void printwinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("You win!");
    }
    else if (winner == COMPUTER)
    {
         printf("You lose!");
    }
    else
    {
        printf("Its a draw");
    }
    

} 