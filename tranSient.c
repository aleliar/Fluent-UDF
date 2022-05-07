/***********************************************************************
    UDF for transition state simulation inlet profile boundary condition and fuel mass inlet profile boundary condition.
***************************************************************************/

#include "udf.h"
#include "unsteady.h"

/* Mass flow inlet */
DEFINE_PROFILE(transient_mdot, thread, position)
{
    real flow_time = CURRENT_TIME;
    real m1 = 0.3336; real m2 = 0.5004;
    real mdot;
    face_t f;

    begin_f_loop(f, thread)
    {
        F_PROFILE(f,thread,position) = (m1+(m2-m1)*flow_time/0.6)/12;
    }
    end_f_loop(f,thread)
}

/*Pressure outlet */
DEFINE_PROFILE(transient_pressure, thread, position)
{
    real flow_time = CURRENT_TIME;
    real p1 = -4500; real p2 = 4120;
    real pout;
    face_t f;

    begin_f_loop(f, thread)
    {
        F_PROFILE(f,thread,position) = p1+(p2-p1)*flow_time/0.6;
    }
    end_f_loop(f,thread)
}

/* transient injection flow rate*/
DEFINE_DPM_INJECTION_INIT(fuel,I)
{
    real flow_time = RP_Get_Real("flow-time");

    real fuel_m1=0.012667, fuel_m2=0.014057;

    I->total_flow_rate = (fuel_m1+(fuel_m2-fuel_m1)*flow_time/0.6)/12;

}
