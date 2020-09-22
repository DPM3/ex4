#pragma once

namespace server_side {

class Element {
	int m_cost;
	bool m_isBlock;
public:
	Element(int m_cost = 0);

	static Element block(); //to create a block

	int& cost();
	bool& isBlock();
	int cost() const;
	bool isBlock() const;
};

}
