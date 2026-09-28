#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 10

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  int topo;
  REGISTRO A[MAX];
} PILHA;

/* Inicialização da PILHA (a PILHA já está criada e é apontada 
pelo endereco em p) */
	void inicializarPilha(PILHA* p){
	  p->topo = -1;
	} /* inicializarPILHA* /

/* inserirElementoPilha - insere elemento no fim da pilha   */
bool inserirElementoPilha(PILHA* p, REGISTRO reg){
     if (p->topo+1>= MAX) return false;
     p->topo = p->topo+1;
     p->A[p->topo] = reg;
     return true;
} /* inserirElementoPilha* /

/* excluirElementoPilha - retorna e exclui 1o elemento da pilha 
retorna false se nao houver elemento a ser retirado */
bool excluirElementoPilha(PILHA* p, REGISTRO* reg){
   if (p->topo == -1) return false;
   *reg = p->A[p->topo];
   p->topo = p->topo-1;
   return true;
} /* excluirElementoPilha* */

// exibir a palavra formada pelas letras na pilha
void exibirPalavra(PILHA* p){
  int i;
  printf("Palavra: \" ");
  for (i=0; i<=p->topo; i++){
    printf("%c", p->A[i].chave); 
  }
  printf("\"\n");
} 

int main() {
    PILHA palavra; 
    inicializarPilha(&palavra); // Prepara a pilha para uso

    char input = ' '; // Variável para ler o teclado
    REGISTRO regTemp; // Variável auxiliar para a exclusão
    REGISTRO reg;     // Variável auxiliar para a inserção

while (input != 'q') {
        system("cls"); // Limpa a tela
        
        exibirPalavra(&palavra);
        printf("Digite uma letra da palavra ou digite 0 para excluir a ultima letra (ou 'q' para sair):\n");
        
        scanf(" %c", &input); 

        if (input == '0') {
            if (excluirElementoPilha(&palavra, &regTemp)) {
                // Se excluiu com sucesso, não precisamos imprimir nada aqui.
                // A tela será limpa no próximo ciclo e a palavra aparecerá atualizada!
            } else {
                printf("Nenhuma letra digitada ainda!\n");
                system("pause"); // Pausa para o usuário ler a mensagem
            }
        } 
        else if (input != 'q') {
            reg.chave = input;
            if (!inserirElementoPilha(&palavra, reg)) {
                printf("A palavra deve conter no maximo 10 caracteres!\n");
                system("pause"); // Pausa para o usuário ler a mensagem
            }
        }
    }   
}