# -*- coding: utf-8 -*-
"""
Created on Sat Oct 23 19:15:44 2021

@author: julia
"""


import numpy as np
import matplotlib.pyplot as plt
from typing import List

with  open('Problem10a.txt', "r") as  infile:
    
    lines = infile.readlines ()

    f1: List[float] = []
    f2: List[float] = []
    f3: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        f1.append(float(vals [0]))
        f2.append(float(vals [1]))
        f3.append(float(vals [2]))
        
h = 0.1
tf = 100        
w_z = np.linspace(0.2 , 2.5 , 116 )
plt.plot(w_z, f1, label = "f=0.1") 
plt.plot(w_z, f2, label = "f=0.4")
plt.plot(w_z, f3, label = "f=0.7")
plt.title(r'Fraction of particles (N=100 particles) inside the trap after 500 $\mu s$ vs $\omega_z$', fontsize=10)
plt.ylabel("Fraction of particles inside" )
plt.xlabel(r'$\omega_z$ (MHz)') 
plt.grid(True) #Grids get painted
plt.legend()
plt.savefig("Resonance_1.pdf")
plt.show()

