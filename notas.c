#include <stdio.h>

int main()
{
    int n, i;
    float soma = 0, media, maior, menor;
    int aprovados = 0, reprovados = 0;

    printf("Quantas notas deseja inserir? ");
    scanf("%d", &n);

    // Correção 1: Declarado como vetor para armazenar todas as notas
    float notas[n];

    for (i = 0; i < n; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]); // Correção 2: Adicionado & e corrigido o scanf

        soma += notas[i];

        if (i == 0)
        {
            maior = notas[i];
            menor = notas[i];
        }

        if (notas[i] > maior)
            maior = notas[i];
        if (notas[i] < menor)
            menor = notas[i];

        if (notas[i] >= 6.0)
        {
            aprovados++;
        }
        else
        {
            reprovados++;
        }
    }

    media = soma / n;

    printf("\n----- Resultados -----\n");
    printf("1- Maior nota: %.2f\n", maior);
    printf("2- Menor nota: %.2f\n", menor);
    printf("3- Alunos aprovados: %d\n", aprovados);
    printf("4- Alunos reprovados: %d\n", reprovados);
    printf("5- Notas acima da media (%.2f): ", media);

    for (i = 0; i < n; i++)
    {
        if (notas[i] > media)
        {
            printf("%.2f ", notas[i]);
        }
    }
    printf("\n");

    return 0;
}
