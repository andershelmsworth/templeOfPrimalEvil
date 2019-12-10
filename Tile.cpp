#include "Tile.hpp"
#include "Pixel.hpp"

Tile::Tile()
{
    board = new Pixel** [3];
    for (int i = 0; i < 3; i++) {
        board[i] = new Pixel*[3];
        for (int j = 0; j < 3; j++) {
            board[i][j] = new Pixel();
        }
    }
}

Tile::~Tile()
{
    //Deallocate board
    Pixel*** currentBoard = getBoard();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            delete[] currentBoard[i][j];
        }
        delete[] currentBoard[i];
    }
    delete[] currentBoard;
}

Pixel*** Tile::getBoard()
{
    return this->board;
}

void Tile::setBoard(Pixel*** incBoard)
{
    this->board = incBoard;
}

void Tile::draw()
{
    Pixel*** currentBoard = getBoard();
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //currentBoard[i][j].setCenter(static_cast<char>(j));
            std::cout << currentBoard[i][j]->getNorthWest();
            std::cout << currentBoard[i][j]->getNorth();
            std::cout << currentBoard[i][j]->getNorthEast();
        }
        std::cout << std::endl;

        for (int j = 0; j < 3; j++) {
            //currentBoard[i][j].setCenter(static_cast<char>(j));
            std::cout << currentBoard[i][j]->getEast();
            std::cout << currentBoard[i][j]->getCenter();
            std::cout << currentBoard[i][j]->getWest();
        }
        std::cout << std::endl;

        for (int j = 0; j < 3; j++) {
            //currentBoard[i][j].setCenter(static_cast<char>(j));
            std::cout << currentBoard[i][j]->getSouthEast();
            std::cout << currentBoard[i][j]->getSouth();
            std::cout << currentBoard[i][j]->getSouthWest();
        }
        std::cout << std::endl;
    }
}
