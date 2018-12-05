#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>

#define OBSTACLE_TEST_SAMPLING 20 // nmber of test to perform on every graph edge to determine if there is a collision

#define INF std::numeric_limits<int>::max()

struct Pos{
	int i;
	int j;
	
	Pos(): i(-1), j(-1)
	{}
	
	Pos(int I, int J): i(I), j(J)
	{}
	
	void disp(){
		std::cout << "*** Pos : (" << i << "," << j << ")" << std::endl;
	}
	
};


#endif
