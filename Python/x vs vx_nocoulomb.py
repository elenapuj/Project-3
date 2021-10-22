import numpy as np
import matplotlib.pyplot as plt
from typing import List

"""
The code opens two data files, creates three vectors for each file, and fills them with the three 
components of the position of each particle when the Coulomb interactions are switched off
"""
with  open('NoCoulomb_r1.txt', "r") as  infile:
    
    lines = infile.readlines ()

    x_1: List[float] = []
    y_1: List[float] = []
    z_1: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        x_1.append(float(vals [0]))
        y_1.append(float(vals [1]))
        z_1.append(float(vals [2]))
        
with  open('NoCoulomb_r2.txt', "r") as  infile:
    lines = infile.readlines ()

    x_2: List[float] = []
    y_2: List[float] = []
    z_2: List[float] = []
    
    for  line in  lines:
        vals1 = line.split()
        x_2.append(float(vals1 [0]))
        y_2.append(float(vals1 [1]))
        z_2.append(float(vals1 [2]))

with  open('NoCoulomb_v1.txt', "r") as  infile:
    
    lines = infile.readlines ()

    vx_1: List[float] = []
    vy_1: List[float] = []
    vz_1: List[float] = []
    
    for  line in  lines:
        vals2 = line.split()
        vx_1.append(float(vals2 [0]))
        vy_1.append(float(vals2 [1]))
        vz_1.append(float(vals2 [2]))
        
with  open('NoCoulomb_v2.txt', "r") as  infile:
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
plt.plot(x_1, vx_1, color = 'red', label = 'Phase space plot of the particle 1')
plt.legend(loc = "lower left")
plt.xlabel("x (μm)")
plt.ylabel("v_x (μm/μs)")
plt.xlim([-210, 210])
plt.ylim([-210, 210])
plt.grid(True)

plt.plot(x_2, vx_2, color = 'blue', label = 'Phase space plot of the particle 2')
plt.legend(loc = "lower left")
plt.xlabel("x (μm)")
plt.ylabel("v_x (μm/μs)")
plt.xlim([-210, 210])
plt.ylim([-210, 210])
plt.grid(True)

#The graph is saved in a PDF file
plt.savefig("Problem_9c_plot_nocoulomb_x.pdf")
