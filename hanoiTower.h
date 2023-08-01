/*
 * hanoiTower.h
 *
 *  Created on: Aug 1, 2023
 *      Author: LEGION
 */

#ifndef HANOITOWER_H_
#define HANOITOWER_H_
#include <vector>

namespace hanoiTower {


	class Cube {
	private:
		unsigned long long length_;
	public:
		Cube(unsigned long long length);
		void setLength(unsigned long long length);
		unsigned long long getLength();
		unsigned long long getArea();
	};

	class StackOfCubes {
	private:
		std::vector<Cube> s;

	public:
		void push(Cube c);
		Cube pop();
		Cube & peekTop();
		void print();
	};

	class Game {
	private:
		std::vector<StackOfCubes> platform;
		int numberOfDiscs;
		bool solved = false;
		void realSolver(int N, int src, int dest, int aux);

	public:
		Game(int numberOfStartingCubes);
		void solve();
		void printGame();
	};

}


#endif /* HANOITOWER_H_ */
