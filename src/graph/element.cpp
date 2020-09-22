#include"element.hpp"


namespace server_side {

Element::Element(int cost = 0) : m_cost{cost}, m_isBlock{false} { }

Element Element::block() {
	Element result;
	result.isBlock() = true;
	return result;
}

int& Element::cost() {
	return m_cost;
}
bool& Element::isBlock() {
	return m_isBlock
}
int Element::cost() const {
	return m_cost;
}
bool Element::isBlock() const {
	return m_isBlock
}

}
