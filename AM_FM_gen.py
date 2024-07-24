# -*- coding: utf-8 -*-
"""
Created on Tue Jul 23 21:15:43 2024

@author: hp
"""
import numpy as np
import matplotlib.pyplot as plt

t=np.linspace(0, 0.004,1000000)

def AM_sig(carrier_freq_,modu_freq_,gain_,depth_):
    carrier_w = 2*np.pi*carrier_freq_
    modu_w = 2*np.pi*modu_freq_
    return gain_*(1+depth_*np.cos(t*modu_w))*np.cos(t*carrier_w)
    
def FM_sig(carrier_freq_,modu_freq_,gain_,offset_freq_):
    carrier_w = 2*np.pi*carrier_freq_
    modu_w = 2*np.pi*modu_freq_
    offset_w = 2*np.pi*offset_freq_
    beta=offset_w/modu_w
    return np.cos(t*carrier_w+beta*np.sin(t*modu_w))

def AM_chart(carrier_freq_,modu_freq_,gain_,depth_):
    chart=AM_sig(carrier_freq_,modu_freq_,gain_,depth_)
    T=1.0/modu_freq_
    points=1000
    
    return
    
    
    

am_sig=AM_sig(1e4,4e3,1,0.5)
fm_sig=FM_sig(1e4,1e3,1,5e3)



fig = plt.figure(figsize=(12,6))
plt.plot(t,am_sig)
