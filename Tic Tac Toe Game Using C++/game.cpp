#include <iostream>
using namespace std;

char display[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int col;
char token = 'x';
string player1 = "";
string player2 = "";
bool draw = false;

void nextline()
{
    cout << endl;
}

void game()
{
    cout << "     |    |    " << endl;
    cout << "   " << display[0][0] << " |"
         << "  " << display[0][1] << " | " << display[0][2] << endl;
    cout << " ____|____|___ " << endl;
    cout << "     |    |    " << endl;
    cout << "   " << display[1][0] << " |"
         << "  " << display[1][1] << " | " << display[1][2] << endl;
    cout << " ____|____|___ " << endl;
    cout << "     |    |    " << endl;
    cout << "   " << display[2][0] << " |"
         << "  " << display[2][1] << " | " << display[2][2] << endl;
    cout << "     |    |    " << endl;
}

void invalid()
{
    int digit;

    if (token == 'x')
    {
        cout << player1 << " Please Enter The Place You Want To Mark: ";
        cin >> digit;
    }
    if (token == '0')
    {
        cout << player2 << " Please Enter The Place You Want To Mark: ";
        cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        col = 0;
    }
    if (digit == 2)
    {
        row = 0;
        col = 1;
    }
    if (digit == 3)
    {
        row = 0;
        col = 2;
    }
    if (digit == 4)
    {
        row = 1;
        col = 0;
    }
    if (digit == 5)
    {
        row = 1;
        col = 1;
    }
    if (digit == 6)
    {
        row = 1;
        col = 2;
    }
    if (digit == 7)
    {
        row = 2;
        col = 0;
    }
    if (digit == 8)
    {
        row = 2;
        col = 1;
    }
    if (digit == 9)
    {
        row = 2;
        col = 2;
    }
    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid Entry." << endl;
    }

    if (token == 'x' && display[row][col] != 'x' && display[row][col] != '0')
    {
        display[row][col] = 'x';
        token = '0';
    }
    else if (token == '0' && display[row][col] != 'x' && display[row][col] != '0')
    {
        display[row][col] = '0';
        token = 'x';
    }
    else
    {
        cout << "There Is No Empty Space!." << endl;
        invalid();
    }
}

bool win()
{
    for (int i = 0; i < 3; i++)
    {
        if (display[i][0] == display[i][1] && display[i][0] == display[i][2] || display[0][i] == display[1][i] && display[0][i] == display[2][i])
        {
            return true;
        }
    }
    if (display[0][0] == display[1][1] && display[1][1] == display[2][2] || display[0][2] == display[1][1] && display[1][1] == display[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            if (display[i][j] != 'x' && display[i][j] != '0')
            {
                return false;
            }
        }
    }
    draw = true;
    return false;
}

int main()
{
    nextline();
    cout << "*** TIC TAC TOE GAME USING C++ ***" << endl;
    nextline();

    cout << "Enter The Name of First Player : ";
    cin >> player1;
    cout << "Enter The Name of Second Player : ";
    cin >> player2;
    nextline();

    cout << player1 << " Will Play The First Chance." << endl;
    cout << player2 << " Will Play The Second Chance." << endl;
    nextline();

    while (!win())
    {
        game();
        invalid();
        win();
    }

    if (token == 'x' && draw == false)
    {
        nextline();
        cout <<"***" <<player2 << " WINS ***" << endl;
    }
    else if (token == '0' && draw == false)
    {
        nextline();
        cout << "***"<<player1 << " WINS ***" << endl;
    }
    else
    {
        nextline();
        cout << "*** DRAW ***";
    }
}