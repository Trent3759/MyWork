#Created by Josh Yamdogo and Trent Scott
#CSC338 Final Project

import numpy as np
import time
from matplotlib import pyplot as plt
from matplotlib import colors
from numba import jit, vectorize, guvectorize, float64, complex64, int32, float32

runType = "cpu" #either cpu or parallel

def main():
    print( runType.upper() + " Time: ", end="")   #for timing 
    draw_img(-2,2,-2,2) #start the graphing

def mand_set_calc(min_x,max_x,min_y,max_y,width,height,maxiter):
    r1 = np.linspace(min_x, max_x, width, dtype=np.float32)
    r2 = np.linspace(min_y, max_y, height, dtype=np.float32)
    c = r1 + r2[:,None]*1j
    n3 = mand_numpy(c,maxiter)
    return (r1,r2,n3.T)

@jit(int32(complex64, int32))
def mand(c,maxiter):
    nreal = 0
    real = 0
    imag = 0
    for n in range(maxiter):
        nreal = real*real - imag*imag + c.real
        imag = 2* real*imag + c.imag
        real = nreal;
        if real * real + imag * imag > 4.0:
            return n
    return 0

@guvectorize([(complex64[:], int32[:], int32[:])], '(n),()->(n)',target=runType)
def mand_numpy(c, maxit, output):
    maxiter = maxit[0]
    for i in range(c.shape[0]):
        output[i] = mand(c[i],maxiter)

    
def draw_img(min_x,max_x,min_y,max_y,width=5,height=5,maxiter=100000,cmap='gist_ncar'):
    dpi = 72
    img_width = dpi * width
    img_height = dpi * height
    start_time = time.time()    #only want to test the calculation time
    x,y,z = mand_set_calc(min_x,max_x,min_y,max_y, img_width,img_height,maxiter)
    end_time = time.time()      #end calculation time
    print("%.4f s" % (end_time - start_time))
    fig, ax = plt.subplots(figsize=(width, height),dpi=72)
    ax.axes.get_xaxis().set_visible(False)      #hide x axis. y axis hidden in next line
    ax.axes.get_yaxis().set_visible(False)
    ticks = np.arange(0,img_width,3*dpi)
    x_ticks = min_x + (max_x-min_x)*ticks/img_width
    plt.xticks(ticks, x_ticks)
    y_ticks = min_y + (max_y-min_y)*ticks/img_width
    plt.yticks(ticks, y_ticks)
    norm = colors.PowerNorm(0.3)
    ax.imshow(z.T,cmap=cmap,origin='lower',norm=norm)
    plt.uninstall_repl_displayhook()
    plt.tight_layout(0) #tighten the layout
    plt.show()  #show the window

main() #call to main
    


    

