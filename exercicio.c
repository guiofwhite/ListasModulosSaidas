#include <stdio.h>

void listarNotas(float notas[], int quantidade);
float calculaMedia(float notas[], int quantidade);

int main(){
    float notas[10];
    int quantidade = 0;
    int opcao;
    
    
    do{
        printf("\n======Sistema de Notas======\n");
        printf("1 - Cadastrar nota\n");
        printf("2 - Listar notas\n");
        printf("3 - Media da turma\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                if(quantidade < 10){
                    printf("Digite a nota:");
                    scanf("%f", &notas[quantidade]);
                    quantidade++;
                }else{
                    printf("Limite atingido\n");
                }
                break;
            case 2:
                listarNotas(notas, quantidade);
                break;
            case 3:
            printf("Média: %.2f\n", calculaMedia(notas, quantidade));  
                break;
            
        }
    }while (opcao != 0);
    {
        return 0;
    }
} //Final da chave Main bitch

//Módulos

void listarNotas(float notas[], int quantidade){
    for(int i = 0; i < quantidade; i++){
        printf("%.1f\n", notas[i]);
    }

}

float calculaMedia(float notas[], int quantidade){
    float soma = 0;
    for(int i = 0; 1 < quantidade; i++){
        soma += notas[i];
    }
    return soma / quantidade;
}

