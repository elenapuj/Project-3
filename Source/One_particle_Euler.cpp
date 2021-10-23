#include "PenningTrap.hpp"


//Here we will generate data for the position and velocity of a single particle in the Penning Trap using the Forward Euler method

int main(){
	
	//The PenningTrap holds a collection of particles
	
	vector<Particle> my_particle_collection;

	
	//We create an specific trap by calling the PenningTrap constructor
	
	PenningTrap my_trap( 96.5, 9.65 * pow(10 , 8), 10000 , my_particle_collection);
	
	
	//Here we introduce some other conditions
	
	double f = 0;  //As this is only necessary when the electric field is time dependent, we define it as zero  

	double w = 0;  //Same as the one before

	double h = 0.01; //Stepsize

	double t = 0; //Initial time

	double tf = 100; //Final time
	
	
	//We create a particle by calling the Particle constructor

	vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  //Random initial position
 	vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  //Random initial velocity
	
	Particle my_particle( 1 , 40.078 , r0 , v0);

	
	//Here we add the particle mentioned before in the specific Penning trap
	
	my_trap.add_particle(my_particle);


	
	
	//We define two matrices that will contain the three components of the velocity and position of the particle
	
	mat Re, Ve;

	
	//Now we fill this matrices with the initial values of the position and the velocity
	
	Re << r0[0] << endr
	   << r0[1] << endr
	   << r0[2];

	Ve << v0[0] << endr
	   << v0[1] << endr
	   << v0[2];

	
	
	
	//We now define a counter for the step
	
	int n = 1;
	
	
	//With this loop, while the time is below the final time defined, the Forward Euler algorithm will evolve the Penning Trap system in time
	
	while (t <= tf) {

		my_trap.evolve_forward_Euler(h, 0, t, f, w, true, false, true);
		
		//We insert in the matrices previously defined the different values of the position and velocity, values calculated thanks to the Forward Euler method
		
		Re.insert_cols(n, my_trap.particle_collection[0].r_);
		Ve.insert_cols(n, my_trap.particle_collection[0].v_);

		t = t + h;

		n++;

	}

	
	//We create two .txt files that stores respectively the matrices that contains the values of the position and velocity of the particle
	
	ofstream ofile1;
        ofile1.open("Problem9a_Rfe.txt");
	ofile1 << scientific;
        ofile1 << Re.t() << endl;
	ofile1.close();

	ofstream ofile2;
	ofile2.open("Problem9a_Vfe.txt");
        ofile2 << scientific;
        ofile2 << Ve.t() << endl;
        ofile2.close();


	return 0;

}
