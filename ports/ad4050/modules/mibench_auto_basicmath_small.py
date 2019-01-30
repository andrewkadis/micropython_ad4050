
import math

# Python version of MiBench, Automotive Set, Basic Maths, Small Benchmark
# Manually converted by hand by A. Kadis, 28th Jan 2018
def run_basicmath_small():

    # Define Key Values
    a1=1.0
    b1=-10.5
    c1=32.0
    d1=-30.0

    a2=1.0
    b2=-4.5
    c2=17.0
    d2=-30.0

    a3=1.0
    b3=-3.5
    c3=22.0
    d3=-31.0

    a4=1.0
    b4=-13.7
    c4=1.0
    d4=-35.0

    # Large number to find sqrt to solve - from benchmark    
    l = 0x3fed0169

    ##########################################
    ######### Solve Some Cubics ##############
    ##########################################

    # Initial 4 solutions from the benchmark
    SolveCubic(a=a1, b=b1, c=c1, d=d1)
    SolveCubic(a=a2, b=b2, c=c2, d=d2)
    SolveCubic(a=a3, b=b3, c=c3, d=d3)
    SolveCubic(a=a4, b=b4, c=c4, d=d4)

    print("HereA\n\r")

    # Now, solve lots of random equations from the benchmark
    # Have 4 nested iterations to test lots of combinations
    # Note that the benchmark overwrites the original values and we maintain this behaviour here
    for a1 in range(1,2,1):

        for b1 in range(10,0,-9):

            # Because the python 'range' iteration syntax does not support floats, we scale by x10 and then scale back
            # Seems to be the best way to get 'apples-to-apples' with the c benchmark
            c1_range_start = 5
            c1_range_end = 6
            c1_range_step = 0.5
            c1_sf = 10 # Scaling Factors to deal with scaling of floats
            for c1 in range( int(c1_range_start*c1_sf), int(c1_range_end*c1_sf), int(c1_range_step*c1_sf) ):
                # Scale back to float
                c1 = c1/c1_sf

                for d1 in range(-1,-2,-1):

                    # Have iterated through all 4 nested loop for 4 different sets of values
                    # Now Run cubic solver for all our values
                    SolveCubic(a1, b1, c1, d1)
                    # print(f"a1: {a1} b1: {b1} c1: {c1} d1: {d1}")

    print("End\n\r")
    ##########################################
    ####### Integer Square Roots #############
    ##########################################
    # Run over a large number of test cases
    for i in range(0,1001,1):
        usqrt(i)
    # Run over a single, specific, very large number
    usqrt(l)

    ##########################################
    ########## Angle Conversions #############
    ##########################################
    for X in range(0,360,1):
        deg2rad(X)
    # Radian To Degrees test is temporarily disabled due to issues with float iterations in python...
    # Corresponding function is disabled in benchmark
    # for X in range(0,360,1):
    #     rad2deg(X)






# Helper function for Solving Cubics, based on function of same name from 'cubic.c' from benchmark
def SolveCubic(a, b, c, d):

    # Variables to return
    solutions = 0
    x0 = 0
    x1 = 0
    x2 = 0

    # Maths equations from benchmark
    a1 = b/a
    a2 = c/a
    a3 = d/a
    Q = (a1*a1 - 3.0*a2)/9.0
    R = (2.0*a1*a1*a1 - 9.0*a1*a2 + 27.0*a3)/54.0;
    R2_Q3 = R*R - Q*Q*Q

    # Check for number of solutions
    if R2_Q3 <= 0:
        solutions = 3
        theta = math.acos(R/math.sqrt(Q*Q*Q))
        x0 = -2.0*math.sqrt(Q)*math.cos(theta/3.0) - a1/3.0
        x1 = -2.0*math.sqrt(Q)*math.cos((theta+2.0*math.pi)/3.0) - a1/3.0
        x2 = -2.0*math.sqrt(Q)*math.cos((theta+4.0*math.pi)/3.0) - a1/3.0

    else:

        solutions = 1
        x0 = math.pow(math.sqrt(R2_Q3)+math.fabs(R), 1/3.0);
        x0 += Q/x0;
        if R < 0.0:
            x0 *= 1
        else:
            x0 *= -1
        x0 -= a1/3.0;

    # Print if enabled
    # print(f"NumSolutions: {solutions} x0: {x0} x1: {x1} x2: {x2}")






# Helper function for square roots of unsigned integers, based on function of same name from 'isqrt.c' from benchmark
# Please see this file for respective notes on the algorithm employed
def usqrt(x):

    BITSPERLONG = 32
    a = 0 # accumulator
    r = 0 # remainder
    e = 0 # trial product

    for i in range(0,BITSPERLONG,1):

        top2bits = ( (x & (3<<(BITSPERLONG-2))) >> (BITSPERLONG-2) )
        r = ((r<<2)) + top2bits
        x = (x<<2)
        a = (a<<1)
        e = ((a<<1)) + 1
        if r>=e:
            r = r-e
            a = a+1

    # Print if enabled
    # print(f"accumulator: {a} remainder: {r} trial product: {e}")






# Helper function for Degrees To Radians and Radians to Degrees, based on functions of same name from 'rad2deg.c' from benchmark
def rad2deg(rad):
    180.0 * rad / math.pi 
def deg2rad(deg):
    math.pi  * deg / 180.0




# Main
print("Benchmark Started")
run_basicmath_small()
print("Benchmark Complete")
