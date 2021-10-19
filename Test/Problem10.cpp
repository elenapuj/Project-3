
#include "PenningTrap.hpp"


int main() {

	//The PenningTrap holds a collection of particles
	vector<Particle> my_particle_collection;

	//We create an specific trap by calling the PenningTrap constructor
	PenningTrap my_trap(96.5, 9.65 * pow(10, 8), 10000, my_particle_collection);

	vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial position
	vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial velocity

//We create a particle by calling the Particle constructor
	Particle my_particle(1, 40.078, r0, v0);

	//Here we add the particle mentioned before in the specific Penning trap
	my_trap.add_n_particles(100 , my_particle);

	std::cout << my_trap.number_particles_inside();

	return 0;


}
