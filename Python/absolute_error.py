import numpy as np
import matplotlib.pyplot as plt
from typing import List

# Data

q = 1 # Charge

b_0 = 96.5 # Magnetic field

m = 40.078 # Mass

v_0 = 9.65e8 # Potential

d =  10000 # Size of the box


# Initial values 

x_0 = 0

v0y = 1

z_0 = 1


# Analythical solutions

w0 = q*b_0 / m

w_z = np.sqrt(2*q*v_0/ (m * d**2))
        
wp = ( w0 + np.sqrt(w0**2-2*w_z**2)) / 2

wl = ( w0 - np.sqrt(w0**2-2*w_z**2)) / 2

Ap = ( v0y + wl * x_0 ) / (wl - wp )

Al = - ( v0y + wp * x_0 ) / (wl - wp )


# Simulated values for different stepsizes

textnames = ['Rel_error_h1.txt' , 'Rel_error_h2.txt' , 'Rel_error_h3.txt' , 
             
             'Rel_error_h4.txt' , 'Rel_error_h5.txt' ]

h_name = [ "0.01" , "0.05" , "0.1" , "0.5" , "1"]

h = ( 0.01 , 0.05 , 0.1 , 0.5 , 1)

max_error = []

for i in  range(0 , 5):
    

    with  open(textnames[i], "r") as  infile:
        
        lines = infile.readlines ()
    
        x: List[float] = []
        y: List[float] = []
        z: List[float] = []
        
        for  line in  lines:
            vals = line.split()
            x.append(float(vals [0]))
            y.append(float(vals [1]))
            z.append(float(vals [2]))
    

    # Time
        
    tf = 100 # Final time
    
    t = np.linspace(0 , tf, len(x) )
    
    # Analythical solution
        
    x_a = Ap * np.cos( wp * t ) + Al * np.cos( wl * t )
    
    y_a = Ap * np.sin( wp * t ) + Al * np.sin( wl * t )
        
    z_a = z_0 * np.cos( w_z * t )
    
  
    # Relative error
    
    abs_e = abs( np.sqrt( ( x_a - x )**2 + ( y_a - y )**2 + ( z_a - z)**2))
    
    max_error_i = max( np.sqrt( ( x_a - x )**2 + ( y_a - y )**2 + ( z_a - z)**2) )
    
    max_error.append( max_error_i )
    
    # Graphs
            
    plt.plot(t, abs_e, label="h=" + h_name[i])
    

        
# General characteristics of the graph
    
plt.title("Absolute error vs time", fontsize=10)
plt.ylabel(r'$abs\_e_{i} (μm)$')
plt.xlabel("t (μs)")
plt.grid(True) #Grid gets painted
plt.legend()
plt.savefig("absolute_error.pdf")
plt.show()




# Error convergence rate

ecri = []

for i in  range(1,4):  
    
    arg = np.log10(max_error[i]/max_error[i-1]) / np.log10(h[i]/h[i-1])
    ecri.append( arg  )
    
ecr = sum(ecri) / 4
