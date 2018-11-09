#include <list>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

//bool intersect(list <vector <int>> point_list, vector <int> new_point);

bool new_intersect(list<vector <int> > point_list, vector <int> p3, vector <int> p4){
	//return true if new line intersects, false if not
	bool cross = 0;
	list <vector <int> >:: iterator it, back;
	vector <int> p1, p2;
	int counter = 0;

	//initalize p1 and p2
	it = point_list.begin();
	back = point_list.begin();
	advance(back, point_list.size()-1);
	p1 = *it;
	advance(it, 1);
	p2 = *it;

//	point_list.push_back(p4)

	bool stop = 0;

	while(it != back){

		//cout << "checking p1 " << p1[0] << " " << p1[1] << " to p2 " << p2[0] << " " << p2[1] << endl;
		//cout << "against p3 " << p3[0] << " " << p3[1] << " and p4 " << p4[0] << " " << p4[1] << endl;

		double bottom = (double) ((p2[0]-p1[0])*-(p4[1]-p3[1])) - (-(p4[0]-p3[0])*(p2[1]-p1[1]));
		double UaTop = (double)  ((p3[0]-p1[0])*-(p4[1]-p3[1])) - (-(p4[0]-p3[0]) * (p3[1]-p1[1]));
		double UbTop = (double)  ((p2[0]-p1[0])*(p3[1]-p1[1])) - ((p3[0] - p1[0]) * (p2[1]-p1[1]));

		double Ua = UaTop/bottom;
		double Ub = UbTop/bottom;

        if( (Ua > 0.0 && Ua < 1.0) && (Ub > 0.0 && Ub < 1.0)){
			//cout << "ua: " << Ua << " ub :" << Ub << endl;
            cross = 1; 
        }       
        
		p1 = p2;

		advance(it, 1);
		p2 = *it;
		counter = counter + 1;
	}

	//runs when it = back
	double bottom = (double) ((p2[0]-p1[0])*-(p4[1]-p3[1])) - (-(p4[0]-p3[0])*(p2[1]-p1[1]));
	double UaTop = (double)  ((p3[0]-p1[0])*-(p4[1]-p3[1])) - (-(p4[0]-p3[0]) * (p3[1]-p1[1]));
	double UbTop = (double)  ((p2[0]-p1[0])*(p3[1]-p1[1])) - ((p3[0] - p1[0]) * (p2[1]-p1[1]));

	double Ua = UaTop/bottom;
	double Ub = UbTop/bottom;


    if( (Ua > 0.0 && Ua < 1.0) && (Ub > 0.0 && Ub < 1.0)){
		//cout << "ua: " << Ua << " ub :" << Ub << endl;
        cross = 1; 
    }       
 
	counter = counter + 1;
//	cout << "checked for cross" << endl;
	return cross;

}

bool intersect(list<vector <int> > point_list,vector <int> prev_point, vector <int> new_point){
	// return true if new line intersects, false if not
	bool cross = 0;	
    list <vector<int> >::iterator it;

	double x1 = prev_point[0];
	double y1 = prev_point[1];
	double x2 = new_point[0];
	double y2 = new_point[1];

	vector <int> p1;
	vector <int> p2;
    vector <int> store;
    vector <int> back, bc;
    
	//back = point_list.back();
	//point_list.pop_back();

	store = point_list.front();
    p1 = store;

    //remove first element from list so loop starts at correct point
    point_list.pop_front();

	//starts at second entry in point_list
	//probably could make this more efficent
	for( it=point_list.begin(); it != point_list.end(); ++it){

		p2 = *it;

        double x3 = p1[0];
        double y3 = p1[1];
        double x4 = p2[0];
        double y4 = p2[1];

        double bottom = ((x2-x1) * -(y4-y3)) - (-(x4-x3)*(y2-y1));
        double UaTop = ((x3-x1)*-(y4-y3)) - (-(x4-x3)*(y3-y1));
        double UbTop = ((x2-x1)*(y3-y1)) - ((x3-x1)*(y2-y1));

        double Ua = UaTop/bottom;
        double Ub = UbTop/bottom; 
		


        if( (Ua > 0.0 && Ua < 1.0) && (Ub > 0.0 && Ub < 1.0)){
            cross = 1; 
			cout << "ua: " << Ua << " ub :" << Ub << endl;
        }       
        
		p1 = p2;
	} 

    //puts first element back in list
    point_list.push_front(store); 
	//point_list.push_back(back);
    return cross; 
}


