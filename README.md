# Project-3

We've used this repository to generate plots for supporting our report about the Penning Trap, a device used to store particles.

In the folder named "Include" you will find every .hpp file that you must download for executing every .cpp, which you will find in the folder "Source". In folder "Phyton" you will find every .py file used to make the plots.


Now we are going to detail a little bit each .cpp file.

First, we have the files "Particle.cpp" and "PenningTrap.cpp" which define the main classes that we will use later. The class "particle" stores the main characteristics of a particle(its charge, mass, etc) and the class "penning trap" stores particles and have some functions that evolve the particle through time. These files are not meant to be directly executed.

In the files "One_particle_Euler.cpp" and "One_particle_RK4.cpp" we evolve only one particle through time using the Foward Euler and the Runge-Kutta method(respectively). With them, we generate the .txt files stored in the folder One particle(In Python/txt files), changing the step-size in the ones used to study the relative error. With this .txt we generate the plots "x vs y RK" and "z vs t RK"(using the file "One particle RK4.py"); "x vs y FE" and "z vs t FE"(using the file "One particle FE.py"); "absolute_error"(using "absolute_error.py"), and "relative_error"(using "relative_error.py").

In the files "Resonance_1" and "Resonance_2" we study the case of 100 particles trapped in our device. With them we produce the plots "Resonance_1" and "Resonance_2", using the python codes "Resonance_1.py" and "Resonance_2.py"(respectively) and the .txt files stored in the folder Resonance(in Python/txt files).
 
And, finally using the file "Two_particles_RK4.cpp" we simulate the case of having two particles in our trap. Changing different desired parameters we generate different .txt files store in the folder Two particles(in Python/txt files) and with them we produce the rest of the plots of the folder Plots(in Python) using the rest of the pyhton files.


For building and execute each of the cpp mentioned before(except for the Particle and the PenningTrap one, as we already said), as, for example "Two_particles_RK4.cpp", you need to have all the files from the folders "Source" and "Include" in the same folder of your computer and write:

Build: g++ Two_particles_RK4.cpp PenningTrap.cpp Particle.cpp -o Two_particles_Rk4.exe -larmadillo
Run: ./Two_particles_RK4.exe
