#include "Piece.h"

Piece::Piece(const sf::Color& color, const sf::Vector2f& pos, const std::string& tag, const std::string& pieceColor)
    : tag(tag), pieceColor(pieceColor) {
    shape.setSize(sf::Vector2f(60.f, 60.f));
    shape.setFillColor(color);
    shape.setOrigin(30.f, 30.f);
    shape.setPosition(pos);
}

void Piece::setPosition(const sf::Vector2f& pos) {
    shape.setPosition(pos);
}

sf::Vector2f Piece::getPosition() const {
    return shape.getPosition();
}

const sf::RectangleShape& Piece::getShape() const {
    return shape;
}

bool Piece::contains(const sf::Vector2f& point) const {
    return shape.getGlobalBounds().contains(point);
}

std::string Piece::getTag() const {
    return tag;
}

std::string Piece::getPieceColor() const {
    return pieceColor;
}

void Piece::setWPawnTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(606, 15, 125, 125));
}

void Piece::setWKingTexture(const sf::Texture& texture)
{
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(15, 10, 125, 125));
}

void Piece::setWQueenTexture(const sf::Texture& texture)
{
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(135, 10, 125, 125));
}

void Piece::setWRookTexture(const sf::Texture& texture)
{
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(490, 10, 125, 125));
}

void Piece::setWKnightTexture(const sf::Texture& texture)
{
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(375, 10, 125, 125));
}

void Piece::setWBishopTexture(const sf::Texture& texture)
{
    shape.setTexture(&texture);
    shape.setTextureRect(sf::IntRect(253, 10, 125, 125));
}