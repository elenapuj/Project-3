//Here we give definitions for the functions in the PenningTrap class

//FALTA DE ACABAR DE COMENTAR

#include "PenningTrap.hpp"

//Constructor of the Penning Trap class
PenningTrap::PenningTrap(double b0_in, double v0_in, double d_in, vector<Particle> particle_collection_in){

	//We assign the introduced values to the member variables

	b0_ = b0_in;
	v0_ = v0_in;
	d_ = d_in;
	particle_collection = particle_collection_in;

}


//Then we define the diferent methods of the class basically for printing the values

//Method that adds a particle to the trap by copying an input Particle
void PenningTrap::add_particle(Particle particle_in){

	particle_collection.push_back(particle_in);
	
}

//Method that adds n particles
void PenningTrap::add_n_particles(int n , int q, double m , int d ) {

	for (int i = 1; i <= n; i++) {

		Particle particle_in(q, m, vec(3).randn() * 0.1 * d, vec(3).randn() * 0.1 * d);

		add_particle(particle_in);

	}

}
//Method that calculates the external electric field
void PenningTrap::external_E_field(vec& E, int i, double t, double f, double w, bool time_dependence){
	
	//The calculation of the external electric field varies depending on whether it depends on time or not
	if (time_dependence){

		E[0] = v0_ * ( 1 + f * cos( w * t ) ) *  particle_collection[i].r_[0]  / ( d_ * d_ );

                E[1] =  v0_ * particle_collection[i].r_[1] / ( d_ * d_ );

                E[2] =  - v0_ * 2 * particle_collection[i].r_[2] / ( d_ * d_ );

	}

	else{

		E[0] = v0_ * particle_collection[i].r_[0]  / ( d_ * d_ );

		E[1] =  v0_ * particle_collection[i].r_[1] / ( d_ * d_ );

		E[2] =  - v0_ * 2 * particle_collection[i].r_[2] / ( d_ * d_ );

	}

}

//Method that gives the value of the external magnetic field
void PenningTrap::external_B_field(vec& B){

        B[2] = b0_;

}

//Method that calculates the force between two particles, i.e. the Coulomb force 
void PenningTrap::force_particle(vec& f_p, int i, int j){

        f_p = 1.38935333*pow(10,5)*particle_collection[j].q_*particle_collection[i].q_*(particle_collection[i].r_-particle_collection[j].r_)/(pow(norm(particle_collection[i].r_-particle_collection[j].r_),3));

}

//Method that calcuates the total force between the particle i and the rest of each particles in the particle collection
void PenningTrap::total_force_particle(vec& t_f_p, int i){

        for (int k = 0; k < particle_collection.size(); k++){
	
                if (i != k){

			vec f_p(3);

			force_particle(f_p, i, k);

                	t_f_p = t_f_p + f_p;

                }
        }

}

//Method that calculates the total external force, i.e. the Lorentz force, to which the particle is subjected
void PenningTrap::total_force_external(vec& t_f_e, int i, double t, double f, double w, bool time_dependence){

	vec E(3);

	external_E_field(E, i, t, f, w, time_dependence);
	
	//We calculate the three components of the Lorentz force
	t_f_e[0] = particle_collection[i].q_ * ( E[0] + b0_ * particle_collection[i].v_[1] );

	t_f_e[1] = particle_collection[i].q_ * ( E[1] - b0_ * particle_collection[i].v_[0] );

	t_f_e[2] = particle_collection[i].q_ * E[2];

}

