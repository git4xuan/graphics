#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ABS_FLOAT_0  0.00001

int main()
{
    typedef struct point{
        float x;
        float y;
    }point;
    typedef struct triangle{
        point A;
        point B;
        point C;
    }triangle;

    float Side_length (point M , point N ){
        float length ;
        length = fabs( sqrt((M.x - N.x)*(M.x - N.x) + (M.y - N.y)*(M.y - N.y)) );
        return length ;
    }

/*这四个标定的是可以直接认为是可用的三角形，不过如果需要输入新的三角形的时候就要考虑这个问题*/
    int Is_triangle(triangle one){
        /*   one.A  one.B one.C */
        /*counting Three side length , AB , AC , BC */
        /*判断是否为一个三角形*/

        float AB ,AC ,BC ;
        AB = Side_length(one.A , one.B );
        AC = Side_length(one.A , one.C );
        BC = Side_length(one.B , one.C );

        if ( ( (AB*AC*BC)> 0 )&&( (AB+BC) > AC )&&( (AB+AC) > BC ) &&( (AC+BC) > AB )  )
            return 1;
        else
            return 0;
    }
    float Get_Triangle_Square (point A , point B ,point C ){
        float AB ,AC ,BC ;
        float  square , semi_perimeter ;
        AB = Side_length(A , B );
        AC = Side_length(A , C );
        BC = Side_length(B , C );
        semi_perimeter =( AB + AC + BC )/2 ;
        square = sqrt(semi_perimeter * (semi_perimeter - AB ) * (semi_perimeter - BC ) * (semi_perimeter - AC ) );
        return square;
    }

    int Is_display(point CIE_point , point A , point B ,point C){
        float SABC , SADB , SADC , SBDC ;
        float SumSquare ;
        SABC = Get_Triangle_Square(A ,B ,C);
        SADB = Get_Triangle_Square(A, CIE_point ,B);
        SADC = Get_Triangle_Square(A , CIE_point , C);
        SBDC = Get_Triangle_Square(B ,CIE_point , C );
        SumSquare = SADC + SADB + SBDC ;
        if((-ABS_FLOAT_0 < ( SABC - SumSquare )) && ((SABC - SumSquare) < ABS_FLOAT_0   )){
            return 1;
        }
        else{
        return 0 ;
        }
    }

    float color_x , color_y , color_z ;
    float CIE_x , CIE_y;
    point CIE_point;
    triangle Galaxy , iPad , AdobeRGB , sRGB ;
    int status_G = -1 , status_i = -1 , status_A = -1 , status_s = -1 ;
    int count = 0;
    /*, (iPad , Adobe_RGB , sRGB ; */
/*-------------------------Input value of CIE_triangle------------------*/
       (Galaxy.A).x = 0.6627 ; (Galaxy.A).y = 0.3365  ;
       (Galaxy.B).x = 0.1750 ; (Galaxy.B).y = 0.7315  ;
       (Galaxy.C).x = 0.1440 ; (Galaxy.C).y = 0.0431  ;
       (iPad.A).x   = 0.6476 ; (iPad.A).y   = 0.3293  ;
       (iPad.B).x   = 0.3062 ; (iPad.B).y   = 0.6109  ;
       (iPad.C).x   = 0.1525 ; (iPad.C).y   = 0.0454  ;
       (AdobeRGB.A).x = 0.64; (AdobeRGB.A).y = 0.33 ;
       (AdobeRGB.B).x = 0.21; (AdobeRGB.B).y = 0.71 ;
       (AdobeRGB.C).x = 0.15; (AdobeRGB.C).y = 0.16 ;
       (sRGB.A).x   = 0.64; (sRGB.A).y = 0.33 ;
       (sRGB.B).x   = 0.30; (sRGB.B).y = 0.60 ;
       (sRGB.C).x   = 0.15; (sRGB.C).y = 0.06 ;
/*  方式错了这里需要直接将数字输入到三角形的角上的数字上。*/
/*----下次还是默认输入的好，调试的话先写一组数据就行了，后期再添加 -----*/
/*   GNU GCC 中无法使用//方式？？好像过不了调试， 使用的是MingW  */
/*   需要使用括号表明范围，接着这里的赋值无需添加float  ，其中在这个地方已经得到表明了 */

    /*(Galaxy.A).x = 0.6627  ;
     (Galaxy.A).y = 0.3365 ;
      (Galaxy.B).x = 0.1750  ;
     (Galaxy.B).y = 0.7315 ;
      (Galaxy.C).x = 0.1440  ;
     (Galaxy.C).y = 0.0431 ;    */
   /* int  status = -1 ;  */

    while (scanf("%f %f %f" , &color_x,&color_y,&color_z) != EOF ){
   /* printf("%6.2f %6.2f\n", color_x , color_y);*/
       CIE_x = color_x/(color_x + color_y + color_z);
       CIE_y = color_y/(color_x + color_y + color_z);
       /*对CIE_point这个点进行赋值*/
       CIE_point.x = CIE_x;  /*表示这个待求颜色的x和y值，后面判断是否在三角形内*/
       CIE_point.y = CIE_y;

       status_G = -1 , status_i = -1 , status_A = -1 , status_s = -1 ;
       status_G = Is_display (CIE_point , Galaxy.A , Galaxy.B , Galaxy.C );
       status_i = Is_display (CIE_point , iPad.A , iPad.B , iPad.C );
       status_A = Is_display (CIE_point , AdobeRGB.A , AdobeRGB.B , AdobeRGB.C );
       status_s = Is_display (CIE_point , sRGB.A , sRGB.B , sRGB.C );

       count++;
       printf("#######################Color%d########################\n",count );
       printf("##                           Status                ##\n");
       printf("##  Device:Galaxy               %d                  ##\n",status_G );
       printf("##  Device:iPad2                %d                  ##\n",status_i );
       printf("##  Standard:AdobeRGB           %d                  ##\n",status_A );
       printf("##  Standard:sRGB               %d                  ##\n",status_s );
       printf("##                                                 ##\n");
       printf("## When Status is 1  , it means This color can be  ##\n");
       printf("## displayed in Devices\/Standard ,if Status is 0 , ##\n");
       printf("## it means can not be.                            ##\n");
       printf("#####################################################\n");
       printf("\n");
       printf("\n");
       printf("\n");
       printf("if you want to test more Colors' CIE-XYZ ,Please input \n");
       printf("Color_X  Color_Y Color_Z  \n");
    }

 /*   color_x = 234.56 , color_y = 234.567;
    printf("%4.2f\n%.2f \n" , color_x , color_y);
*/
    return 0;
}
