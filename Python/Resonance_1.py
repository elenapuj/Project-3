import numpy as np
import matplotlib.pyplot as plt
from typing import List

"""
We open a data file, create three vectors for each file, and fill them with 
the results of the fraction of particles remaining inside the trap for each 
angular frequency and the constant amplitude f
"""

with  open('Resonance_1.txt', "r") as  infile:
    
    lines = infile.readlines ()

    f1: List[float] = []
    f2: List[float] = []
    f3: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        f1.append(float(vals [0]))
        f2.append(float(vals [1]))
        f3.append(float(vals [2]))
        
#The values of the angular frequency
w_v = np.linspace(0.2 , 2.5 , 116 )

#Plot
plt.plot(w_v, f1, label = "f=0.1", color = "red") 
plt.plot(w_v, f2, label = "f=0.4", color = "blue")
plt.plot(w_v, f3, label = "f=0.7", color = "green")
plt.title(r'Fraction of particles (N=100 particles) inside the trap after 500 $\mu s$ vs $\omega_V$', fontsize=10)
plt.ylabel("Fraction of particles inside" )
plt.xlabel(r'$\omega_V$ (MHz)') 
plt.grid(True) #Grids get painted
plt.legend()

#The graph is saved in a PDF file
plt.savefig("Resonance_1.pdf")

plt.show()

