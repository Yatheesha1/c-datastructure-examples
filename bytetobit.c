#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


int main() {
    uint8_t g_data = 128;

    printf("Enter number:");
    scanf("%" SCNu8, &g_data);

    uint8_t data = g_data;

    printf("%d: ", data);

    for (uint8_t i = 0; i< 8; i++) { // LSB->MSB
        uint8_t a = data%2;
        printf("%d", a);
        data = data/2;
    }

    data = g_data;
    printf("\n%d: ", data);

    for (uint8_t i = 0; i< 8; i++) { // LSB->MSB
        uint8_t a = (data & 0x01);
        printf("%d", a);
        data = data >> 1;
    }

    data = g_data;
    printf("\n%d: ", data);

    for (uint8_t i = 0; i< 8; i++) { // MSB->LSB
        uint8_t a = (data & 0x80);
        if (a) {
            printf("%d", 1);
        } else {
            printf("%d", 0);
        }
        
        data <<= 1;
    }

    data = g_data;
    printf("\n%d: ", data);

    for (uint8_t i = 0; i< 8; i++) { // MSB->LSB
        uint8_t a = (data >> (8-i-1)) & 0x01;
        printf("%d", a);
    }

    printf("\n");

    return 0;
}