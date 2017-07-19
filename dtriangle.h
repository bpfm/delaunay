#include <vector>

using namespace std;

class dtriangle{

private:

	int id;
	vector<dvertex> dvertices;

public:

	void set_id(int new_id){
		id = new_id;
	}

	void add_dvertex(dvertex new_dvertex){
		dvertices.push_back(new_dvertex);
	}
	
	int get_id(){
		return id;
	}

	dvertex get_dvertex(int dvertex_id){
		return dvertices[dvertex_id];
	}

};