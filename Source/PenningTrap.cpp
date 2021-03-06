//Here we give definitions for the functions in the PenningTrap class

#include "PenningTrap.hpp"


//Constructor of the Penning Trap class

PenningTrap::PenningTrap(double b0_in, double v0_in, double d_in, vector<Particle> particle_collection_in) {

	//We assign the introduced values to the member variables

	b0_ = b0_in;
	v0_ = v0_in;
	d_ = d_in;
	particle_collection = particle_collection_in;

}


//Then we define the diferent methods of the class basically for printing the values


//Method that adds a particle to the trap by copying an input Particle

void PenningTrap::add_particle(Particle particle_in) {

	particle_collection.push_back(particle_in);

}


//Method that adds n particles

void PenningTrap::add_n_particles(double n , int q, double m , int d ) {

	for (int i = 1; i <= n; i++) {

		Particle particle_in(q, m, vec(3).randn() * 0.1 * d, vec(3).randn() * 0.1 * d);

		add_particle(particle_in);

	}

}



//Method that sets a random position and velocity

void PenningTrap::randomize_r_and_v(double N , int d) {


	for (int l = 0; l < N; l++) {

		particle_collection[l].r_ = vec(3).randn() * 0.1 * d;

		particle_collection[l].v_ = vec(3).randn() * 0.1 * d;

	}

}



//Method that calculates the external electric field

void PenningTrap::external_E_field(vec& E, int i, double t, double f, double w, bool time_dependence) {

	//The calculation of the external electric field varies depending on whether it depends on time or not. That's something that we set with the bool time_dependence
	
	if (time_dependence) {

		E[0] = v0_ * (1 + f * cos(w * t)) * particle_collection[i].r_[0] / (d_ * d_);

		E[1] = v0_ * (1 + f * cos(w * t)) * particle_collection[i].r_[1] / (d_ * d_);

		E[2] = -v0_ * (1 + f * cos(w * t)) * 2 * particle_collection[i].r_[2] / (d_ * d_);

	}

	else {

		E[0] = v0_ * particle_collection[i].r_[0] / (d_ * d_);

		E[1] = v0_ * particle_collection[i].r_[1] / (d_ * d_);

		E[2] = -v0_ * 2 * particle_collection[i].r_[2] / (d_ * d_);

	}

}



//Method that gives the value of the external magnetic field

void PenningTrap::external_B_field(vec& B) {

	B[2] = b0_;

}



//Method that calculates the force between two particles, i.e. the Coulomb force 

void PenningTrap::force_particle(vec& f_p, int i, int j) {

	vec dr = particle_collection[i].r_ - particle_collection[j].r_;

	double dr_norm = pow(arma::norm(dr), 3);

	vec dr_ = dr / dr_norm;

	f_p = 1.38935333 * pow(10, 5) * particle_collection[j].q_ * particle_collection[i].q_ * dr_;

}



//Method that calcuates the total force between the particle i and the rest of each particles in the particle collection

void PenningTrap::total_force_particle(vec& t_f_p, int i) {

	for (int k = 0; k < particle_collection.size(); k++) {

		if (i != k) {

			vec f_p(3);

			force_particle(f_p, i, k);

			t_f_p = t_f_p + f_p;

		}
	}

}



//Method that calculates the total external force, i.e. the Lorentz force, to which the particle is subjected due to the electric and magnetic field of the trap

void PenningTrap::total_force_external(vec& t_f_e, int i, double t, double f, double w, bool time_dependence) {

	//First, we calculate the electric force
	
	vec E(3);

	external_E_field(E, i, t, f, w, time_dependence);

	//Then we calculate the three components of the Lorentz force
	
	t_f_e[0] = particle_collection[i].q_ * (E[0] + b0_ * particle_collection[i].v_[1]);

	t_f_e[1] = particle_collection[i].q_ * (E[1] - b0_ * particle_collection[i].v_[0]);

	t_f_e[2] = particle_collection[i].q_ * E[2];

}



//Method that calculates the sum of all forces

