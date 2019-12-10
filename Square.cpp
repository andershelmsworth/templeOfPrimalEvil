#include "Tile.hpp"
#include "Square.hpp"

Square::Square()
{
    squareBoard = new Tile** [3];
    for (int i = 0; i < 3; i++) {
        squareBoard[i] = new Tile*[3];
        for (int j = 0; j < 1; j++) {
            squareBoard[i][j] = new Tile;
        }
    }
    /*
    northWest = &squareBoard[0][0];
    setNorth(&squareBoard[0][1]);
    setNorthEast(&squareBoard[0][2]);
    setWest(&squareBoard[1][0]);
    setCenter(&squareBoard[1][1]);
    setEast(&squareBoard[1][2]);
    setSouthWest(&squareBoard[2][0]);
    setSouth(&squareBoard[2][1]);
    setSouthEast(&squareBoard[2][2]);
    */

}

Square::~Square()
{
    //Deallocate board
    Tile*** currentBoard = getSquareBoard();
    for (int i = 0; i < 3; i++) {
        delete[] currentBoard[i];
    }
    delete[] currentBoard;
}

Tile*** Square::getSquareBoard()
{
    return this->squareBoard;
}

void Square::setSquareBoard(Tile*** incSquareBoard)
{
    this->squareBoard = incSquareBoard;
}

void Square::draw()
{
    Tile*** currentBoard = getSquareBoard();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            //currentBoard[i][j].setCenter(static_cast<char>(j));
            currentBoard[i][j]->draw();
        }
    }
}
