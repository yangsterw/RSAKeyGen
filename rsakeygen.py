# -*- coding: utf-8 -*-
"""
Created on Fri Aug  9 13:32:52 2019

@author: yang
"""

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sklearn
import gmpy2
from gmpy2 import mpz
import array as arr
# variables

p = 15485867
q = 32452867
e = 9192679

p2 = 14567881
q2 = 15245513
e2 = 12136141

p3 = 14368993
q3 = 11508703
e3 = 3306811

n = p*q
n2 = p2*q2
n3 = p3*q3

phi_n = (p-1)*(q-1)
phi_n2 = (p2-1)*(q2-1)
phi_n3 = (p3-1)*(q3-1)


def is_coprime_phi(phi_n, coprime_to_check):
    while phi_n % coprime_to_check == 0:
        coprime_to_check = input("Enter a prime number, to check if coprime with phi_n")
        e = coprime_to_check
    return True

if not is_coprime_phi(phi_n,e):
        raise ValueError("e is not coprime with phi_n")
        
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)
    
def modinv(coprime, phi_n):
    g, x, y = egcd(coprime, phi_n)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % phi_n
    
d = modinv(e, phi_n)
d2 = modinv(e2, phi_n2)
d3 = modinv(e3, phi_n3)

print("Set #1")
print("p=", p)
print("q=", q)
print("n=", n)
print("e=", e)
print("d=", d)
print("Set #2")
print("p=", p2)
print("q=", q2)
print("e=", e2)
print("n=", n2)
print("d=", d2)
print("Set #3")
print("p=", p3)
print("q=", q3)
print("e=", e3)
print("n=", n3)
print("d=", d3)