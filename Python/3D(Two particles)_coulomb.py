from mpl_toolkits import mplot3d
#matplotlib inline
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

plt.figure()
ax = plt.axes(projection='3d')
ax.scatter3D(x_1, y_1, z_1, c=z_1, cmap='Reds')
plt.plot(x_1, y_1, z_1, color = 'red', label = 'Trajectory of the particle 1')
ax.plot(x_1, y_1, z_1, color = 'red')
plt.legend(loc = "lower left")
plt.xlabel("x (μm)")
plt.ylabel("y (μm)")
plt.grid(True)

plt.savefig("3D(Two particles)_coulomb_1.pdf")

plt.figure()
ax = plt.axes(projection='3d')
ax.scatter3D(x_2, y_2, z_2, c=z_2, cmap='Blues')
plt.plot(x_2, y_2, z_2, color = 'blue', label = 'Trajectory of the particle 2')
ax.plot(x_2, y_2, z_2, color = 'blue')
plt.legend(loc = "lower left")
plt.xlabel("x (μm)")
plt.ylabel("y (μm)")
plt.grid(True)

#The graph is saved in a PDF file
plt.savefig("3D(Two particles)_coulomb_2.pdf")
