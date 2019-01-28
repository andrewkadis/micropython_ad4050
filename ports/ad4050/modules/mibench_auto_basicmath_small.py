
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

    # Now, solve lots of random equations from the benchmark
    # Have 4 nested iterations to test lots of combinations
    # Note that the benchmark overwrites the original values and we maintain this behaviour here
    for a1 in range(1,10,1):

        for b1 in range(10,0,-1):

            # Because the python 'range' iteration syntax does not support floats, we scale by x10 and then scale back
            # Seems to be the best way to get 'apples-to-apples' with the c benchmark
            c1_range_start = 5
            c1_range_end = 15
            c1_range_step = 0.5
            c1_sf = 10 # Scaling Factors to deal with scaling of floats
            for c1 in range( int(c1_range_start*c1_sf), int(c1_range_end*c1_sf), int(c1_range_step*c1_sf) ):
                # Scale back to float
                c1 = c1/c1_sf

                for d1 in range(-1,-11,-1):

                    # Have iterated through all 4 nested loop for 4 different sets of values
                    # Now Run cubic solver for all our values
                    SolveCubic(a1, b1, c1, d1)
                    # print(f"a1: {a1} b1: {b1} c1: {c1} d1: {d1}")

    ##########################################
    ####### Integer Square Roots #############
    ##########################################
    # Run over a large number of test cases
    for i in range(0,1001,1):
        usqrt(i)
    # Run over a single, specific, very large number
    usqrt(l)

    # t1 = 0x0000FF00
    # t2 = t1 <<16
    # print(f"t2: {t2:x}")


    # t1 = 0x00FF0000
    # t2 = (t1 <<16) & 0xFFFFFFFF
    # print(f"t2: {t2:x}")






# Helper function for Solving Cubics, based on function of same name from 'cubic.c' from benchmark
def SolveCubic(a, b, c, d):

    # Variables to return
    solutions = 0
    x0 = math.nan
    x1 = math.nan
    x2 = math.nan

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





# Main
run_basicmath_small()
print("Benchmark Complete")

# int run_basicmath_small(void)
# {

#   double  x[3];
#   double X;
#   int     solutions;
#   int i;
#   unsigned long l = 0x3fed0169L;
#   struct int_sqrt q;
#   long n = 0;

#   /* solve soem cubic functions */
#   // printf("********* CUBIC FUNCTIONS ***********\n");
#   /* should get 3 solutions: 2, 6 & 2.5   */
#   SolveCubic(a1, b1, c1, d1, &solutions, x);  
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   /* should get 1 solution: 2.5           */
#   SolveCubic(a2, b2, c2, d2, &solutions, x);  
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   SolveCubic(a3, b3, c3, d3, &solutions, x);
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   SolveCubic(a4, b4, c4, d4, &solutions, x);
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   /* Now solve some random equations */
#   for(a1=1;a1<10;a1++) {
#     for(b1=10;b1>0;b1--) {
#       for(c1=5;c1<15;c1+=0.5) {
# 	for(d1=-1;d1>-11;d1--) {
# 	  SolveCubic(a1, b1, c1, d1, &solutions, x);  
# 	  // printf("Solutions:");
# 	  // for(i=0;i<solutions;i++)
# 	    // printf(" %f",x[i]);
# 	  // printf("\n");
# 	}
#       }
#     }
#   }
  
#   // printf("********* INTEGER SQR ROOTS ***********\n");
#   /* perform some integer square roots */
#   for (i = 0; i < 1001; ++i)
#     {
#       usqrt(i, &q);
# 			// remainder differs on some machines
#      // printf("sqrt(%3d) = %2d, remainder = %2d\n",
#      // printf("sqrt(%3d) = %2d\n",
# 	     // i, q.sqrt);
#     }
#   usqrt(l, &q);
#   //printf("\nsqrt(%lX) = %X, remainder = %X\n", l, q.sqrt, q.frac);
#   // printf("\nsqrt(%lX) = %X\n", l, q.sqrt);


#   // printf("********* ANGLE CONVERSION ***********\n");
#   /* convert some rads to degrees */
#   for (X = 0.0; X <= 360.0; X += 1.0)
#     // printf("%3.0f degrees = %.12f radians\n", X, deg2rad(X));
#   // puts("");
#   for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180))
#     // printf("%.12f radians = %3.0f degrees\n", X, rad2deg(X));
  
  
#   return 0;
# }









# int run_basicmath_small(void)
# {
#   double  a1 = 1.0, b1 = -10.5, c1 = 32.0, d1 = -30.0;
#   double  a2 = 1.0, b2 = -4.5, c2 = 17.0, d2 = -30.0;
#   double  a3 = 1.0, b3 = -3.5, c3 = 22.0, d3 = -31.0;
#   double  a4 = 1.0, b4 = -13.7, c4 = 1.0, d4 = -35.0;
#   double  x[3];
#   double X;
#   int     solutions;
#   int i;
#   unsigned long l = 0x3fed0169L;
#   struct int_sqrt q;
#   long n = 0;

#   /* solve soem cubic functions */
#   // printf("********* CUBIC FUNCTIONS ***********\n");
#   /* should get 3 solutions: 2, 6 & 2.5   */
#   SolveCubic(a1, b1, c1, d1, &solutions, x);  
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   /* should get 1 solution: 2.5           */
#   SolveCubic(a2, b2, c2, d2, &solutions, x);  
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   SolveCubic(a3, b3, c3, d3, &solutions, x);
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   SolveCubic(a4, b4, c4, d4, &solutions, x);
#   // printf("Solutions:");
#   for(i=0;i<solutions;i++)
#     // printf(" %f",x[i]);
#   // printf("\n");
#   /* Now solve some random equations */
#   for(a1=1;a1<10;a1++) {
#     for(b1=10;b1>0;b1--) {
#       for(c1=5;c1<15;c1+=0.5) {
# 	for(d1=-1;d1>-11;d1--) {
# 	  SolveCubic(a1, b1, c1, d1, &solutions, x);  
# 	  // printf("Solutions:");
# 	  // for(i=0;i<solutions;i++)
# 	    // printf(" %f",x[i]);
# 	  // printf("\n");
# 	}
#       }
#     }
#   }
  
#   // printf("********* INTEGER SQR ROOTS ***********\n");
#   /* perform some integer square roots */
#   for (i = 0; i < 1001; ++i)
#     {
#       usqrt(i, &q);
# 			// remainder differs on some machines
#      // printf("sqrt(%3d) = %2d, remainder = %2d\n",
#      // printf("sqrt(%3d) = %2d\n",
# 	     // i, q.sqrt);
#     }
#   usqrt(l, &q);
#   //printf("\nsqrt(%lX) = %X, remainder = %X\n", l, q.sqrt, q.frac);
#   // printf("\nsqrt(%lX) = %X\n", l, q.sqrt);


#   // printf("********* ANGLE CONVERSION ***********\n");
#   /* convert some rads to degrees */
#   for (X = 0.0; X <= 360.0; X += 1.0)
#     // printf("%3.0f degrees = %.12f radians\n", X, deg2rad(X));
#   // puts("");
#   for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180))
#     // printf("%.12f radians = %3.0f degrees\n", X, rad2deg(X));
  
  
#   return 0;
# }