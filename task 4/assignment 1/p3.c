#include <stdio.h>

typedef unsigned char byte;
typedef short int16;
typedef int int32;
typedef long int64; 
typedef float float32; 
typedef double float64; 
int main() {
   printf("size of byte: %lu\n", sizeof(byte)); 
   printf("size of int16: %lu\n", sizeof(int16));  
   printf("size of int32: %lu\n", sizeof(int32)); 
   printf("size of int64: %lu\n", sizeof(int64)); 
   printf("size of float32: %lu\n", sizeof(float32));
   printf("size of float64: %lu\n", sizeof(float64)); 

   return 0;
}