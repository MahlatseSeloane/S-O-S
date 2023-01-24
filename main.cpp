#include "The_Game.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int player1(int numberOfEmptySpaces);
int player2(vector<vector<int> > emptySpaces);

int main()
{
    int boardSize;

    ifstream inData;
    ofstream outData;
    inData.open("input.txt");
    outData.open("gameResults.txt");

    while(inData >> boardSize)
    {
        if(boardSize >= 3)
        {
            outData << "size " << boardSize << endl;

            The_Game game(boardSize);

            int index;
            char ch;

            while(game.CheckIfGameIsOver() == false)
            {
                outData << "player" << game.getTurn() + 1 << ": ";

                if(!game.getTurn())
                    index = player1(game.getNumberOfEmptySpaces());
                else if(game.getTurn())
                    index = player2(game.getEmptySpaces());

                game.setPointsBefore();
                char ch = game.play(index);

                outData << "r" << game.getEmptySpace(index,0) << "c" << game.getEmptySpace(index,1) << " " << ch << endl;

                if(game.didPlayerGainPoints())
                    outData << "player" << game.getTurn() + 1 << ": point scored" << endl;
            }

            if(game.getp1Points() == game.getp2Points())
                outData << "draw";
            else
            {
                outData << "winner: player";
                (game.getp1Points() > game.getp2Points()) ? outData << "1\nscore: " << game.getp1Points() << "," << game.getp2Points()
                : outData << "2\nscore: " << game.getp2Points() << "," << game.getp1Points();

            }

            outData << endl << endl;
        }
    }

    inData.close();
    outData.close();

    return 0;
}

int player1(int numberOfEmptySpaces)
{
    srand(time(0));
    return rand()%(numberOfEmptySpaces);
}

int player2(vector<vector<int> > emptySpaces)
{
    int index = 0;

    for(int i = 0; i < emptySpaces.size(); i++)
        if(emptySpaces[i][2] > emptySpaces[index][2])
            index = i;

    srand(time(0));
    index = (emptySpaces[index][2] == 0) ? rand()%emptySpaces.size(): index;

    return index;
}
