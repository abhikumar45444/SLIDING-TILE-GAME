#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


//       index ->  0  1  2  3  4  5  6  7  8  9   10  11  12  13  14  15     
int board[4][4] = {3, 2, 4, 1, 7, 5, 6, 8, 14, 12, 13, 15, 9, 10, 11, 0 };

int WinningBoard[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
short int PlayerMove = 0;

int moves = 400;

void Display();
void Input(); // down - 80    up - 72    left - 75   right - 77
int ValidMove();
int CheckWin();


int main()
{
    int isWin = 0;
    do
    {
        Display();
        Input();
        isWin = CheckWin();
        if(isWin)
        {
            break;
        }
    } while (moves);
    
    if(isWin)
    {
        printf("\t----- HURRAY YOU WON --------\n");
    }
    else
    {
        printf("\t----- YOU LOSE!TRY AGAIN :-( --------\n");
    }
     printf("\n\n\n\n");

     return 0;
}

void Display()
{
    system("cls");

    printf("Remaing Moves: %d\n\n", moves);
    printf("__________________________________________\n");
    printf("|          |         |         |         |\n");
    printf("|    %2d    |   %2d    |   %2d    |   %2d    |\n",board[0][0], board[0][1],board[0][2], board[0][3]);
    printf("|__________|_________|_________|_________|\n");
    printf("|          |         |         |         |\n");
    printf("|    %2d    |   %2d    |   %2d    |   %2d    |\n", board[1][0], board[1][1],board[1][2], board[1][3]);
    printf("|__________|_________|_________|_________|\n");
     printf("|          |         |         |         |\n");
    printf("|    %2d    |   %2d    |   %2d    |   %2d    |\n", board[2][0], board[2][1],board[2][2], board[2][3]);
    printf("|__________|_________|_________|_________|\n");
     printf("|          |         |         |         |\n");
    printf("|    %2d    |   %2d    |   %2d    |   %2d    |\n", board[3][0], board[3][1],board[3][2], board[3][3]);
    printf("|__________|_________|_________|_________|\n");

    printf("\n");
}


void Input()
{
    while(1)
    {
        fflush(stdin);
        getch();
        PlayerMove = getch();
        int isValid = ValidMove();
        if(isValid)
        {
            int i, j, temp = 0;

            for (int ti = 0; ti < 4; ti++)
            {
                for (int tj = 0; tj < 4; tj++)
                {
                    if(board[ti][tj] == 0)
                    {
                        i = ti;
                        j = tj;
                        break;
                    }
                }
            }

            printf("i=%d j=%d\n", i, j);
            if (PlayerMove == 72)
            {
                int tempi = i, tempj = j;
                tempi--;
                temp = board[tempi][tempj];
                board[tempi][tempj] = board[i][j];
                board[i][j] = temp;
                
            }
            else if(PlayerMove == 80)
            {

                int tempi = i, tempj = j;
                tempi++;
                temp = board[tempi][tempj];
                board[tempi][tempj] = board[i][j];
                board[i][j] = temp;

            }
            else if(PlayerMove == 75)
            {

                int tempi = i, tempj = j;
                tempj--;
                temp = board[tempi][tempj];
                board[tempi][tempj] = board[i][j];
                board[i][j] = temp;

            }
            else if(PlayerMove == 77)
            {

                int tempi = i, tempj = j;
                tempj++;
                temp = board[tempi][tempj];
                board[tempi][tempj] = board[i][j];
                board[i][j] = temp;

            }
            moves--;
            return;
        }
        else
        {
            printf("Invalid Move!!\n");
        }
    }  
}


int ValidMove()
{
    int i= 0, j = 0;

    for (int ti = 0; ti < 4; ti++)
    {
        for (int tj = 0; tj < 4; tj++)
        {
            // printf("ti=%d tj=%d\n", ti, tj);
            if(board[ti][tj] == 0)
            {
                i = ti;
                j = tj;
                break;
            }
        }
    }

    // printf("i=%d j=%d\n", i, j);
    // printf("board[%d][%d]=%d\n", i, j , board[i][j]);

    if (PlayerMove == 72)
    {
        i--;
    }
    else if(PlayerMove == 80)
    {
        i++;
    }
    else if(PlayerMove == 75)
    {
        j--;
    }
    else if(PlayerMove == 77)
    {
        j++;
    }

    if((i >= 0 && i <= 3) && (j >= 0 && j <= 3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int CheckWin()
{
    int notWin = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(WinningBoard[i][j] != board[i][j])
            {
                notWin = 1;
                break;
            }
        }
        if(notWin)
        {
            break;
        }
    }
    

    if(!notWin)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}