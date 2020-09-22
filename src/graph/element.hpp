#pragma once

namespace server_side {

class Element {
	float m_cost;
	bool m_isBlock;
public:
	Element(int cost = 0);

	static Element block(); //to create a block

	float& cost();
	bool& isBlock();
	float cost() const;
	bool isBlock() const;
};

}
