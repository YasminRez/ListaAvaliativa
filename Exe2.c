#include <stdio.h>
#include <math.h>
int main() {
int tempo;
double dinheiroA, taxa, valorFinal;

scanf("%d", &tempo);
scanf("%lf %lf", &dinheiroA, &taxa);
for(int i=1; i<= tempo; i++){
    valorFinal = dinheiroA * (1 + taxa) * ((pow ((1 + taxa), i) - 1) / taxa);
    printf("Montante ao fim do mes %d: R$ %.2lf\n", i, valorFinal);
}


    return 0;
}