void PenningTrap::total_force(vec& t_f, int i, double t, double f, double w, bool null_exterior, bool time_dependence, bool coulomb) {

	//The calculation of the sum of all forces depends on whether the fields E and B are zero outside the trap or not
	
	if (null_exterior) {

		if (norm(particle_collection[i].r_) < d_) {

			//The calculation of the total force also depends if the Coulomb interactions are taking or not into account
			
			if (coulomb) {

				vec t_f_e(3);

				total_force_external(t_f_e, i, t, f, w, time_dependence);

				vec t_f_p = zeros(3);

				total_force_particle(t_f_p, i);

				t_f = t_f_e + t_f_p;

			}

			else {

				vec t_f_e(3);

				total_force_external(t_f_e, i, t, f, w, time_dependence);

				t_f = t_f_e;

			}

		}


		else {

			if (coulomb) {

				vec t_f_p = zeros(3);

				total_force_particle(t_f_p, i);

				t_f = t_f_p;

			}

			else {

				t_f = zeros(3);

			}

		}

	}


	else {


		if (coulomb) {

			vec t_f_e(3);

			total_force_external(t_f_e, i, t, f, w, time_dependence);

			vec t_f_p = zeros(3);

			total_force_particle(t_f_p, i);

			t_f = t_f_e + t_f_p;

		}

		else {

			vec t_f_e(3);

			total_force_external(t_f_e, i, t, f, w, time_dependence);

			t_f = t_f_e;

		}

	}

}



//Method that evolves the PenningTrap system in time using the forward Euler method

void PenningTrap::evolve_forward_Euler(double dt, int i, double t, double f, double w, bool null_exterior, bool time_dependence, bool coulomb) {

	//We get the total force acting on the particle i
	
	vec t_f(3);

	total_force(t_f, i, t, f, w, null_exterior, time_dependence, coulomb);

	//Here we calculate the new values of the velocity and the position of the particle
	
	vec v_new = particle_collection[i].v_ + dt * t_f / particle_collection[i].m_;

	vec r_new = particle_collection[i].r_ + dt * v_new;

	particle_collection[i].r_ = r_new;

	particle_collection[i].v_ = v_new;

}



//Method that evolves the PenningTrap system in time using the RK4 method

void PenningTrap::evolve_RK4(double dt, int i, double t, double f, double w, bool null_exterior, bool time_dependance, bool coulomb) {

	//We define the initial values of the position and velocity of the particle
	
	vec r_old = particle_collection[i].r_;
	vec v_old = particle_collection[i].v_;
	
	
	//We get the total force acting on the particle i

	vec t_f(3);

	total_force(t_f, i, t, f, w, null_exterior, time_dependance, coulomb);

	
	//This vector represents the acceleration of the particle
	
	vec a = t_f / particle_collection[i].m_;

	
	//Using it, we calculate k1
	
	vec K1r = v_old * dt;
	vec K1v = a * dt;

	
	//We assign the new values to the position and velocity of the particle
	
	particle_collection[i].r_ = r_old + K1r / 2;
	particle_collection[i].v_ = v_old + K1v / 2;


	//We calculate the force again using the new position and velocity
	
	total_force(t_f, i, t + dt / 2, f, w, null_exterior, time_dependance, coulomb);

	
	//Now we calculate the new value of the acceleration of the particle
	
	a = t_f / particle_collection[i].m_;

	
	//And, then, k2
	
	vec K2r = particle_collection[i].v_ * dt;
	vec K2v = a * dt;

	
	//We assign the new values to the position and velocity of the particle
	
	particle_collection[i].r_ = r_old + K2r / 2;
	particle_collection[i].v_ = v_old + K2v / 2;
	
	
	//We repeat the process to now get k3

	total_force(t_f, i, t + dt / 2, f, w, null_exterior, time_dependance, coulomb);

	a = t_f / particle_collection[i].m_;

	vec K3r = particle_collection[i].v_ * dt;
	vec K3v = a * dt;

	
	//We assign the new values to the position and velocity of the particle
	
	particle_collection[i].r_ = r_old + K3r;
	particle_collection[i].v_ = v_old + K3v;

	
	//We repeat the process again for getting k4

	total_force(t_f, i, t + dt, f, w, null_exterior, time_dependance, coulomb);

	a = t_f / particle_collection[i].m_;

	vec K4r = particle_collection[i].v_ * dt;
	vec K4v = a * dt;

	
	//Finally we get the values of th position and velocity of the particle for the next value of time i+1
	
	particle_collection[i].r_ = r_old + (K1r + 2 * (K2r + K3r) + K4r) / 6;

	particle_collection[i].v_ = v_old + (K1v + 2 * (K2v + K3v) + K4v) / 6;

}

	
//Method that counts how many particles are still inside the trap region

double PenningTrap::number_particles_inside(){

	double number_inside = 0;

	for (int i = 0; i < particle_collection.size(); i++) {

		if (norm(particle_collection[i].r_) < d_) {

			number_inside++;
			//cout << number_inside << endl;
			//cout << norm(particle_collection[i].r_) << endl;
			//particle_collection[i].r_.print("r");
		}
	}

	return number_inside;

}
