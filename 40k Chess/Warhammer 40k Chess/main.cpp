#include "Game.h"

int main() {
	Game game;
	game.run();
	return 0;
}

/*
#include <iostream>

#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Warhammer 40K Chess");

	sf::CircleShape player(50.f);
	sf::CircleShape whiteHorse(50.f);

	sf::CircleShape enemyAI(50.f);
	
	float RectangleSize = 100;

	sf::RectangleShape chessBoard(sf::Vector2f(RectangleSize, RectangleSize));

	float snapPositionSquareSize = 15.f;

	sf::CircleShape snapPositionSquare(snapPositionSquareSize);

	player.setFillColor(sf::Color::Blue);

	whiteHorse.setFillColor(sf::Color::Magenta);

	enemyAI.setFillColor(sf::Color::Red);
	snapPositionSquare.setFillColor(sf::Color::Magenta);

	player.setPosition(150, 150);

	whiteHorse.setPosition(200, 150);

	enemyAI.setPosition(600, 600);

	player.setOrigin(50.f, 50.f);
	whiteHorse.setOrigin(50.f, 50.f);

	bool white = false;
	bool isDragging{};

	int offset = 100;

	int rangeSquare = 50;

	int chessBoardX = 8;
	int chessBoardY = 8;

	sf::Vector2f targetPosition = player.getPosition(); // Default target position
	float speed = 5.0f;

	sf::Texture chessPieces;
	if (!chessPieces.loadFromFile("C:/Users/borde/Documents/C++/Warhammer 40k Chess game/40k Chess/Assets/ChessPieces.jpg"))
	{
		cerr << "Failed to load chess pieces texture!" << endl;
		return -1;
	}

	while (window.isOpen())
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			// Initiate check for left mouse button = pressed
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{

				// Initiate check if mouse is inside chess piece
				if (sf::Mouse::getPosition(window).x <= (player.getPosition().x + rangeSquare) && sf::Mouse::getPosition(window).y <= (player.getPosition().y + rangeSquare)
					&& sf::Mouse::getPosition(window).x >= (player.getPosition().x - rangeSquare) && sf::Mouse::getPosition(window).y >= (player.getPosition().y - rangeSquare))
				{
					player.setFillColor(sf::Color::Yellow);
					player.setScale(1.25f, 1.25f);

					isDragging = true;
				}
			}

			// Initiate check if left mouse button = released
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				player.setFillColor(sf::Color::Blue);
				player.setScale(1.0f, 1.0f);
				isDragging = false;

				// Snap pawn to nearest circle
				sf::Vector2i mousePos = sf::Mouse::getPosition(window); //Gets mouse position of window

				int gridX = (mousePos.x - offset) / RectangleSize; //Figures out which square mouse is on
				int gridY = (mousePos.y - offset) / RectangleSize;

				gridX = std::max(0, std::min(gridX, chessBoardX - 1)); //Makes sure that when mouse is let go outside of board, that it snaps towards nearest point
				gridY = std::max(0, std::min(gridY, chessBoardY - 1));

				sf::Vector2f squareCenter = sf::Vector2f(gridX * RectangleSize + offset + RectangleSize / 2,
					gridY * RectangleSize + offset + RectangleSize / 2); // Converts gird coordinates back into pixel coordinates for placing the player

				player.setPosition(squareCenter);
			}

			// Initiate check if bool = true
			if (isDragging)
			{
				player.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			}

			// Initiate check if chess piece hit other chess piece
			if (!isDragging && player.getPosition().x <= (enemyAI.getPosition().x + rangeSquare) && player.getPosition().y <= (enemyAI.getPosition().y + rangeSquare) &&
				player.getPosition().x >= (enemyAI.getPosition().x - rangeSquare) && player.getPosition().y >= (enemyAI.getPosition().y - rangeSquare))
			{
				enemyAI.setPosition(0, 0);
			}
		}

		// Create chess board
		window.clear();

		white = true;
		for (int y = 0; y < chessBoardY; y++)
		{
			white = !white;
			for (int x = 0; x < chessBoardX; x++)
			{
				white = !white;
				if (white) 
				{
					chessBoard.setFillColor(sf::Color::White);

				}
				else
				{
					chessBoard.setFillColor(sf::Color::Black);
				}
				chessBoard.setPosition((RectangleSize * x) + offset, (RectangleSize * y) + offset);
				window.draw(chessBoard);

				sf::Vector2f squareCenter = chessBoard.getPosition() + sf::Vector2f(RectangleSize / 2, RectangleSize / 2); // Gives the center point of the square
				snapPositionSquare.setPosition(squareCenter - sf::Vector2f(snapPositionSquareSize, snapPositionSquareSize)); // Places the circle in the center of the square 
				window.draw(snapPositionSquare);
			}
		}

		window.draw(whiteHorse);
		window.draw(player);
		window.draw(enemyAI);

		window.display();
	}

	return 0;
}
*/