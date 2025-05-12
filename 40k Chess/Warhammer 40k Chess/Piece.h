#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Piece {
public:
    Piece(const sf::Color& color, const sf::Vector2f& pos, const std::string& tag, const std::string& pieceColor);

    void setPosition(const sf::Vector2f& pos);
    sf::Vector2f getPosition() const;
    const sf::RectangleShape& getShape() const;
    bool contains(const sf::Vector2f& point) const;
    std::string getTag() const;
    std::string getPieceColor() const;

    void setWPawnTexture(const sf::Texture& texture);
    void setWKingTexture(const sf::Texture& texture);
    void setWQueenTexture(const sf::Texture& texture);
    void setWRookTexture(const sf::Texture& texture);
    void setWKnightTexture(const sf::Texture& texture);
    void setWBishopTexture(const sf::Texture& texture);

private:
    sf::RectangleShape shape;
    std::string tag;
    std::string pieceColor;
};