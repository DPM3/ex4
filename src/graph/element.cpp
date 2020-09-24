#include"element.hpp"


namespace server_side {

Element::Element(float cost) : m_cost{cost}, m_isBlock{false} { }

Element Element::block() {
	Element result;
	result.isBlock() = true;
	return result;
}

float& Element::cost() {
	return m_cost;
}
bool& Element::isBlock() {
	return m_isBlock;
}
float Element::cost() const {
	return m_cost;
}
bool Element::isBlock() const {
	return m_isBlock;
}

}
