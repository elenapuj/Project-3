//Here we give definitions for the functions in the Particle class

#include "Particle.hpp"


//Constructor

Particle::Particle(double q_in, double m_in, vec r_in, vec v_in){

	//We assign the introduced values to the member variables

	q_ = q_in;
	m_ = m_in;
	r_ = r_in;
	v_ = v_in;

}



//Then we define the diferent methods of the class basically for printing the values

void Particle::q(){

	cout << "q=" << q_ << endl;
	cout << endl;

}




void Particle::m(){

	cout << "m=" << m_ << endl;
	cout << endl;

}


void Particle::r(){

	r_.print("r=");

}


void Particle::v(){

	v_.print("v=");

}


void Particle::info(){

	cout << "q=" << q_ << endl;
        cout << endl;
	cout << "m=" << m_ << endl; 
        cout << endl;
	r_.print("r=");
	v_.print("v=");

}

