// Linux compile and run : gcc -std=c99 flags_all_in_binary.c -o flags_all_in_binary.out && ./flags_all_in_binary.out
// Mac compile and run   : gcc flags_all_in_binary.c -o flags_all_in_binary.out && ./flags_all_in_binary.out

// Print binary from `1<<0` to `1<<18`
#include <stdio.h>

void printBitsRightToLeft(unsigned int num)
{
    int t = num;
    for (int bit = 0; bit < (sizeof(unsigned int) * 8); bit++)
    {
        t = num >> (31 - bit);
        printf("%i ", t & 0x01);
    }
    printf("\n");
}

int main()
{
    printf("All flags of `ifconfig` in binary:\n");
    for (int i = 0; i <= 18; i++)
    {
        printBitsRightToLeft(1 << i);
    }
    printf("`sizeof(int)`: %i Bytes = %i bits\n", (int)sizeof(int), (int)sizeof(int) * 8);
    return 0;
}