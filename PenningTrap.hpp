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

          PenningTrap(double b0_in, double v0_in, double d_in, vector<Particle> particle_collection_in);


          //Finally, we declare some methods for calculating some important things

	  void add_particle(Particle p_in);
          void external_E_field(vec& E, int i);
	  void external_B_field(vec& B);
	  void force_particle(vec& f_p, int i, int j);
	  void total_force_particle(vec& t_f_p, int i);
	  void total_force_external(vec& t_f_e, int i);
	  void total_force(vec& t_f, int i);

};


#endif
