#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void createBoard();
    sf::Vector2f snapToGrid(const sf::Vector2f& position);
    sf::Vector2f previousPosition;
    sf::Texture chessPieceTexture;


    sf::RenderWindow window;
    static constexpr int boardSize = 8;
    static constexpr int squareSize = 100;

    std::vector<Piece> pieces;
    Piece* selectedPiece = nullptr;
    bool isDragging = false;
};