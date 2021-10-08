#include "Particle.hpp"


int main(){

vec r1 = vec(3).randn();

vec v1 = vec(3).randn();

Particle prueba(4, 46, r1, v1);


prueba.info();

return 0;

}
