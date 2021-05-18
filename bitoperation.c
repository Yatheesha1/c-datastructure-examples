#include <stdio.h>
#include <stdint.h>

typedef struct _Bits
{
    uint8_t a0:1; // LSB
    uint8_t a1:1;
    uint8_t a2:1;
    uint8_t a3:1;
    uint8_t a4:1;
    uint8_t a5:1;
    uint8_t a6:1;
    uint8_t a7:1; // MSB
} Bits;

typedef struct _Nibble
{
    uint8_t a0:4; // LSN
    uint8_t a1:4; // MSN
} Nibble;


int main() {
    Bits bits = {1, 1, 1, 0, 0, 0, 0, 0};

    Nibble nibble = {0b0000, 0b0001};

    printf("Value bits: %d\n", *(uint8_t *)(&bits));
    printf("Value nibble: %d\n", *(uint8_t *)(&nibble));
    return 0;
}