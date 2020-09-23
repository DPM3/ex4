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
	return "this will never happen!";
}

Direction opposite(Direction dir) {
	switch (dir) {
		case Direction::UP:
			return Direction::DOWN;
		case Direction::DOWN:
			return Direction::UP;
		case Direction::RIGHT:
			return Direction::LEFT;
		case Direction::LEFT:
			return Direction::RIGHT;
	}
	return Direction::DOWN; //will never happen!
}
