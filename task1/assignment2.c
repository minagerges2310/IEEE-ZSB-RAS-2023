#include <stdio.h>

int main() {
    int x = 1, y = 2, z = 3;
    int *p, *q, *r;
    p = &x;
    q = &y;
    r = &z;

    // Print the values of x, y, z, p, q, r, *p, *q, *r
    printf("x = %d\ny = %d\nz = %d\np = %p\nq = %p\nr = %p\n*p = %d\n*q = %d\n*r = %d\n",
           x, y, z, (void *)p, (void *)q, (void *)r, *p, *q, *r);

    // Swap pointers
    printf("\nSwapping pointers...\n");
    int *temp = r;
    r = p;
    p = q;
    q = temp;

    // Print the values of x, y, z, p, q, r, *p, *q, *r
    printf("\nx = %d\ny = %d\nz = %d\np = %p\nq = %p\nr = %p\n*p = %d\n*q = %d\n*r = %d\n",
           x, y, z, (void *)p, (void *)q, (void *)r, *p, *q, *r);

    return 0;
}
