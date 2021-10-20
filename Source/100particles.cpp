#include "PenningTrap.hpp"

int main() {

	//The PenningTrap holds a collection of particles
	vector<Particle> my_particle_collection;

	//We create an specific trap by calling the PenningTrap constructor
	PenningTrap my_trap(96.5, 0.0025 * 9.64852558 * pow(10, 7), 500, my_particle_collection);

	vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial position
	vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial velocity

//We create a particle Ca+ by calling the Particle constructor
	
	Particle my_particle(1, 40.078, r0, v0);

	//Number of particles

	int N = 100;

//We add 100 particles 

	my_trap.add_n_particles(N, my_particle);

	vector <double> fraction;

	vec f;

	f << 0.1 << 0.4 << 0.7 << endr;

	vec w = linspace( 0.2 , 2.5 , 115);


	//We now define a counter for the step

	int n = 1;

	ofstream ofile1;
	ofile1.open("Problem10a.txt");
	ofile1 << scientific;

	for (int c = 0; c < 3; c++) {

		double h = 0.1; //stepsize

		double t = 0; //initial time

		double tf = 500; //final time

		while (t <= tf) {

			for (int g = 0; g < 115; g++) {

				my_trap.evolve_RK4(h, g, t, f[c], w[g], true, true, false);

				t = t + h;

				n++;

			}

		}

		int fraction_i = my_trap.number_particles_inside() / N;

		ofile1 << fraction_i << endl;

		fraction.push_back(fraction_i);

	}

	ofile1.close();

	return 0;

}
