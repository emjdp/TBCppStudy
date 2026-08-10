// Chapter9_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Calc.h"

int main()
{

    Calc cal(10);
    /* cal.add(10);
     cal.sub(1);
     cal.mult(2);*/
    cal.add(10).sub(1).mult(2).print();

    //cal.print();

    return 0;
}

