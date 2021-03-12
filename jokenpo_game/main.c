#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//As regras do jogo Pedra-Papel-Tesoura são:
//Pedra ganha da tesoura (amassando-a ou quebrando-a).
//Tesoura ganha do papel (cortando-o).
//Papel ganha da pedra (embrulhando-a).

int pontos_do_jogador=0, pontos_do_computador=0;

main() {

   jokenpo();

}

int jokenpo() {

   int jogador, computador;
   printf ("\n------ Jo Ken Po ------\n");
   printf ("\n %d Jogador X Computador %d \n", pontos_do_jogador, pontos_do_computador);
   printf ("          \n");
   printf ("0. Pedra\n");
   printf ("1. Papel\n");
   printf ("2. Tesoura\n");
   printf ("3. Sair\n");
   scanf ("%d", &jogador);

   if (jogador < 0 || jogador >=3) {
       exit(0);
   }

   srand(time(NULL));
   computador = rand() % 3; //aqui vamos gerar um numero aleatorio

   switch(computador) {
       case 0: printf ("\nComputador -> Pedra\n"); break;
       case 1: printf ("\nComputador -> Papel\n"); break;
       case 2: printf ("\nComputador -> Tesoura\n"); break;
   }

   if ((jogador == 0 && computador == 2) || (jogador == 1 && computador == 0) || (jogador == 2 && computador == 1)) {
           printf("\n *** Voce venceu! *** \n");
           pontos_do_jogador++;
           jokenpo();
       }

   if (jogador == computador) {
           printf ("\n *** Empate! *** \n");
           jokenpo();
       }

    else {
           printf ("\n *** Computador venceu! *** \n");
           pontos_do_computador++;
           jokenpo();
       }

    return 0;
}
