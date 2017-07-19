#include <vector>

#include "dedge.h"

class dtriangle{

public:

	vector<dedge> edges;

private:

	void add_edge(dedge new_dedge){
		edges.push_back(new_dedge);
	}


	
};