import numpy as np
import matplotlib.pyplot as plt
from typing import List

"""
We open two data files, create a vector for each file, and fill them with 
the results of the fraction of particles remaining inside the trap for each 
angular frequency for a constant amplitude f=0.4 with and without taking into 
account Coulomb's force
"""

with  open('Resonance_2.txt', "r") as  infile:
    
    lines = infile.readlines ()

    no_coulomb: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        no_coulomb.append(float(vals [0]))
        
with  open('Resonance_3.txt', "r") as  infile:
    
    lines = infile.readlines ()

    coulomb: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        coulomb.append(float(vals [0]))
        
#The values of the angular frequency (near a resonance)
w_v = np.linspace(0.25 , 0.75 , 116 )

#Plot
plt.figure(figsize=(5,5)) #Squared plot
plt.plot(w_v, no_coulomb, label = "Without Coulomb", color = "blue")
plt.plot(w_v, coulomb, label = "With Coulomb", color = "red") 
plt.title(r'Fraction of particles (N=100 particles) inside the trap after 500 $\mu s$ vs $\omega_V$', fontsize=10)
plt.ylabel("Fraction of particles inside" )
plt.xlabel(r'$\omega_V$ (MHz)') 
plt.grid(True) #Grids get painted
plt.legend(loc='right', bbox_to_anchor=(1.46, 0.5), ncol = 1)

#The graph is saved in a PDF file
plt.savefig("Resonance_2_3.pdf", bbox_inches=('tight'))
plt.show()
