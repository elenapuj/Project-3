#include "PenningTrap.hpp"

int main(){

	vector<Particle> my_particle_collection;

	PenningTrap my_trap( 96.5, 9.65 * pow(10 , 8), 10000 , my_particle_collection);

	vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial position
 	vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial velocity

	Particle my_particle( 1 , 40.078 , r0 , v0);

	my_trap.add_particle(my_particle);

	double h = 0.1; //stepsize

	double t = 0.; //initial time

	double tf = 100.; //final time

	int n = 0;

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

		R.insert_cols(n, my_trap.particle_collection[0].r_);
		V.insert_cols(n, my_trap.particle_collection[0].v_);

	}

	ofstream ofile1;
        ofile1.open("Problem9a_R.txt");
	ofile1 << scientific;
        ofile1 << R << endl;
	ofile1.close();

	ofstream ofile2;
	ofile2.open("Problem9a_V.txt");
        ofile2 << scientific;
        ofile2 << V << endl;
        ofile2.close();

	return 0;

}
