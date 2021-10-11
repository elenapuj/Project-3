//Here we define the "PenningTrap" class

#ifndef __PenningTrap_hpp__
#define __PenningTrap_hpp__


#include "Particle.hpp"


class PenningTrap{

        public:

          //First we declare the member variables

          double b0_, v0_, d_;
          vector<Particle> particle_collection;


          //Then, we declare also the constructor

	  PenningTrap() {}

          PenningTrap(double b0_in, double v0_in, double d_in);


          //Finally, we declare some methods for calculating some important things

	  void add_particle(Particle p_in);
          void external_E_field(vec r_);
	  void external_B_field(double b0_in);
	  void force_particle(int i, int j);
	  void total_force_particle(int i);
	  void total_force_external(int i);
	  void total_force(int i);

};


#endif
