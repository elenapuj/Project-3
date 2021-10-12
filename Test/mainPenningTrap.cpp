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

        vec pruebaB = zeros(3);
        vec pruebaf_p(3);
        vec pruebat_f_p = zeros(3);
        vec pruebat_f_e = zeros(3);
        vec pruebat_f(3);
        vec pruebaE = zeros(3);

        prueba.add_particle(particulaprueba1);

	prueba.add_particle(particulaprueba2);

        prueba.external_E_field(pruebaE,0);

	pruebaE.print("E=");

        prueba.external_B_field(pruebaB);

	pruebaB.print("B=");

        prueba.force_particle(pruebaf_p,0,1);

	pruebaf_p.print("Force between two particles=");

        prueba.total_force_particle(pruebat_f_p, 0);

	pruebat_f_p.print("Total force particle=");

        prueba.total_force_external(pruebat_f_e, 0);

	pruebat_f_e.print("Total external force=");

        prueba.total_force(pruebat_f, 0);

	pruebat_f.print("Total force=");

	return 0;

}
