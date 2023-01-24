#include "The_Game.h"

The_Game::The_Game()
{
    //ctor
}

The_Game::The_Game(int _boardSize)
{
    setUp(_boardSize);
}

void The_Game::setUp(int _boardSize)
{
    boardSize = _boardSize;
    myTurn = false;
    player1Points = 0, player2Points = 0, pPointsBefore = 0;

    board.resize(boardSize, vector<char>(boardSize,' '));
}

vector<vector<int> > The_Game::getEmptySpaces()
{
    return emptySpaces;
}

int The_Game::getNumberOfEmptySpaces()
{
    return emptySpaces.size();
}

bool The_Game::getTurn()
{
    return myTurn;
}

int The_Game::getp1Points()
{
    return player1Points;
}

int The_Game::getp2Points()
{
    return player2Points;
}

void The_Game::setPointsBefore()
{
    pPointsBefore = (getTurn() == true) ? getp2Points(): getp1Points();
}

int The_Game::getEmptySpace(int x, int y)
{
    return emptySpaces[x][y];
}

bool The_Game::didPlayerGainPoints()
{
    int pPoints = (getTurn() == true) ? getp2Points(): getp1Points();
    if(pPoints == pPointsBefore)
    {
        previousPlays.clear();
        myTurn = !myTurn;
        return false;
    }

    return true;
}

char The_Game::play(int index)
{
    int row = emptySpaces[index][0];
    int col = emptySpaces[index][1];

    srand(time(0));
    if(emptySpaces[index][3] == 0)
        board[row][col] = 'S';
    else if(emptySpaces[index][3] == 1)
        board[row][col] = 'O';
    else if(emptySpaces[index][3] == 2)
        board[row][col] = 'S';

    if(previousPlays.size() == 2)
    {
        if(previousPlays[0] == board[row][col] && previousPlays[1] == board[row][col])
            emptySpaces[index][2] = 0;
        else
            previousPlays[0] = previousPlays[1], previousPlays[1] = board[row][col];
    }
    else
        previousPlays.push_back(board[row][col]);

    if(myTurn == true)
        player2Points += emptySpaces[index][2];
    else
        player1Points += emptySpaces[index][2];

    return board[row][col];
}

void The_Game::checkEmptySpaces()
{
    emptySpaces.clear();
    int index = 0;

    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
        {
            if(board[i][j] == ' ')
            {
                emptySpaces.push_back(checkPotentialPoints(i,j,index));
                index++;
            }
        }
    }
}

vector<int> The_Game::checkPotentialPoints(int i, int j,int index)
{
    vector<int> temp(4);
    int pointsForS = 0;
    int pointsForO = 0;

    temp[0] = i;
    temp[1] = j;

    VerticalCheck(i,j,pointsForO,pointsForS);
    HorizontalCheck(i,j,pointsForO,pointsForS);
    DiagonalCheckLeftToRight(i,j,pointsForO,pointsForS);
    DiagonalCheckRightToLeft(i,j,pointsForO,pointsForS);

    if(pointsForO > pointsForS)
    {
        temp[2] = pointsForO;
        temp[3] = 1;
    }
    else if(pointsForS > pointsForO)
    {
        temp[2] = pointsForS;
        temp[3] = 2;
    }
    else if(pointsForO == 0 && pointsForS == 0)
    {
        temp[2] = 0;
        temp[3] = 0;
    }
    else if(pointsForO == pointsForS)
    {
        srand(time(NULL));
        int randomNumber = rand()%(2);
        temp[2] = (randomNumber == 0) ? pointsForO : pointsForS;
        temp[3] = randomNumber + 1;
    }

    return temp;
}

void The_Game::VerticalCheck(int x,int y,int &PointsForO,int &PointsForS)
{
    if(x+1 < boardSize - 1 && x+2 <= boardSize - 1 && board[x+1][y] == 'O' && board[x+2][y] == 'S')
        PointsForS++;

    if(x-1 > 0 && x-2 >= 0 && board[x-1][y] == 'O' && board[x-2][y] == 'S')
        PointsForS++;

    if(x+1 <= boardSize - 1 && x-1 >= 0 && board[x+1][y] == 'S' && board[x-1][y] == 'S')
        PointsForO++;
}

void The_Game::HorizontalCheck(int x,int y,int &PointsForO,int &PointsForS)
{
    if(y+1 < boardSize - 1 && y+2 <= boardSize - 1 && board[x][y+1] == 'O'&& board[x][y+2] == 'S')
        PointsForS++;

    if(y-1 > 0 && y-2 >= 0 && board[x][y-1] == 'O' && board[x][y-2] == 'S')
        PointsForS++;

    if(y+1 <= boardSize - 1 && y-1 >= 0 && board[x][y+1] == 'S' && board[x][y-1] == 'S')
        PointsForO++;
}

void The_Game::DiagonalCheckLeftToRight(int x,int y,int &PointsForO,int &PointsForS)
{
    if(x+1 < boardSize - 1 && y+1 < boardSize - 1 && x+2 <= boardSize - 1 && y+2 <= boardSize - 1 && board[x+1][y+1] == 'O' && board[x+2][y+2] == 'S')
        PointsForS++;

    if(x-1 > 0 && y-1 > 0 && x-2 >= 0 && y-2 >= 0 && board[x-1][y-1] == 'O' && board[x-2][y-2] == 'S')
        PointsForS++;

    if(x+1 <= boardSize - 1 && y+1 <= boardSize - 1 && x-1 >= 0 && y-1 >= 0 && board[x+1][y+1] == 'S' && board[x-1][y-1] == 'S')
        PointsForO++;
}

void The_Game::DiagonalCheckRightToLeft(int x,int y,int &PointsForO,int &PointsForS)
{
    if(x-1 > 0 && y+1 < boardSize - 1 && x-2 >= 0 && y+2 <= boardSize - 1 && board[x-1][y+1] == 'O' && board[x-2][y+2] == 'S')
        PointsForS++;

    if(x+1 < boardSize - 1 && y-1 > 0 && x+2 <= boardSize - 1 && y-2 >= 0 && board[x+1][y-1] == 'O' && board[x+2][y-2] == 'S')
        PointsForS++;

    if(x-1 >= 0 && y+1 <= boardSize - 1 && x+1 <= boardSize - 1 && y-1 >= 0 && board[x-1][y+1] == 'S' && board[x+1][y-1] == 'S')
        PointsForO++;
}

bool The_Game::CheckIfGameIsOver()
{
    checkEmptySpaces();
    if(emptySpaces.size() == 0)
        return true;

    return false;
}
