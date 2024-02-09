/* C program to calculate the volume of a cylinder. */

#include <math.h>
#include <stdio.h>

int main() {

    // declare a constant for PI
    const double PI = M_PI;

    // Declare a variable for the radius of the cylinder
    double radius;

    printf("Enter the radius of the cylinder: ");

    // assign the radius entered by the user to the variable radius
    scanf("%lf", &radius);

    printf("Enter the height of the cylinder: ");

    // declare a variable for height of the cylinder
    // and assign it with the value that the user enters
    double height;
    scanf("%lf", &height);

    // declare a variable for the volume of the cylinder
    double volume;

    // calculate the volume of the cylinder
    // volume of cylinder = PI * r * r * h
    volume = PI * pow(radius,2) * height;

    double cone_volume = volume / 3;


    // print the volume of the cylinder to the console
    printf("The volume of the cylinder = %.2f\n", volume);

    printf("The volume of the cone = %.2f\n", cone_volume);

    printf("The volume of the cylinder and cone are = %f and %f resp.\n", volume, cone_volume);

}