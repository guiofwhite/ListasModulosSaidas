#include <stdio.h>


void listarNotas(float notas[], int quantidade);
float calculaMedia(float notas[], int quantidade);


void mostrarMaiorNota(float notas[], int quantidade);
void mostrarMenorNota(float notas[], int quantidade);
void contarAprovadosEReprovados(float notas[], int quantidade);
void listarAcimaDaMedia(float notas[], int quantidade);

int main()
{
    float notas[10];
    int quantidade = 0;
    int opcao;

    do
    {
        printf("\n====== Sistema de Notas ======\n");
        printf("1 - Cadastrar nota\n");
        printf("2 - Listar todas as notas\n");
        printf("3 - Média da turma\n");
        printf("4 - Mostrar a maior nota\n");
        printf("5 - Mostrar a menor nota\n");
        printf("6 - Contar aprovados e reprovados\n");
        printf("7 - Mostrar notas acima da média da turma\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (quantidade < 10)
            {
                printf("Digite a nota: ");
                scanf("%f", &notas[quantidade]);
                quantidade++;
            }
            else
            {
                printf("Limite de notas atingido (Máx: 10)\n");
            }
            break;
        case 2:
            listarNotas(notas, quantidade);
            break;
        case 3:
            if (quantidade > 0)
            {
                printf("Média da turma: %.2f\n", calculaMedia(notas, quantidade));
            }
            else
            {
                printf("Nenhuma nota cadastrada ainda.\n");
            }
            break;
        case 4:
            mostrarMaiorNota(notas, quantidade);
            break;
        case 5:
            mostrarMenorNota(notas, quantidade);
            break;
        case 6:
            contarAprovadosEReprovados(notas, quantidade); 
            break;
        case 7:
            listarAcimaDaMedia(notas, quantidade);
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}



void listarNotas(float notas[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhuma nota para listar.\n");
        return;
    }
    printf("\n--- Lista de Notas ---\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("Nota %d: %.1f\n", i + 1, notas[i]);
    }
}

float calculaMedia(float notas[], int quantidade)
{
    float soma = 0;
    for (int i = 0; i < quantidade; i++)
    {
        soma += notas[i];
    }
    return soma / quantidade;
}


void mostrarMaiorNota(float notas[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhuma nota cadastrada.\n");
        return;
    }
    float maior = notas[0];
    for (int i = 1; i < quantidade; i++)
    {
        if (notas[i] > maior)
        {
            maior = notas[i];
        }
    }
    printf("A maior nota da turma é: %.1f\n", maior);
}


void mostrarMenorNota(float notas[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhuma nota cadastrada.\n");
        return;
    }
    float menor = notas[0];
    for (int i = 1; i < quantidade; i++)
    {
        if (notas[i] < menor)
        {
            menor = notas[i];
        }
    }
    printf("A menor nota da turma é: %.1f\n", menor);
}


void contarAprovadosEReprovados(float notas[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhuma nota cadastrada.\n");
        return;
    }
    int aprovados = 0;
    int reprovados = 0;

    for (int i = 0; i < quantidade; i++)
    {
        if (notas[i] >= 7.0)
        {
            aprovados++;
        }
        else
        {
            reprovados++;
        }
    }
    printf("Quantidade de alunos aprovados: %d\n", aprovados);
    printf("Quantidade de alunos reprovados: %d\n", reprovados);
}

void listarAcimaDaMedia(float notas[], int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhuma nota cadastrada.\n");
        return;
    }

    float media = calculaMedia(notas, quantidade);
    printf("Média da turma: %.2f\n", media);
    printf("Notas acima da média:\n");

    int encontrou = 0;
    for (int i = 0; i < quantidade; i++)
    {
        if (notas[i] > media)
        {
            printf("- Nota: %.1f\n", notas[i]);
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nenhuma nota está acima da média.\n");
    }
}