#include <vector>

#include "dtriangle.h"

using namespace std;

class dtriangulation{
	
private:

	vector<dtriangle> triangulation;

public:

	add_triangle(dtriangle new_dtriangle){
		triangulation.push_back(new_dtriangle);
	}

};