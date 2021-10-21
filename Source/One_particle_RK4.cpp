#include "PenningTrap.hpp"

//Here we will generate data for the position and velocity of a single particle in the Penning Trap using the Runge-Kutta 4 method

int main(){
	
	//The PenningTrap holds a collection of particles
	
        vector<Particle> my_particle_collection;
	
	
	//We create an specific trap by calling the PenningTrap constructor
        
	PenningTrap my_trap( 96.5, 9.65 * pow(10 , 8), 10000 , my_particle_collection);
	
	//We define some other data for the penning trap
	
	double f = 0;  //As this is only necessary when the electric field is time dependent, we define it as zero

	double w = 0;  //Same as the one before

        double h = 0.1; //Stepsize

        double t = 0; //Initial time

        double tf = 100; //Final time
	
	
	//We create a particle by calling the Particle constructor
	
        vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  //Random initial position
        vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  //Random initial velocity
        
	Particle my_particle( 1 , 40.078 , r0 , v0);
	
	
	//Here we add the particle mentioned before in the specific Penning trap
        
	my_trap.add_particle(my_particle);

	
	

	//We define two matrices that will contain the three components of the velocity and position of the particle
        
	mat Rrk, Vrk;

	
	//Now we fill this matrices with the initial values of the position and the velocity
        
	Rrk << r0[0] << endr
            << r0[1] << endr
            << r0[2];

        Vrk << v0[0] << endr
            << v0[1] << endr
            << v0[2];

	
	//We now define a counter for the step
	
	int n = 1;
	
	
	//With this loop, while the time is below the final time defined, the Runge Kutta algorithm will evolve the Penning Trap system in time
	
	while (t <= tf){

                my_trap.evolve_RK4(h, 0, t, f, w, true, false, true);
		
		//We insert in the matrices previously defined the different values of the position and velocity, values calculated thanks to the Runge Kutta method
                Rrk.insert_cols(n, my_trap.particle_collection[0].r_);
                Vrk.insert_cols(n, my_trap.particle_collection[0].v_);

		n++;

                t = t + h;


        }

	
	
	//We create two .txt files that stores  respectively the matrices that contains the values of the position and velocity of the particle
	
	ofstream ofile1;
        ofile1.open("Problem9a_Rrk.txt");
        ofile1 << scientific;
        ofile1 << Rrk.t() << endl;
        ofile1.close();

        ofstream ofile2;
        ofile2.open("Problem9a_Vrk.txt");
        ofile2 << scientific;
        ofile2 << Vrk.t() << endl;
        ofile2.close();


	return 0;

}
