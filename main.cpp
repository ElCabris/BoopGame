#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <graphics.hpp>
#include <iostream>

int main() {
  int n = 5;
	boop::GraphicBoard board(n);
  sf::RenderWindow window(sf::VideoMode(n * 50, n * 50), "board");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          std::cout << "click" << std::endl;
        }
      }
    }

    window.clear(sf::Color::White);
    board.draw(window);
    window.display();
  }
  return 0;
}
