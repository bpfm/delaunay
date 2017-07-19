#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "dvertex.h"
#include "dedge.h"
#include "dtriangle.h"

int main(){

	int i,j,n_vert=10;
	double rand1,rand2,rand3,x1,x2,x3,y1,y2,y3,x_new,y_new;
	double ma,mb,x_centre,y_centre,rad,rad_new;
	dvertex new_vertex;
	dtriangle new_triangle;
	vector<dvertex> all_points;
	vector<dtriangle> dtriangulation;
	vector<dtriangle>::iterator it_tri;
	
	ofstream vertices;

	vertices.open("points.txt");

	for(i=0;i<n_vert;i++){
		rand1 = (double)rand()/RAND_MAX;
		rand2 = (double)rand()/RAND_MAX;

		new_vertex.set_x(rand1);
		new_vertex.set_y(rand2);

		all_points.push_back(new_vertex);
		vertices << rand1 << "\t" << rand2 << endl;
	}

	vertices.close();

	// create random triangle (use first three vertices)

	cout << "Creating starting triangle" << endl;

	new_triangle.set_id(0);
	new_triangle.add_dvertex(all_points[0]);
	new_triangle.add_dvertex(all_points[1]);
	new_triangle.add_dvertex(all_points[2]);

	dtriangulation.push_back(new_triangle);

	// insert new point and adjust triangulation

	cout << "Inserting new points into triangulation" << endl;

	for(i=3;i<n_vert;i++){
		new_vertex = all_points[i];
		for(it_tri = dtriangulation.begin(),j=0;it_tri < dtriangulation.end();it_tri++,j++){
			x1 = dtriangulation[j].get_dvertex(0).get_x();
			x2 = dtriangulation[j].get_dvertex(1).get_x();
			x3 = dtriangulation[j].get_dvertex(2).get_x();
			y1 = dtriangulation[j].get_dvertex(0).get_y();
			y2 = dtriangulation[j].get_dvertex(1).get_y();
			y3 = dtriangulation[j].get_dvertex(2).get_y();
			x_new = new_vertex.get_x();
			y_new = new_vertex.get_y();

			// calculate cicrumdisk

			ma = (y2-y1)/(x2-x1);
			mb = (y3-y2)/(x3-x2);

			x_centre = (ma*mb*(y1-y3)+mb*(x1+x2)-ma*(x2+x3))/(2.0*(mb-ma));
			y_centre = -1.0*(1.0/ma)*(x_centre-(x1+x2)/2.0)+(y1+y2)/2.0;

			rad = sqrt((x1-x_centre)*(x1-x_centre)+((y1-y_centre)*(y1-y_centre)));
			rad_new = sqrt((x_new-x_centre)*(x_new-x_centre)+((y_new-y_centre)*(y_new-y_centre)));

			if(rad_new > rad){
				// new vertex lies within circumdisk of jth triangle
			}			

		}
	}

	return 0;
}