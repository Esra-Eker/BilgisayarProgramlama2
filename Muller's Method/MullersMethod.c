#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    printf("-------------------------------------\n\tMuller's Method\n\tEsra Eker\n\t17025047\n-------------------------------------");
    //I defined the function
    printf("\nf(x)=x^3 - (3.7)x^2 + (6.25)x - 4.069\n-------------------------------------");

    //I defined all the variables that I will use in this program.
    double xb, xs, xm;
    double fxb, fxs, fxm;
    double a, b, c;
    double D, D1, D2, D3;
    double delta;
    double x1, x2;

    //The user is prompted to enter interval values.
    printf("\nEnter xb value: ");
    scanf("%lf", &xb);

    printf("Enter xs value: ");
    scanf("%lf", &xs);

    //The xm value is calculated.
    xm = (xb + xs) / 2;

    //The corresponding function values are calculated.
    fxb = pow(xb, 3) - (3.7) * pow(xb, 2) + (6.25) * (xb)-4.069;
    fxm = pow(xm, 3) - (3.7) * pow(xm, 2) + (6.25) * (xm)-4.069;
    fxs = pow(xs, 3) - (3.7) * pow(xs, 2) + (6.25) * (xs)-4.069;

    //fxb, fxm, fxs values are printed on the screen.
    printf("\nf(xb)=%f\n", fxb);
    printf("f(xm)=%f\n", fxm);
    printf("f(xs)=%f\n", fxs);

    //If there is a root in the interval, the evaluation starts.
    if (fxb * fxs < 0)
    {
        printf("There is a root in the interval entered.\n\n");
        printf("y = ax^2 + bx + c\n");
        //The calculated values are written instead in the parabola.
        printf("%f =  a(%f) + b(%f)  + c\n", fxb, pow(xb, 2), xb);
        printf("%f =  a(%f) + b(%f)  + c\n", fxm, pow(xm, 2), xm);
        printf("%f =  a(%f) + b(%f)  + c\n", fxs, pow(xs, 2), xs);
        
        //The resulting system of equations is solved by the Cramer's rule.
        //The matrices are changing, so I calculated them one by one.
        D = pow(xb, 2) * (xm * 1 - xs * 1) - (xb) * (pow(xm, 2) * 1 - pow(xs, 2) * 1) + 1 * (pow(xm, 2) * (xs)-pow(xs, 2) * (xm));
        printf("D= %f\n", D);

        D1 = (fxb) * ((xm) * 1 - (xs) * 1) - (xb) * ((fxm) * 1 - (fxs) * 1) + 1 * ((fxm) * (xs)-(fxs) * (xm));
        printf("D1= %f\n", D1);

        D2 = pow(xb, 2) * (fxm * 1 - fxs * 1) - (fxb) * (pow(xm, 2) * 1 - pow(xs, 2) * 1) + 1 * (pow(xm, 2) * (fxs)-pow(xs, 2) * (fxm));
        printf("D2= %f\n", D2);

        D3 = pow(xb, 2) * ((xm) * (fxs)-(xs) * (fxm)) - 1 * (pow(xm, 2) * (fxs)-pow(xs, 2) * (fxm)) + (fxb) * (pow(xm, 2) * (xs)-pow(xs, 2) * (xm));
        printf("D3= %f\n\n", D3);

        a = D1 / D;
        b = D2 / D;
        c = D3 / D;

        //The found values of a, b and c are printed on the screen.
        printf("a= %f\n", a);
        printf("b= %f\n", b);
        printf("c= %f\n\n", c);

        //The found values a, b and c are printed in the function.
        printf("f(x) =  (%f)x^2 + (%f)x + (%f)\n", a, b, c);

        //The roots of the function are calculated.
        delta = b * b - 4 * a * c;

        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("The first root of the function: %f\n", x1);
        printf("The second root of the function: %f\n", x2);

        //It is checked whether the roots are within the entered interval.
        if (xb < x1)
            if (x1 < xs)
            {
                printf("\nThe root of the function in the entered interval: %f ", x1);
            }
        if (xb < x2)
            if (x2 < xs)
            {
                printf("\nThe root of the function in the entered interval: %f ", x2);
            }
    }
    //If there is no root in the entered interval, the calculation is not made.
    else
    {
        printf("There is no root in the interval entered.");
    }
    return 0;

}
