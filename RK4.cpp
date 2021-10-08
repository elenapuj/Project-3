#include "PenningTrap.hpp"
#include "Particle.hpp"

// Evolve the system one time step (dt) using Runge-Kutta 4th order

void evolve_RK4(double dt) {

	int i;
	int tf;
	vec t = linspace(0, tf, tf / dt);
	vec f = total_force[i] / particle_collection[i].m_;

	for (int k > 0; k++) {
		vec k1 = dt * f[k];
		vec k2 = dt * f(t[i] + dt / 2, y[i] + k1 / 2);
		vec k3 = dt * f(t[i] + dt / 2, y[i] + k2 / 2);
		vec k4 = dt * f(t[i + 1], y[i] + k3 / 2);
		vec y[i + 1] = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}
}