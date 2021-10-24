import numpy as np
import matplotlib.pyplot as plt
from typing import List

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
       
w_v = np.linspace(0.25 , 0.75 , 116 )
plt.figure(figsize=(5,5))
plt.plot(w_v, no_coulomb, label = "Without Coulomb", color = "blue")
plt.plot(w_v, coulomb, label = "With Coulomb", color = "red") 
plt.title(r'Fraction of particles (N=100 particles) inside the trap after 500 $\mu s$ vs $\omega_V$', fontsize=10)
plt.ylabel("Fraction of particles inside" )
plt.xlabel(r'$\omega_V$ (MHz)') 
plt.grid(True) #Grids get painted
plt.legend(loc='right', bbox_to_anchor=(1.46, 0.5), ncol = 1)
plt.savefig("Resonance_2_3.pdf", bbox_inches=('tight'))
plt.show()
