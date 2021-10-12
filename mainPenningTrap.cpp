#include "PenningTrap.hpp"

int main(){

        vec r1 = vec(3).randn();

        vec v1 = vec(3).randn();

        vec r2 = vec(3).randn();

        vec v2 = vec(3).randn();

        Particle particulaprueba1(4, 46, r1, v1);

        Particle particulaprueba2(3, 49, r2, v2);

        vector<Particle> my_particle_collection;

        PenningTrap prueba(5,9,7, my_particle_collection);

        vec B;
        vec f_p;
        vec t_f_p;
        vec t_f_e;
        vec t_f;
        vec E;

        prueba.add_particle(particulaprueba1);

        prueba.external_E_field(E,0);

        prueba.external_B_field(B);

        prueba.force_particle(f_p,0,1);

        prueba.total_force_particle(t_f_p, 0);
  
        prueba.total_force_external(t_f_e, 0);

        prueba.total_force(t_f, 0);

}
