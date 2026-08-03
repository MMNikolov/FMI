#include <stdio.h>

int main()
{
    unsigned short x = 0; // 0000000000000000
    printf("Original value of x = %u\n", x);
    
    unsigned short bitSet = 1; // 0000000000000001
    
    unsigned short bitUnset = 0; // 0000000000000000

    // Повдигане нa bit
    x |= bitSet; // 1 | 0 = 1
    printf("Value after bit-set of x = %u\n", x);
    
    // Смъкване на bit
    x &= bitUnset; // 1 & 0 = 0
    printf("Value after bit-unset of x = %u\n", x);

    // Извличане на bit
    unsigned short bitToggle = 1; // 0000000000000001
    bitToggle <<= 3; // 0000000000001000

    //  Искаме да проверим дали bit на index 3 e вдигнат
    x = 26; // 0000000000011010
    short isRaised = (bitToggle & x) != 0;
    printf("The bit at index 3 is: %hu\n", isRaised);
    return 0;
}