//Method that calculates the sum of all forces
void PenningTrap::total_force(vec& t_f, int i, double t, double f, double w, bool null_exterior, bool time_dependence, bool coulomb){
	
	//The calculation of the sum of all forces depends on wether the external fields E and B are zero or not
	if (null_exterior){

		if( norm(particle_collection[i].r_) < d_ ){
			
			//The calculation of the total force also depends if the Coulomb interactions are taking or not into account
			if (coulomb){

                        	vec t_f_e(3);

                        	total_force_external(t_f_e, i, t, f, w, time_dependence);

                        	vec t_f_p = zeros(3);

                        	total_force_particle(t_f_p, i);

                        	t_f = t_f_e + t_f_p;

                	}

                	else{

                        	vec t_f_e(3);

                        	total_force_external(t_f_e, i, t, f, w, time_dependence);

                        	t_f = t_f_e;

                	}

		}


		else{

			if (coulomb){

                                vec t_f_p = zeros(3);

                                total_force_particle(t_f_p, i);

                                t_f = t_f_p;

                        }

                        else{

                                t_f = zeros(3);

                        }

		}

	}


	else{


		if (coulomb){

			vec t_f_e(3);

			total_force_external(t_f_e, i, t, f, w, time_dependence);

			vec t_f_p = zeros(3);

			total_force_particle(t_f_p, i);

			t_f = t_f_e + t_f_p;

		}

		else{

			vec t_f_e(3);

                        total_force_external(t_f_e, i, t, f, w, time_dependence);

			t_f = t_f_e;

		}

	}

}

//Method that evolves the PenningTrap system in time using the forward Euler method
void PenningTrap::evolve_forward_Euler(double dt, int i, double t, double f, double w, bool null_exterior, bool time_dependence, bool coulomb) {

	vec t_f(3);

	total_force(t_f, i, t, f, w, null_exterior, time_dependence, coulomb);

	//Here we calculate the new values of the velocity and the position of the particle
	vec v_new = particle_collection[i].v_ + dt * t_f / particle_collection[i].m_;

	vec r_new = particle_collection[i].r_ + dt * v_new;

	particle_collection[i].r_ = r_new;

	particle_collection[i].v_ = v_new;

}

//Method that evolves the PenningTrap system in time using the RK4 method
void PenningTrap::evolve_RK4(double dt, int i, double t, double f, double w, bool null_exterior, bool time_dependance, bool coulomb){
	
	//We define the initial values of the position and velocity of the particle
	vec r_old = particle_collection[i].r_;
	vec v_old = particle_collection[i].v_;

	vec t_f(3);

	total_force(t_f, i, t, f, w, null_exterior, time_dependance, coulomb);

	//This vector represents the acceleration of the particle
	vec a = t_f / particle_collection[i].m_;

	vec K1r = v_old * dt;
	vec K1v = a * dt;

	//We assign the new values to the position and velocity of the particle
	particle_collection[i].r_ = r_old + K1r / 2;
	particle_collection[i].v_ = v_old + K1v / 2;


        total_force(t_f, i, t + dt/2, f, w, null_exterior, time_dependance, coulomb);

	//Now we calculate the new value of the acceleration of the particle
        a = t_f / particle_collection[i].m_;


        vec K2r = particle_collection[i].v_ * dt;
        vec K2v = a * dt;

	//We assign the new values to the position and velocity of the particle
        particle_collection[i].r_ = r_old + K2r / 2;
        particle_collection[i].v_ = v_old + K2v / 2;

        total_force(t_f, i, t + dt/2, f, w, null_exterior, time_dependance, coulomb);

	//Now we calculate the new value of the acceleration of the particle
        a = t_f / particle_collection[i].m_;

        vec K3r = particle_collection[i].v_ * dt;
        vec K3v = a * dt;

	//We assign the new values to the position and velocity of the particle
        particle_collection[i].r_ = r_old + K3r;
        particle_collection[i].v_ = v_old + K3v;


        total_force(t_f, i, t + dt, f, w, null_exterior, time_dependance, coulomb);

        a = t_f / particle_collection[i].m_;

        vec K4r = particle_collection[i].v_ * dt;
        vec K4v = a * dt;

	//Finally we get the values of th position and velocity of the particle for the next value of time i+1
	particle_collection[i].r_ = r_old + ( K1r + 2*( K2r + K3r ) + K4r ) / 6;

	particle_collection[i].v_ = v_old + ( K1v + 2*( K2v + K3v ) + K4v ) / 6;

}

	//Method that
double PenningTrap::number_particles_inside(){

	double number_inside = 0;

	for (int e = 0; e < particle_collection.size(); e++) {

		if (norm(particle_collection[e].r_) < d_) {

			number_inside++;

		}
	}

	return number_inside;


}
