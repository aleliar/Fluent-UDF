# Fluent-UDF
Some easy UDF for Fluent 

********************************Coded base on centOS7*****************************

tranSient.c

1.A transient time varying mass flow rate inlet, define the start value as m1, the final value as m2.

2.A transient time varying pressure outlet, define the start pressure as p1, the goal pressure as p2.

3.A transient time varying injection mass flow rate, define the start fuel flow rate as fuel_m1,  the final fuel flow rate as fuel_m2.

4.Place the tranSien.c under the same path as your case&data file.

5.Open fluent, read case, User-define, Compiled, choose the UDF, build the lib*, load.

6.Change the inlet,outlet and injection with UDF

Notice:

1.For transient simulation only.

2.While using the inejction UDF, there's no need to change the "Total mass flow rate" value, UDF will replace it.
