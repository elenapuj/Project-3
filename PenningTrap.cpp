//Here we give definitions for the functions in the PenningTrap class

#include "PenningTrap.hpp"


//Vamo pa ello

PenningTrap::PenningTrap(double b0_in, double v0_in, double d_in, vector particle_collection_in){

	//We assign the introduced values to the member variables

	b0_ = b0_in;
	v0_ = v0_in;
	d_ = d_in;

}



//Then we define the diferent methods of the class basically for printing the values

void PenningTrap::add_particle(Particle particle_in){

particle_collection.push_back(particle_in);

}


void external_E_field(vec r_){



}


void external_B_field(double b0_in){

	vec external_B_field = vec(3, fill::zeros);
        external_B_field[2] = b0_in;


}


void force_particle(int i, int j){



}


void total_force_particle(int i){



}


void total_force_external(int i){



}


void total_force(int i){



}
