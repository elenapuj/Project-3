# -*- coding: utf-8 -*-
"""
Created on Tue Oct 12 14:24:04 2021

@author: julianeltoro
"""

with  open('Problem9a_R.txt', "r") as  infile:
    
    lines = infile.readlines ()

    x0: List[float] = []
    y0: List[float] = []
    z0: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        x0.append(float(vals [0]))
        y0.append(float(vals [1]))
        z0.append(float(vals [2]))
        
with  open('Problem9a_V.txt', "r") as  infile:
    lines = infile.readlines ()

    v0x: List[float] = []
    v0y: List[float] = []
    v0z: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        v0x.append(float(vals [0]))
        v0y.append(float(vals [1]))
        v0z.append(float(vals [2]))
        
h = 0.1
tf = 100        
t = np.linspace(0 , tf, tf/h )
plot(t, z0)
plt.title("Motion of one particle in the z direction vs time", fontsize=10)
plt.ylabel("z (μm)" )
plt.xlabel("t (μs)")
plt.grid(True) #Grids get painted
plt.savefig("Problem_9a_plot.pdf")
