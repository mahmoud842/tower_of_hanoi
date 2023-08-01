//============================================================================
// Name        : tower_of_hanoi.cpp
// Author      : mahmoud hesham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "hanoiTower.h"

int main() {

	hanoiTower::Game g(5);
	g.printGame();
	g.solve();
	std::cout << "========after solve========" << std::endl;
	g.printGame();

	return 0;
}
