#include <stdio.h>
#include <stdlib.h>

  typedef struct point{
        float x;
        float y;
    }point;
    typedef struct triangle{
        point A;
        point B;
        point C;
    }triangle;
int main()
{

    triangle Galaxy ;

 /*   float  (Galaxy.A)-> x = 0.6627  ;
    float (Galaxy.A).y = 0.3365 ;
    float  (Galaxy.B).x = 0.1750  ;
    float (Galaxy.B).y = 0.7315 ;
    float  (Galaxy.C).x = 0.1440  ;
    float (Galaxy.C).y = 0.0431 ;  */
 /*  可能成功的方式   point Galaxy_A , Galaxy_B  , Galaxy_C ;
     (Galaxy_A).y = 0.3365 ;  */
     (Galaxy.A).y = 0.3365 ;
    int  status = -1 ;

    return 0;
}
