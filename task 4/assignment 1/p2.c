#include <stdio.h>

typedef struct {
   float real;
   float imag;
} complex;

complex add(complex n1, complex n2);

int main() {
   complex num1, num2, result;

   printf("enter the real and imaginary parts of the first complex number: ");
   scanf("%f %f", &num1.real, &num1.imag);

   printf("enter the real and imaginary parts of the second complex number: ");
   scanf("%f %f", &num2.real, &num2.imag);

   result = add(num1, num2);
   printf("Sum = %.1f + %.1fi", result.real, result.imag);

   return 0;
}

complex add(complex n1, complex n2) {
   complex temp;
   temp.real = n1.real + n2.real;
   temp.imag = n1.imag + n2.imag;
   return temp;
}