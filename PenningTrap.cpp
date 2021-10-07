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


void external_E_field(vec particle_collection[i].r_ , double v0_ , double d_ ){
	
	vec external_E_field = zeros(3);
	
	external_E_field[0] = v0_ * particle_collection[i].r_[0]  / ( d_ * d_ );
	
	external_E_field[1] =  v0_ * particle_collection[i].r_[1] / ( d_ * d_ );
		
	external_E_field[2] =  - v0_ * 2 * particle_collection[i].r_[2] / ( d_ * d_ );

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
	
	vec total_force_external = zeros(3);
	
	total_force_external[0] = particle_collection[i].q_ * external_E_field[0] + external_B_field[2] * particle_collection[i].v_[1];

	total_force_external[1] = particle_collection[i].q_ * external_E_field[1] - external_B_field[2] * particle_collection[i].v_[0];
		
	total_force_external[2] = 0;

}


void total_force(int i){
	
	vec total_force = total_force_external[i] + total_force_particle[i];

}
