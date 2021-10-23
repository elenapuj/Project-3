import numpy as np
import matplotlib.pyplot as plt
from typing import List

"""
We open two data files, create three vectors for each file, and fill them with the three 
components of the position and velocity of the particle respectively
"""
with  open('1part R RK.txt', "r") as  infile:
    
    lines = infile.readlines ()

    x: List[float] = []
    y: List[float] = []
    z: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        x.append(float(vals [0]))
        y.append(float(vals [1]))
        z.append(float(vals [2]))
        
with  open('1part V RK.txt', "r") as  infile:
    lines = infile.readlines ()

    vx: List[float] = []
    vy: List[float] = []
    vz: List[float] = []
    
    for  line in  lines:
        vals1 = line.split()
        vx.append(float(vals1 [0]))
        vy.append(float(vals1 [1]))
        vz.append(float(vals1 [2]))
 
#Plot
h = 0.1
tf = 100        
t = np.linspace(0 , tf, 1002 )
plt.plot(t, z)
plt.title("Motion of one particle in the z direction vs time", fontsize=10)
plt.ylabel("z (μm)" )
plt.xlabel("t (μs)")
plt.grid(True) #Grids get painted

#The graph is saved in a PDF file
plt.savefig("z vs t.pdf")
