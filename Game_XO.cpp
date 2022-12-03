# include <iostream>
using namespace std;
// it is ok 
void board(char  xo[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "|" << xo[i][j] << ' ';
        }
        cout << "\n -------------- \n ";
    }
}
// for the equel of rows and cols 
bool equel(char x, char y, char z)
{
    if ((x == y) && (x == z) && (x != ' '))
        return true; 
    else
        return false;
}


// to check who is the winner x player or o player  
// 2 x winner 
// -2 o winner 
// 0 tie cas 
// 1  no winner
char check_winner(char xo[3][3])
{

    // for the change of the rows 
    for (int i = 0; i < 3; i++)
    {
        if (equel(xo[i][0], xo[i][1], xo[i][2]))
        {
            return  xo[i][0] == 'X' ? 2 : -2;
        }
    }
    // for the change of the cols
    for (int j = 0; j < 3; j++)
    {
        if (equel(xo[0][j], xo[1][j], xo[2][j]))
        {
            return xo[0][j] == 'X' ? 2 : -2;
        }
    }
    // for diameter one 
    if (equel(xo[0][0], xo[1][1], xo[2][2]))
    {
        return xo[0][0] == 'X' ? 2 : -2;
    }
    // for diameter two 
    if (equel(xo[0][2], xo[1][1], xo[2][0]))
    {
        return xo[0][2] == 'X' ? 2 : -2;
    }

    // for tie case 
    bool tie = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (xo[i][j] == ' ')
            {
                tie = false;
            }
        }

    }
    if (tie)
        return 0;
    else
        return 1;
}

int main()
{
    char xo[3][3] = { {' ',' ',' ' } , {' ' ,' ',' '} ,{' ',' ' ,' '} };
    int x, y;
    char player = 'X';
    bool winner = false;
    while (!winner)
    {
        cin >> x >> y;
        if (xo[x][y] == ' ')
        {
            xo[x][y] = player;
            board(xo);
            if (player == 'X')
                player = 'O';
            else
                player = 'X';
        }
        else
            cout << " the filed is not empty \n";
        winner = check_winner(xo) != 1;
    }

    int result = check_winner(xo);
    if (result == 0)
        cout << " tie case ";
    else
        cout << ((result == 2) ? "X" : "O") << " : the winner /n";

}