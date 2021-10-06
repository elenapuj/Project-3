//Here we define the "Particle" class

#ifndef __Particle_hpp__
#define __Particle_hpp__


#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;


class Particle{

	public:

	  //First we declare the member variables

	  double q_, m_;
	  vec r_, v_;


	  //Then, we declare also the constructor

	  Particle(double q_in, double m_in, vec r_in, vec v_in);


	  //Finally, we declare some methods so we are able to print everything later if needed

	  void q();
	  void m();
	  void r();
	  void v();
	  void info();

};


#endif
