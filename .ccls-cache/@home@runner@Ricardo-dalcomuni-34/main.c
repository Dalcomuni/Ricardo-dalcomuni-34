#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
  printf("************************************\n");
  printf("* Bem vindo ao jogo de adivinhação *\n");
printf("************************************\n\n");

  int segundos = time(0);
  srand(segundos);
  int numGrand = rand();

  printf("Dificuldades:\n");
  printf("1=facil\n");
  printf("2=médio\n");
  printf("3=dificil\n");
  printf("Escolha uma dificuldade:\n");
  
  int d;
  scanf("%d", &d);

  int chances;
  if (d==1) {
    chances = 15;
  } else if (d==2) {
    chances = 10;
  } else if (d==3) {
    chances = 5;
  } else {
    chances = 1;
  }

  int numSecret = numGrand % 100;
  int ganhou = 0;
  int tentativas = 1;
  int pontos = 1000;
  int pontosPerdidos = 0;

  for (int i = 1; i <= chances; i++) {

    if (pontos <= 0) {

      printf("Você perdeu todos os seus pontos.");
      printf("\nO número secreto era %d", numSecret);
      break;

    }

    printf("Tentativa %d de %d", i, chances);
    printf("\nSeus pontos são: %d", pontos);
    printf("\nChute um número: ");
    int chute;
    scanf("%d", &chute);

    int acertou = numSecret == chute;
    int maior = chute < numSecret;
    int menor = chute > numSecret;

    pontosPerdidos = abs(chute - numSecret);



    if (chute == 0) {
      printf("\nVocê não pode usar o 0\n\n");
      continue;
    }

    if (chute < 0) {

      printf("\nNão use números negativos\n\n");

        continue;

    }

    if (acertou) {

      printf("\nParabéns, você acertou\n\n");

      break;

    } else if (maior) {

      printf("\nO número secreto é maior\n\n");

    } else if (menor) {

      printf("\nO número secreto é menor\n\n");

    }

    tentativas++;

    pontos -= pontosPerdidos;
  }

  return 0;
  }