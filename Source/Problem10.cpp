#include "PenningTrap.hpp"

int main() {

	//The PenningTrap holds a collection of particles

	vector<Particle> my_particle_collection;


	//We create an specific trap by calling the PenningTrap constructor

	PenningTrap my_trap(96.5, 0.0025 * 9.64852558 * pow(10, 7), 500, my_particle_collection);

	//We create a particle Ca+ by calling the Particle constructor

	//Number of particles

	double N = 100;

	//We add N particles with random initial conditions

	my_trap.add_n_particles(N, 1 , 40.078, 500);

	//cout << my_particle_collection.size() << endl;

	vec fraction = zeros(116);

	vec f;

	f << 0.1 << 0.4 << 0.7 << endr;

	vec w = linspace(0.2, 2.5, 116);

	mat particles_inside;

	ofstream ofile1;
	ofile1.open("Problem10a.txt");
	ofile1 << scientific;

	for (int c = 0; c < 3; c++) {

		double h = 1;  //Stepsize

		double tf = 500;  //Final time

		for (int g = 0; g < 116; g++) {			
			
			double t = 0;  //Initial time

			while (t <= tf) {

				for (int l = 0; l < N; l++) {

					my_trap.evolve_RK4(h, l, t, f[c], w[g], true, true, false);
										
				}
								
				t = t + h;

			}

			//cout << w[g] << endl;
			//cout << my_trap.number_particles_inside() << my_trap.number_particles_inside() / N  << endl;


			fraction[g] = my_trap.number_particles_inside() / N;

			my_trap.randomize_r_and_v(N ,500);
			


			//my_trap.add_n_particles(N, 1, 40.078, 500);
						
		}

		//fraction.print();

		particles_inside.insert_cols(c, fraction);


	}
	
	ofile1 << particles_inside << endl;
	ofile1.close();

	return 0;

}