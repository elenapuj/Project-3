#include "PenningTrap.hpp"

int main(){
	
	vector<Particle> my_particle_collection;
	
	PenningTrap my_trap( 96.5, 9.65 * pow(10 , 8), 10000 , my_particle_collection);
		
	vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial position
 	vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial velocity
	
	Particle my_particle( 1 , 40.078 , r0 , v0);
	
	int h = 0.1; //stepsize
	
	int t = 0; //initial time
	
	int tf = 100; //final time
	
	int n = 1;
		
	mat R, V;
	
	R << r0[0] << endr
	  << r0[1] << endr
	  << r0[2];
	V << v0[0] << endr
	  << v0[1] << endr
	  << v0[2];
			
	while (t <= tf) {
		
		n++;
		
		t = t + h;
		
		my_trap.evolve_forward_Euler(h,0);
		
		R.insert_cols(n, particle_collection[0].r_);
		V.insert_cols(n, particle_collection[0].v_);

	}
	
	ofstream ofile;
        ofile.open("Problem9a_R.txt");
	ofile << scientific;
        ofile << R << endl;
	ofile.close();
	
	ofstream ofile;
	ofile.open("Problem9a_V.txt");
        ofile << scientific;
        ofile << V << endl;
        ofile.close();

	return 0;
		
}
