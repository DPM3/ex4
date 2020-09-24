#pragma once
#include<string>

enum class Direction {
	UP, DOWN, LEFT, RIGHT
};

std::string tostring(Direction);

Direction opposite(Direction);
