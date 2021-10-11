//Here we give definitions for the functions in the PenningTrap class

#include "PenningTrap.hpp"


//Vamo pa ello

PenningTrap::PenningTrap(double b0_in, double v0_in, double d_in, vector<Particle> particle_collection_in){

	//We assign the introduced values to the member variables

	b0_ = b0_in;
	v0_ = v0_in;
	d_ = d_in;
	particle_collection = particle_collection_in;

}



//Then we define the diferent methods of the class basically for printing the values

void PenningTrap::add_particle(Particle particle_in){

particle_collection.push_back(particle_in);

}


void PenningTrap::external_E_field(vec& E, int i){

	E[0] = v0_ * particle_collection[i].r_[0]  / ( d_ * d_ );

	E[1] =  v0_ * particle_collection[i].r_[1] / ( d_ * d_ );

	E[2] =  - v0_ * 2 * particle_collection[i].r_[2] / ( d_ * d_ );

}


void PenningTrap::external_B_field(vec& B){

        B[2] = b0_;


}


void PenningTrap::force_particle(vec& f_p, int i, int j){

        f_p = 1.38935333*pow(10,5)*particle_collection[j].q_*particle_collection[i].q_*(particle_collection[i].r_-particle_collection[j].r_)/(pow(norm(particle_collection[i].r_-particle_collection[j].r_),3));

}


void PenningTrap::total_force_particle(vec& t_f_p, int i){

        for (int t = 0; t < particle_collection.size(); t++){

                if (i != t){

		vec f_p(3);

		force_particle(f_p, i, t);

                t_f_p = t_f_p + f_p;

                }
        }

}


void PenningTrap::total_force_external(vec& t_f_e, int i){

	vec E = zeros(3);

	external_E_field(E, i);

	vec B = zeros(3);

	external_B_field(B);

	t_f_e[0] = particle_collection[i].q_ * E[0] + B[2] * particle_collection[i].v_[1];

	t_f_e[1] = particle_collection[i].q_ * E[1] - B[2] * particle_collection[i].v_[0];

	t_f_e[2] = 0;

}


void PenningTrap::total_force(vec& t_f, int i){

	vec t_f_e = zeros(3);

	total_force_external(t_f_e, i);

	vec t_f_p = zeros(3);

	total_force_particle(t_f_e, i);

	vec l_f = t_f_e + t_f_p;

}


