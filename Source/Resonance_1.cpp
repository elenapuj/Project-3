#include "PenningTrap.hpp"

int main() {
	
	//We create a vector to store particles

	vector<Particle> my_particle_collection;
	
	
	//Then, we create a trap with the desired conditions 
	
	PenningTrap my_trap(96.5, 0.0025 * 9.64852558 * pow(10, 7), 500, my_particle_collection);


	//We add N particles to the trap
	
	double N = 100;

	my_trap.add_n_particles(N, 1 , 40.078, 500);


	//Now, we introduce some other data we will need

	vec f;

	f << 0.1 << 0.4 << 0.7 << endr;

	vec w = linspace(0.2, 2.5, 116);
	
	
	//And now, we create some elements to store data later
	
	vec fraction = zeros(116);

	mat particles_inside;
	
	
	//After that, we open a file for storing how many particles are there in the trap after sometime for each omega

	ofstream ofile1;
	ofile1.open("Resonance_1.txt");
	ofile1 << scientific;
	
	
	//Then, for each f and each omega, we evoulte the system during 500 microsecs without taking the Coulomb force into account

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
			
			
			//After evolving the system, we get the number of particles that are still inside the trap

			fraction[g] = my_trap.number_particles_inside() / N;
			
			
			//And before starting with a new omega, we set the initial conditions again

			my_trap.randomize_r_and_v(N ,500);
			
						
		}


		particles_inside.insert_cols(c, fraction);


	}
	
	//Finally, we write the data we obtained in the file that we opened before
	
	ofile1 << particles_inside << endl;
	ofile1.close();

	return 0;

}
