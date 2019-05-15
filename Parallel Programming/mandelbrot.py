import numpy as np
import time
from matplotlib import pyplot as plt
from matplotlib import colors
from numba import jit, vectorize, guvectorize, float64, complex64, int32, float32

parallel = True

def main():
    global targetType
    print("Parallel Time: ", end="")
    mandelbrot_image(-2,2,-2,2) #this is the parallel version
    print("Serial/Single Thread CPU Time: ", end="")
    parallel = False
    mandelbrot_image(-2,2,-2,2) #this is the serial version


def mandelbrot_set2(xmin,xmax,ymin,ymax,width,height,maxiter):
    r1 = np.linspace(xmin, xmax, width, dtype=np.float32)
    r2 = np.linspace(ymin, ymax, height, dtype=np.float32)
    c = r1 + r2[:,None]*1j
    if (parallel):
        n3 = mandelbrot_numpyParallel(c,maxiter)
    else:
        n3 = mandelbrot_numpySerial(c,maxiter)
    
    return (r1,r2,n3.T)
    
def mandelbrot_image(xmin,xmax,ymin,ymax,width=5,height=5,maxiter=100000,cmap='gnuplot2'):
    dpi = 72
    img_width = dpi * width
    img_height = dpi * height
    start_time = time.time()
    x,y,z = mandelbrot_set2(xmin,xmax,ymin,ymax,img_width,img_height,maxiter)
    end_time = time.time()
    print("%.4f s" % (end_time - start_time))
    fig, ax = plt.subplots(figsize=(width, height),dpi=72)
    ax.axes.get_xaxis().set_visible(False)
    ax.axes.get_yaxis().set_visible(False)
    ticks = np.arange(0,img_width,3*dpi)
    x_ticks = xmin + (xmax-xmin)*ticks/img_width
    plt.xticks(ticks, x_ticks)
    y_ticks = ymin + (ymax-ymin)*ticks/img_width
    plt.yticks(ticks, y_ticks)
    norm = colors.PowerNorm(0.3)
    ax.imshow(z.T,cmap=cmap,origin='lower',norm=norm)
    plt.uninstall_repl_displayhook()
    plt.tight_layout(0)
    #plt.show()
    

@jit(int32(complex64, int32))
def mandelbrot(c,maxiter):
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


@guvectorize([(complex64[:], int32[:], int32[:])], '(n),()->(n)',target='parallel')
def mandelbrot_numpyParallel(c, maxit, output):
    maxiter = maxit[0]
    for i in range(c.shape[0]):
        output[i] = mandelbrot(c[i],maxiter)





    

main()
    


    

