#include <stdio.h>

union database {
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
  union database data;
  printf("Size of the union: %lu bytes\n", sizeof(data));
  printf("Size of shops structure: %lu bytes\n", sizeof(data.shops));
  printf("Size of product_info structure: %lu bytes\n", sizeof(data.product_info));
  printf("Size of category structure: %lu bytes\n", sizeof(data.category));
  return 0;
}