#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int is_alpha_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int is_valid_license_plate(char placa[8]) {
   
    if (strlen(placa) == 8 &&
        is_alpha_upper(placa[0]) && is_alpha_upper(placa[1]) && is_alpha_upper(placa[2]) &&
        placa[3] == '-' &&
        is_digit(placa[4]) && is_digit(placa[5]) && is_digit(placa[6]) && is_digit(placa[7])) {
        return 1;
    }
   
    else if (strlen(placa) == 7 &&
             is_alpha_upper(placa[0]) && is_alpha_upper(placa[1]) && is_alpha_upper(placa[2]) &&
             is_digit(placa[3]) && is_alpha_upper(placa[4]) && is_digit(placa[5]) && is_digit(placa[6])) {
        return 2;
    }
   
    else {
        return 0;
    }
}

int main() {
    char placa[9];

    char DiaSemana[20];
    char dia1[] = "SEGUNDA-FEIRA";
    char dia2[] = "TERCA-FEIRA";
    char dia3[] = "QUARTA-FEIRA";
    char dia4[] = "QUINTA-FEIRA";
    char dia5[] = "SEXTA-FEIRA";
    char dia6[] = "SABADO";
    char dia7[] = "DOMINGO";

    scanf("%s", placa);
    limparBuffer();
    scanf("%s", DiaSemana);

    int result = is_valid_license_plate(placa);


    for (int i = 0; DiaSemana[i]; i++) {
        if (result == 0 && DiaSemana[i] >= 'a' && DiaSemana[i] <= 'z') {
            printf("Placa invalida\n");
            printf("Dia da semana invalido\n");
            return 0;
        } else if (result == 0){
            printf("Placa invalida\n");
            return 0;
        } else if (DiaSemana[i] >= 'a' && DiaSemana[i] <= 'z'){
             printf("Dia da semana invalido\n");
            return 0;
        }
    }
   
    int ultimoNumero = placa[strlen(placa) - 1]-'0';
    limparBuffer();

    // Comparar dias da semana
    if (strcmp(DiaSemana, dia1) == 0) {
    if (ultimoNumero == 0 || ultimoNumero == 1) {
        printf("%s nao pode circular segunda-feira\n", placa);
    } else {
        printf("%s pode circular segunda-feira\n", placa);
    }
} else if (strcmp(DiaSemana, dia2) == 0) {
    if (ultimoNumero == 2 || ultimoNumero == 3) {
        printf("%s nao pode circular terca-feira\n", placa);
    } else {
        printf("%s pode circular terca-feira\n", placa);
    }
} else if (strcmp(DiaSemana, dia3) == 0) {
    if (ultimoNumero == 4 || ultimoNumero == 5) {
        printf("%s nao pode circular quarta-feira\n", placa);
    } else {
        printf("%s pode circular quarta-feira\n", placa);
    }
} else if (strcmp(DiaSemana, dia4) == 0) {
    if (ultimoNumero == 6 || ultimoNumero == 7) {
        printf("%s nao pode circular quinta-feira\n", placa);
    } else {
        printf("%s pode circular quinta-feira\n", placa);
    }
} else if (strcmp(DiaSemana, dia5) == 0) {
    if (ultimoNumero == 8 || ultimoNumero == 9) {
        printf("%s nao pode circular sexta-feira\n", placa);
    } else {
        printf("%s pode circular sexta-feira\n", placa);
    }
}  else if (strcmp(DiaSemana, dia6) == 0 || strcmp(DiaSemana, dia7) == 0) {
        printf("Nao ha proibicao no fim de semana\n");
      } else {
        printf("Dia da semana invalido\n");
        return 0;
      }
   
    return 0;
}
