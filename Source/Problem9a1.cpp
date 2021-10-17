#include "PenningTrap.hpp"


int main(){

        vector<Particle> my_particle_collection;

        PenningTrap my_trap( 96.5, 9.65 * pow(10 , 8), 10000 , my_particle_collection);

        vec r0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial position
        vec v0 = vec(3).randn() * 0.1 * my_trap.d_;  // random initial velocity

        Particle my_particle( 1 , 40.078 , r0 , v0);

        my_trap.add_particle(my_particle);

	double f = 0;

	double w = 0;

        double h = 0.1; //stepsize

        double t = 0; //initial time

        double tf = 100; //final time

        int n = 1;

        mat Rrk, Vrk;

        Rrk << r0[0] << endr
            << r0[1] << endr
            << r0[2];

        Vrk << v0[0] << endr
            << v0[1] << endr
            << v0[2];


	while (t <= tf){

                my_trap.evolve_RK4(h, 0, t, f, w, true, false, true);

                Rrk.insert_cols(n, my_trap.particle_collection[0].r_);
                Vrk.insert_cols(n, my_trap.particle_collection[0].v_);

		n++;

                t = t + h;


        }


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
