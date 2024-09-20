#include <SFML/Graphics/RectangleShape.hpp>
#include <graphics.hpp>

boop::GraphicBoard::GraphicBoard(const unsigned int &n) : _size(n), _cell_size(50){}

void boop::GraphicBoard::draw(sf::RenderWindow& window) const {
	for (unsigned int row = 0; row < _size; ++row) {
		for (unsigned int col = 0; col < _size; ++col) {
			sf::RectangleShape square(sf::Vector2f(_cell_size, _cell_size));
			square.setPosition(col * _cell_size, row * _cell_size);
			square.setOutlineThickness(1);
			square.setOutlineColor(sf::Color::Black);
			square.setFillColor(sf::Color::White);

			window.draw(square);
		}
	}
}
