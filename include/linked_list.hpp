#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstddef>

namespace boop {

template <typename T> struct Node {
  T data;
  Node *up, *down, *right, *left;
  Node(const T &);
  Node();
  ~Node();
  void connect_nodes_down(std::size_t size);
  void clear();

private:
  void clear(Node<T> *node);
};

template <typename T>
Node<T> *connect_nodes_horizontally(Node<T> *node1, Node<T> *node2);

template <typename T> Node<T> *find_up_node(const Node<T> *);

template <typename T> Node<T> *find_left_node(const Node<T> *);

template <typename T> Node<T> *find_right_node(const Node<T> *);

template <typename T> Node<T> *find_down_node(const Node<T> *);

template <typename T> Node<T> *find_up_node(const Node<T> *node) {
  auto actual = node;
  while (actual->up != nullptr)
    actual = actual->up;
  return actual;
}

template <typename T> Node<T> *find_down_node(const Node<T> *node) {
  auto actual = node;
  while (actual->down != nullptr)
    actual = actual->down;
  return actual;
}

template <typename T> Node<T> *find_left_node(const Node<T> *node) {
  auto actual = node;
  while (actual->left != nullptr)
    actual = actual->left;
  return actual;
}

template <typename T> Node<T> *find_right_node(const Node<T> *node) {
  auto actual = node;
  while (actual->right != nullptr)
    actual = actual->right;
  return actual;
}
} // namespace boop

template <typename T>
boop::Node<T>::Node(const T &data)
    : data(data), up(nullptr), down(nullptr), right(nullptr), left(nullptr) {}

template <typename T>
boop::Node<T>::Node()
    : data(T()), up(nullptr), down(nullptr), right(nullptr), left(nullptr) {}

template <typename T> boop::Node<T>::~Node() {
  delete up;
  delete down;
  delete right;
  delete left;
}

template <typename T> void boop::Node<T>::connect_nodes_down(std::size_t size) {
  if (size == 0)
    return;
  auto actual = this;
  for (std::size_t i = 0; i < size; i++) {
    actual->down = new Node<T>();
    actual->down->up = actual;
    actual = actual->down;
  }
}

template <typename T> void boop::Node<T>::clear() {
  if (up) {
    up->clear();
    up = nullptr;
  }
  if (down) {
    down->clear();
    down = nullptr;
  }
  if (left) {
    left->clear();
    left = nullptr;
  }
  if (right) {
    right->clear();
    right = nullptr;
  }

  delete this;
}

template <typename T>
boop::Node<T> *boop::connect_nodes_horizontally(Node<T> *node1,
                                                Node<T> *node2) {
  /*
   For this function, two nodes must be passed, each belonging to an array of
   nodes of different sizes: a x b and c x d respectively.
   */

  // find the node of the first matrix that is at the top right.
  Node<T> *actual1 = find_up_node(find_left_node(node1));
  Node<T> *actual2 = find_up_node(find_right_node(node2));
	while (actual1 != nullptr && actual2 != nullptr) {
		actual1->right = actual2;
		actual2->left = actual1;
		actual1 = actual1->down;
		actual2 = actual2->down;	
	}
	return find_up_node(find_right_node(node1)); 
}

#endif
