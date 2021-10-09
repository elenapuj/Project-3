#include "PenningTrap.hpp"
#include "Particle.hpp"

// Evolve the system one time step (dt) using Runge-Kutta 4th order

void evolve_RK4(double dt) {

	int i;
	vec y;
	
	
	vec a = total_force[i] / particle_collection[i].m_;

	vec k1 = dt * a;
	vec k2 = dt * a(t + dt / 2, y + k1 / 2);
	vec k3 = dt * a(t + dt / 2, y + k2 / 2);
	vec k4 = dt * a(t+dt, y + k3 / 2);
	y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	vec evolve_RK4 = y;
	
}

int main(){
	
	int tf, v_in;
	//vec t = linspace(0, tf, tf / dt);
	int t = 0;
	int dt = 5;
	vector vv;
	
	while (t <= tf) {
		t = t + dt;
		v_in = evolve_RK4(dt);
		vv.push_back(v_in);

	}

	return 0;
}
