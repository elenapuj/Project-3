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

with  open('Coulomb_v1.txt', "r") as  infile:
    
    lines = infile.readlines ()

    vx_1: List[float] = []
    vy_1: List[float] = []
    vz_1: List[float] = []
    
    for  line in  lines:
        vals2 = line.split()
        vx_1.append(float(vals2 [0]))
        vy_1.append(float(vals2 [1]))
        vz_1.append(float(vals2 [2]))
        
with  open('Coulomb_v2.txt', "r") as  infile:
    lines = infile.readlines ()

    vx_2: List[float] = []
    vy_2: List[float] = []
    vz_2: List[float] = []
    
    for  line in  lines:
        vals3 = line.split()
        vx_2.append(float(vals3 [0]))
        vy_2.append(float(vals3 [1]))
        vz_2.append(float(vals3 [2]))
        
#Plot
plt.plot(z_1, vz_1, color = 'red', label = 'Phase space plot of the particle 1')
plt.legend(loc = "lower left")
plt.xlabel("z (μm)")
plt.ylabel("v_z (μm/μs)")
plt.xlim([-75, 75])
plt.ylim([-75, 75])
plt.grid(True)

plt.plot(z_2, vz_2, color = 'blue', label = 'Phase space plot of the particle 2')
plt.legend(loc = "lower left")
plt.xlabel("z (μm)")
plt.ylabel("v_z (μm/μs)")
plt.xlim([-75, 75])
plt.ylim([-75, 75])
plt.grid(True)

#The graph is saved in a PDF file
plt.savefig("PhaseSpace z Coulomb.pdf")
