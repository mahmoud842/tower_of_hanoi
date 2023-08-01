/*
 * hanoiTower.cpp
 *
 *  Created on: Aug 1, 2023
 *      Author: LEGION
 */

#include "hanoiTower.h"
#include <iostream>

namespace hanoiTower {

	// Cube class
	Cube::Cube(unsigned long long length){
		length_ = length;
	}

	void Cube::setLength(unsigned long long length){
		length_ = length;
	}

	unsigned long long Cube::getArea(){
		return length_ * length_ * 6;
	}

	unsigned long long Cube::getLength(){
		return length_;
	}

	// ========================================
	// Stack class
	void StackOfCubes::print(){
		std::cout << "[";
		for (unsigned int i = 0; i < s.size(); i++){
			std::cout << s[i].getLength();
			if (i != s.size() - 1)
				std::cout << ",";
		}
		std::cout << ']' << std::endl;
	}

	void StackOfCubes::push(Cube c){
		s.push_back(c);
	}

	Cube StackOfCubes::pop(){
		unsigned int lastIndex = s.size() - 1;
		Cube lastItem = s[lastIndex];
		s.pop_back();
		return lastItem;
	}

	Cube & StackOfCubes::peekTop(){
		unsigned int lastIndex = s.size() - 1;
		return s[lastIndex];
	}

	// ========================================
	// Game class
	Game::Game(int numberOfStartingCubes){
		numberOfDiscs = numberOfStartingCubes;

		for (int i = 0; i < 3; i++) {
			StackOfCubes sof;
			platform.push_back(sof);
		}

		for (int i = numberOfStartingCubes; i > 0; i--){
			Cube c(i);
			platform[0].push(c);
		}
	}

	void Game::printGame(){
		for (int i = 0; i < 3; i++){
			std::cout << "Stack " << i + 1 << ' ';
			platform[i].print();

		}
	}

	void Game::solve(){
		realSolver(numberOfDiscs, 0, 2, 1);
	}

	void Game::realSolver(int N, int src, int dest, int aux){
		if (N != 0) {
			realSolver(N - 1, src, aux, dest);
			Cube tmp = platform[src].pop();
			platform[dest].push(tmp);
			std::cout << "===== step =====" << std::endl;
			printGame();
			realSolver(N - 1, aux, dest, src);
		}
	}

}
