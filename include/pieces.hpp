#include <string>
namespace boop {
class Piece {
protected:
	std::string _type;
public:
	inline std::string get_type() const { return _type; }
};
class Cat : public Piece {
public:
	Cat();
};

class Kitten : public Piece {
public:
	Kitten();
};
} // namespace boop
