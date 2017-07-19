class dedge{

private:

	int dedge_id;
	dvertex dvertex_0,dvertex_1;

public:

	void set_dedge_id(int new_dedge_id){
		dedge_id = new_dedge_id;
	}

	void set_dvertex(int index, dvertex new_dvertex){
		if(index==0){
			dvertex_0 = new_dvertex;
		}else{
			dvertex_1 = new_dvertex;
		}
	}
	
	int get_dedge_id(){
		return dedge_id;
	}

	dvertex get_dvertex(int index){
		if(index==0){
			return dvertex_0;
		}else{
			return dvertex_1;
		}
	}

};