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

        for (int k = 0; k < particle_collection.size(); k++){

                if (i != k){

			vec f_p(3);

			force_particle(f_p, i, k);

                	t_f_p = t_f_p + f_p;

                }
        }

}


void PenningTrap::total_force_external(vec& t_f_e, int i){

	vec E(3);

	external_E_field(E, i);

	t_f_e[0] = particle_collection[i].q_ * ( E[0] + b0_ * particle_collection[i].v_[1] );

	t_f_e[1] = particle_collection[i].q_ * ( E[1] - b0_ * particle_collection[i].v_[0] );

	t_f_e[2] = particle_collection[i].q_ * E[2];

}


void PenningTrap::total_force(vec& t_f, int i){

	vec t_f_e(3);

	total_force_external(t_f_e, i);

	vec t_f_p = zeros(3);

	total_force_particle(t_f_p, i);

	t_f = t_f_e + t_f_p;

}


void PenningTrap::evolve_forward_Euler(double dt, int i) {

	vec t_f(3);

	total_force(t_f, i);

	vec v_new = particle_collection[i].v_ + dt * t_f / particle_collection[i].m_;

	vec r_new = particle_collection[i].r_ + dt * v_new;

	particle_collection[i].r_ = r_new;

	particle_collection[i].v_ = v_new;

}


void PenningTrap::evolve_RK4(double dt, int i){

	vec r_old = particle_collection[i].r_;
	vec v_old = particle_collection[i].v_;

	vec t_f(3);

	total_force(t_f, i);

	vec a = t_f / particle_collection[i].m_;


	vec K1r = v_old * dt;
	vec K1v = a * dt;


	particle_collection[i].r_ = r_old + K1r / 2;
	particle_collection[i].v_ = v_old + K1v / 2;


	r_old = particle_collection[i].r_;
        v_old = particle_collection[i].v_;

        total_force(t_f, i);

        a = t_f / particle_collection[i].m_;


        vec K2r = v_old * dt;
        vec K2v = a * dt;


        particle_collection[i].r_ = r_old + K2r / 2;
        particle_collection[i].v_ = v_old + K2v / 2;


	r_old = particle_collection[i].r_;
        v_old = particle_collection[i].v_;

        total_force(t_f, i);

        a = t_f / particle_collection[i].m_;


        vec K3r = v_old * dt;
        vec K3v = a * dt;


        particle_collection[i].r_ = r_old + K3r / 2;
        particle_collection[i].v_ = v_old + K3v / 2;


	r_old = particle_collection[i].r_;
        v_old = particle_collection[i].v_;

        total_force(t_f, i);

        a = t_f / particle_collection[i].m_;


        vec K4r = v_old * dt;
        vec K4v = a * dt;


	particle_collection[i].r_ = particle_collection[i].r_ + ( K1r + 2*( K2r + K3r ) + K4r ) / 6;

	particle_collection[i].v_ = particle_collection[i].v_ + ( K1v + 2*( K2v + K3v ) + K4v ) / 6;

}
