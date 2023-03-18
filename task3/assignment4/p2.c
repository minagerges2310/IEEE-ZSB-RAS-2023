#include <stdio.h>

struct database {
  struct {
    char name[50];
    char location[50];
  } shops;

  struct {
    int id;
    float price;
    int quantity;
  } product_info;

  struct {
    int id;
    int products_num;
  } category;
};

int main() {
  struct database data;
  printf("Size of the union: %lu bytes\n", sizeof(data));
  printf("Size of shops structure: %lu bytes\n", sizeof(data.shops));
  printf("Size of product_info structure: %lu bytes\n", sizeof(data.product_info));
  printf("Size of category structure: %lu bytes\n", sizeof(data.category));
  return 0;
}

/*the size of the struct is biger than the size of the union becase in a struct each member is located in its own block of memory, 
but the union all members share the same memory space so the union size is equal to the size of its largest memeber 

so the size of the struct is larger because it includes all three structures as separate members, whereas in the union,
 only one member can be active at any given time, so the union's size is determined solely by its largest member*/