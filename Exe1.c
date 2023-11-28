#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int romanDecimal(char rom[]) {
    int a[100], T, i, k, valor, resultado;
    T = strlen(rom);

    for (i = 0; i < T; i++) {
        switch (rom[i]) {
            case 'I':
                a[i] = 1;
                break;
            case 'V':
                a[i] = 5;
                break;
            case 'X':
                a[i] = 10;
                break;
            case 'L':
                a[i] = 50;
                break;
            case 'C':
                a[i] = 100;
                break;
            case 'D':
                a[i] = 500;
                break;
            case 'M':
                a[i] = 1000;
                break;
            default:
                printf("\nValor invalido\n");
                exit(0);
        }
    }

    k = a[T - 1];

    for (i = T - 1; i > 0; i--) {
        valor = a[i - 1];
        resultado = a[i];

        if (resultado > valor)
            k = k - valor;
        else
            k = k + valor;
    }

    return k;
}

void decimalBinary(int decimal, char rom[]) {
    int binary[100], index = 0;

    do {
        binary[index++] = decimal % 2;
        decimal = decimal / 2;
    } while (decimal > 0);

    printf("%s na base 2: ", rom);
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

void decimalHexadecimal(int decimal, char rom[]) {
    int hexa[100], index1 = 0;

    do {
        int remainder = decimal % 16;
        char hex;
        switch (remainder) {
            case 10:
                hex = 'a';
                break;
            case 11:
                hex = 'b';
                break;
            case 12:
                hex = 'c';
                break;
            case 13:
                hex = 'd';
                break;
            case 14:
                hex = 'e';
                break;
            case 15:
                hex = 'f';
                break;
            default:
                hex = remainder + '0';
                break;
        }
        hexa[index1++] = hex;
        decimal = decimal / 16;
    } while (decimal > 0);

    printf("\n%s na base 16: ", rom);
    for (int i = index1 - 1; i >= 0; i--) {
        printf("%c", hexa[i]);
    }
     printf("\n");
}

int main() {
    char rom[15];
    scanf("%s", rom);

    int decimal = romanDecimal(rom);
    decimalBinary(decimal, rom);
    printf("\n%s na base 10: %d", rom, decimal);
    decimalHexadecimal(decimal, rom);

    return 0;
}
