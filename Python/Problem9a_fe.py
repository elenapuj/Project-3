# -*- coding: utf-8 -*-
"""
Created on Tue Oct 12 14:24:04 2021

@author: julianeltoro
"""

import numpy as np
import matplotlib.pyplot as plt
from typing import List

with  open('Problem9a_Rfe.txt', "r") as  infile:
    
    lines = infile.readlines ()

    x: List[float] = []
    y: List[float] = []
    z: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        x.append(float(vals [0]))
        y.append(float(vals [1]))
        z.append(float(vals [2]))
        
with  open('Problem9a_Vfe.txt', "r") as  infile:
    lines = infile.readlines ()

    vx: List[float] = []
    vy: List[float] = []
    vz: List[float] = []
    
    for  line in  lines:
        vals1 = line.split()
        vx.append(float(vals1 [0]))
        vy.append(float(vals1 [1]))
        vz.append(float(vals1 [2]))
        
h = 0.1
tf = 100        
t = np.linspace(0 , tf, 1002 )
plt.plot(t, z)
plt.title("Motion of one particle in the z direction vs time", fontsize=10)
plt.ylabel("z (μm)" )
plt.xlabel("t (μs)")
plt.grid(True) #Grids get painted
plt.show()
plt.savefig("Problem_9a_plot_fe.pdf")

plt.plot(x, y)
plt.title("Motion of one particle in the xy plane", fontsize=10)
plt.ylabel("y (μm)" )
plt.xlabel("x (μm)")
plt.grid(True) #Grids get painted
plt.show()
plt.savefig("Problem_9a_plot_xy_fe.pdf")