#include "dvertex.h"

class dedge{

private:

	vertex *vertex_0,*vertex_1;

public:

	set_vertex(int index, vertex* new_vertex){
		if(index==0){
			vertex_0 = new_vertex;
		}else{
			vertex_1 = new_vertex;
		}
	}
	
};