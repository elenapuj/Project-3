import numpy as np
import matplotlib.pyplot as plt
from typing import List

"""
The code opens two data files, creates three vectors for each file, and fills them with the three 
components of the position of each particle when the Coulomb interactions are switched on
"""
with  open('Coulomb_r1.txt', "r") as  infile:
    
    lines = infile.readlines ()

    x_1: List[float] = []
    y_1: List[float] = []
    z_1: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        x_1.append(float(vals [0]))
        y_1.append(float(vals [1]))
        z_1.append(float(vals [2]))
        
with  open('Coulomb_r2.txt', "r") as  infile:
    lines = infile.readlines ()

    x_2: List[float] = []
    y_2: List[float] = []
    z_2: List[float] = []
    
    for  line in  lines:
        vals1 = line.split()
        x_2.append(float(vals1 [0]))
        y_2.append(float(vals1 [1]))
        z_2.append(float(vals1 [2]))
 
#Plot
plt.plot(x_1, y_1, color = 'red', label = 'Motion of the particle 1 in the x-y plane')
plt.legend(loc = "lower left")
plt.ylabel("y (μm)")
plt.xlabel("x (μm)")
plt.xlim([-2500, 2500])
plt.ylim([-2500, 2500])
plt.grid(True)

plt.plot(x_2, y_2, color = 'blue', label = 'Motion of the particle 2 in the x-y plane')
plt.legend(loc = "lower left")
plt.ylabel("y (μm)")
plt.xlabel("x (μm)")
plt.xlim([-2500, 2500])
plt.ylim([-2500, 2500])
plt.grid(True)

#The graph is saved in a PDF file
plt.savefig("Problem_9b_plot_coulomb.pdf")
