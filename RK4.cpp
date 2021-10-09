#include "PenningTrap.hpp"
#include "Particle.hpp"

// Evolve the system one time step (dt) using Runge-Kutta 4th order

void evolve_RK4(double dt) {

	int i;
	vec y;
	int tf;
	//vec t = linspace(0, tf, tf / dt);
	vec a = total_force[i] / particle_collection[i].m_;

	int k1 = dt * a[k];
	int k2 = dt * a(t[k] + dt / 2, y[i] + k1 / 2);
	int k3 = dt * a(t[i] + dt / 2, y[i] + k2 / 2);
	int k4 = dt * a(t[i + 1], y[i] + k3 / 2);
	y[i + 1] = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
	}
}
