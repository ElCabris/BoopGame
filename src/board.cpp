#include <game_elements.hpp>

boop::Board::Board(size_t size) {
	head = new Node<Pieces*>();
	head->connect_nodes_down(size);
	for (std::size_t i = 0; i < size; i++) {
		auto aux = new Node<Pieces*>();
		aux->connect_nodes_down(size);
		head = connect_nodes_horizontally(head, aux); 
	}
}

boop::Board::~Board() {
	head->clear();
}
