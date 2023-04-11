#include <stdio.h>

// Macro definition for custom sizeof() function
#define MY_SIZEOF(type) ((char*)(&type + 1) - (char*)(&type))

// Inline function definition for custom sizeof() function
static inline size_t my_sizeof_inline(int type) {
    return (char*)(&type + 1) - (char*)(&type);
}

int main() {
    int num = 10;

    // Using custom sizeof() function with macros
    size_t size_macro = MY_SIZEOF(num);
    printf("Size using macro: %zu\n", size_macro);

    // Using custom sizeof() function with inline keyword
    size_t size_inline = my_sizeof_inline(num);
    printf("Size using inline: %zu\n", size_inline);

    // Using regular sizeof() function
    size_t size_regular = sizeof(num);
    printf("Size using regular: %zu\n", size_regular);

    return 0;
}

/*The main difference between the macro and inline versions is how they are expanded and executed.
 Macros are expanded during the preprocessing phase of the compilation process,
  where the macro is replaced with its corresponding code before the actual compilation happens.
   On the other hand, inline functions are expanded during the compilation phase,
 where the function is inserted directly into the calling code.
  This means that macros are expanded at every usage, while inline functions are expanded only once during compilation and the resulting code is included in the final executable.*/