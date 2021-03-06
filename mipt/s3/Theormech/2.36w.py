from math import *
def mine(phi0,w,t,w0,R):
 phi=phi0*sin(w*t)
 phit=phi0*cos(w*t)*w
 phitt=-phi0*sin(w*t)*w**2
 theta=-w0*t**2/(2.*R)
 s=-((phit*R-w0*t)**2)/R
 x=s*cos(phi+theta)-R*phitt*sin(phi+theta)+w0*sin(phi+theta)
 y=w0+s*sin(phi+theta)+R*phitt*cos(phi+theta)-w0*cos(phi+theta)
 return((x**2+y**2)**0.5)

def theirs(phi0,w,t,w0,R):
 phi=phi0*sin(w*t)
 phi1=phi0*sin(w*t)-w0*t**2/(2.*R)
 x=R*(w0*t/R-phi0*w*cos(w*t))**2-w0*sin(phi1)
 y=2*w0*sin(phi1/2.)**2+R*w**2*phi0*sin(w*t)
 return((x**2+y**2)**0.5)

phi0=12143.
w=1212.123
t=2132.1
w0=52134.234
R=121234.2143

def test():
 print theirs(phi0,w,t,w0,R)
 print mine(phi0,w,t,w0,R)

test()
