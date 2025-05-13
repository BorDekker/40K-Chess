#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
    : window(sf::VideoMode(boardSize* squareSize, boardSize* squareSize), "Simple Chess") {
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(50, 50), "Selectable", "White"); //White Rook left
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(150, 50), "Selectable", "White"); // White Knight left
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(250, 50), "Selectable", "White"); // White Bishop left
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(350, 50), "Selectable", "White"); // White Queen
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(450, 50), "Selectable", "White"); // White King
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(550, 50), "Selectable", "White"); // White Bishop right
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(650, 50), "Selectable", "White"); // White Knight right
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(750, 50), "Selectable", "White"); // White Rook right

    // White pawns
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(50, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(150, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(250, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(350, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(450, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(550, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(650, 150), "Selectable", "White");
    pieces.emplace_back(sf::Color::Blue, sf::Vector2f(750, 150), "Selectable", "White");

    pieces.emplace_back(sf::Color::Red, sf::Vector2f(50, 750), "Selectable", "Black"); // Black Rook left
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(150, 750), "Selectable", "Black"); // Black Knight left
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(250, 750), "Selectable", "Black"); // Black Bishop left
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(350, 750), "Selectable", "Black"); // Black Queen
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(450, 750), "Selectable", "Black"); // Black King
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(550, 750), "Selectable", "Black"); // Black Bishop right
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(650, 750), "Selectable", "Black"); // Black Knight right
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(750, 750), "Selectable", "Black"); // Black Rook right

    // Black pawns
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(50, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(150, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(250, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(350, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(450, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(550, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(650, 650), "Selectable", "Black");
    pieces.emplace_back(sf::Color::Red, sf::Vector2f(750, 650), "Selectable", "Black");

    if (!chessPieceTexture.loadFromFile("C:/Users/borde/Documents/C++/Warhammer 40k Chess game/40k Chess/Assets/ChessPieces.jpg")) {
        std::cerr << "Failed to load texture!\n";
    }
    else {
        std::cerr << "Texture loaded!\n";
    }

    pieces[0].setWRookTexture(chessPieceTexture);
    pieces[1].setWKnightTexture(chessPieceTexture);
    pieces[2].setWBishopTexture(chessPieceTexture);
    pieces[3].setWQueenTexture(chessPieceTexture);
    pieces[4].setWKingTexture(chessPieceTexture);
    pieces[5].setWBishopTexture(chessPieceTexture);
    pieces[6].setWKnightTexture(chessPieceTexture);
    pieces[7].setWRookTexture(chessPieceTexture);

    pieces[8].setWPawnTexture(chessPieceTexture);
    pieces[9].setWPawnTexture(chessPieceTexture);
    pieces[10].setWPawnTexture(chessPieceTexture);
    pieces[11].setWPawnTexture(chessPieceTexture);
    pieces[12].setWPawnTexture(chessPieceTexture);
    pieces[13].setWPawnTexture(chessPieceTexture);
    pieces[14].setWPawnTexture(chessPieceTexture);
    pieces[15].setWPawnTexture(chessPieceTexture);

    pieces[16].setBRookTexture(chessPieceTexture);
    pieces[17].setBKnightTexture(chessPieceTexture);
    pieces[18].setBBishopTexture(chessPieceTexture);
    pieces[19].setBQueenTexture(chessPieceTexture);
    pieces[20].setBKingTexture(chessPieceTexture);
    pieces[21].setBBishopTexture(chessPieceTexture);
    pieces[22].setBKnightTexture(chessPieceTexture);
    pieces[23].setBRookTexture(chessPieceTexture);

    pieces[24].setBPawnTexture(chessPieceTexture);
    pieces[25].setBPawnTexture(chessPieceTexture);
    pieces[26].setBPawnTexture(chessPieceTexture);
    pieces[27].setBPawnTexture(chessPieceTexture);
    pieces[28].setBPawnTexture(chessPieceTexture);
    pieces[29].setBPawnTexture(chessPieceTexture);
    pieces[30].setBPawnTexture(chessPieceTexture);
    pieces[31].setBPawnTexture(chessPieceTexture);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // When picking a piece up
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            for (auto& piece : pieces) {
                if (piece.getTag() == "Selectable" && piece.contains(mousePos)) {
                    selectedPiece = &piece;
                    isDragging = true;
                    break;
                }
            }
        }

        // When letting a piece go
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) { // Checks if we're clicking the left mouse button

            if (selectedPiece) { // Checks if we're holding a chess piece
                selectedPiece->setPosition(snapToGrid(selectedPiece->getPosition())); // When you're letting go of the piece, it will snap neatly back to position on the board
                 
                // Detect and remove captured (collided) piece of the opposite color
                auto it = std::remove_if(pieces.begin(), pieces.end(), // Goes through all pieces to check if something is hitting each other
                    [&](const Piece& other) {
                        return (&other != selectedPiece) && // Don't check the piece we dropped
                            selectedPiece->getShape().getGlobalBounds().intersects(other.getShape().getGlobalBounds()) && // Are we hitting a piece?
                            selectedPiece->getPieceColor() != other.getPieceColor(); // Only delete the piece if it's an other color
                    });

                if (it != pieces.end()) {
                    pieces.erase(it, pieces.end()); // Deletes the enemy that got hit
                }

                selectedPiece = nullptr; // Nothing is being dragged, so it's set to false
                isDragging = false;
            }
        }
    }

    if (isDragging && selectedPiece) { // When holding a piece and dragging across the game, it's position will be equal to the mouse position
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        selectedPiece->setPosition(mousePos);
    }
}

void Game::update() {
    // (empty for now)
}

void Game::render() {
    window.clear();
    createBoard();

    for (auto& piece : pieces)
        window.draw(piece.getShape());

    window.display();
}

void Game::createBoard() {
    sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
    bool white = true;

    for (int y = 0; y < boardSize; ++y) {
        for (int x = 0; x < boardSize; ++x) {
            square.setPosition(x * squareSize, y * squareSize);
            square.setFillColor(white ? sf::Color::White : sf::Color(100, 100, 100));
            window.draw(square);
            white = !white;
        }
        white = !white;
    }
}

sf::Vector2f Game::snapToGrid(const sf::Vector2f& position) {
    int x = static_cast<int>(position.x) / squareSize;
    int y = static_cast<int>(position.y) / squareSize;

    x = std::max(0, std::min(x, boardSize - 1));
    y = std::max(0, std::min(y, boardSize - 1));

    return sf::Vector2f(
        x * squareSize + squareSize / 2.f,
        y * squareSize + squareSize / 2.f
    );
}