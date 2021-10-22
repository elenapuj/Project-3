#include "PenningTrap.hpp"


//In this file we will obtain data of the the position and velocity  of two particles in a trap where E has not time dependence


int main(){

	//First we set up our Penning Trap with the desired conditions

        vector<Particle> my_particle_collection;

        PenningTrap my_trap( 96.5, 9.65 * pow(10 , 8), 10000 , my_particle_collection);

	//Here we introduce some other conditions

	double f = 0;  //It's only relevant when E is time dependant

        double w = 0;  //Same as f

        double h = 0.1;  //Stepsize

        double t = 0;  //Initial time

        double tf = 100;  //Final time


	//After that, we create and introduce 2 particles in the trap. The initial conditions must be the same for both particles

	int N = 2;  //Number of particles

	vec r01;
	r01 << 0 << 0 << 0 << endr;
	vec v01 = vec(3).randu() * h * my_trap.d_;
	
	vec r02;
	r02 << 5 << 5 << 5 << endr;
	vec v02= vec(3).randu() * h * my_trap.d_;


        Particle my_particle1( 1 , 40.078 , r01 , v01);
	Particle my_particle2( 1 , 40.078 , r02 , v02);

        my_trap.add_particle(my_particle1);
	my_trap.add_particle(my_particle2);



	//Then, we create matrices for storing the position and velocity of each particle at each moment, writing in the first position the initial values

        mat Rrk1, Vrk1;

        Rrk1 << my_trap.particle_collection[0].r_[0] << endr
             << my_trap.particle_collection[0].r_[1] << endr
             << my_trap.particle_collection[0].r_[2];

        Vrk1 << my_trap.particle_collection[0].v_[0] << endr
             << my_trap.particle_collection[0].v_[1] << endr
             << my_trap.particle_collection[0].v_[2];


	mat Rrk2, Vrk2;

        Rrk2 << my_trap.particle_collection[0].r_[0] << endr
             << my_trap.particle_collection[0].r_[1] << endr
             << my_trap.particle_collection[0].r_[2];

        Vrk2 << my_trap.particle_collection[0].v_[0] << endr
             << my_trap.particle_collection[0].v_[1] << endr
             << my_trap.particle_collection[0].v_[2];



	//We create a counter for counting the step

	int n = 1;


	//Now we evolve the system using the Runge-Kutta 4 method

	while (t <= tf){

                my_trap.evolve_RK4(h, 0, t, f, w, false, false, false);
		Rrk1.insert_cols(n, my_trap.particle_collection[0].r_);
                Vrk1.insert_cols(n, my_trap.particle_collection[0].v_);

		my_trap.evolve_RK4(h, 1, t, f, w, false, false, false);
		Rrk2.insert_cols(n, my_trap.particle_collection[1].r_);
                Vrk2.insert_cols(n, my_trap.particle_collection[1].v_);

		n++;  //Here we sum one to the counter

                t = t + h;  //And then we upload the time

        }



	//Finally we write the position and the velocity of each particle in a file

	ofstream ofile1;
        ofile1.open("Problem9a_Rrk1.txt");
        ofile1 << scientific;
        ofile1 << Rrk1.t() << endl;
        ofile1.close();

        ofstream ofile2;
        ofile2.open("Problem9a_Vrk1.txt");
        ofile2 << scientific;
        ofile2 << Vrk1.t() << endl;
        ofile2.close();


	ofstream ofile3;
        ofile3.open("Problem9a_Rrk2.txt");
        ofile3 << scientific;
        ofile3 << Rrk2.t() << endl;
        ofile3.close();

        ofstream ofile4;
        ofile4.open("Problem9a_Vrk2.txt");
        ofile4 << scientific;
        ofile4 << Vrk2.t() << endl;
        ofile4.close();


	return 0;

}
