#ifndef THE_GAME_H
#define THE_GAME_H

#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class The_Game
{
public:
    The_Game();
    The_Game(int _boardSize);
    void setUp(int boardSize);

    int getNumberOfEmptySpaces();
    bool getTurn();
    int getp1Points();
    int getp2Points();
    void setPointsBefore();
    int getEmptySpace(int x, int y);
    bool didPlayerGainPoints();
    char play(int index);

    vector<vector<int> > getEmptySpaces();

    void checkEmptySpaces();
    vector<int> checkPotentialPoints(int i,int j,int index);
    void VerticalCheck(int x,int y,int &PointsForO,int &PointsForS);
    void HorizontalCheck(int x,int y,int &PointsForO,int &PointsForS);
    void DiagonalCheckRightToLeft(int x,int y,int &PointsForO,int &PointsForS);
    void DiagonalCheckLeftToRight(int x,int y,int &PointsForO,int &PointsForS);
    bool CheckIfGameIsOver();

private:
    vector<vector<char> > board;
    vector<char> previousPlays;
    vector<vector<int> > emptySpaces;

    int player1Points, player2Points, pPointsBefore;
    int boardSize;

    bool myTurn = true;
};

#endif // THE_GAME_H
