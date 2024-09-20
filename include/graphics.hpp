#include <SFML/Graphics.hpp>
#include <linked_list.hpp>
#include <game_elements.hpp>
namespace boop {
class GraphicBoard {
private:
	unsigned int _size;
	unsigned int _cell_size;
public:
	GraphicBoard(const unsigned int& n);
	void draw(sf::RenderWindow&) const;
};
}

