#include <string>
#include <linked_list.hpp>

namespace boop {

class Pieces {
  virtual std::string get_type() const noexcept = 0;
};

class Cat : public Pieces {
  virtual std::string get_type() const noexcept override;
};

class Kitten : public Pieces {
  virtual std::string get_type() const noexcept override;
};

class Board {
private:
	Node<Pieces*>* head;
public:
	Board(size_t);
	~Board();
};

} // namespace boop
