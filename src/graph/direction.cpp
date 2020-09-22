#include"direction.hpp"

std::string tostring(Direction dir) {
	switch(dir) {
		case Direction::UP:
			return "Up";
		case Direction::DOWN:
			return "Down";
		case Direction::LEFT:
			return "Left";
		case Direction::RIGHT:
			return "Right";
	}
}
