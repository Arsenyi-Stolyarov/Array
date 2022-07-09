#include "Array.h"


int main ()
{
    Array <double, 3> a_1 = { 1.0, 2.0, 3.0 };

    Array <double, 2, 3> a_2 = { { 4.0, 5.0, 6.0 },
                                 { 7.0, 8.0, 9.0 } };

    a_2[0] = a_1;

    a_2[1] = { 0.1, 1.1, 2.1 };

    return 0;
}
