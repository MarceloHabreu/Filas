#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Implementar utilizando filas em C, uma aplicaçao que simule uma fila de atendimento com prioridades, considerando a existência de diferentes níveis de prioridade:
// * Prioridade 1º: Idosos e Pessoas com deficiência -> [1]
// * Prioridade 2º: Gestantes com gestão de risco -> [2]
// * Prioridade 3º: Pesoas com crianças de colo de até 1 ano de vida -> [3]
// * Prioridade 4º: Gestantes com mais de 6 meses de gravidez -> [4]
// * Prioridade 5º: Gestantes com até 6 meses de gravidez -> [5]
// * Prioridade 6º: Demais pessoas amparados pela lei -> [6]
// * Prioridade 7º: Atendimento normal -> [7]

// Definindo constante (valor máximo)
#define N 5

// Definindo estrutura
typedef struct {
  int head, tail; // cabeça e final da fila
  int priority[N];  // tipo de prioridade da pessoa de tamanho máximo N clientes
  char name[N][40];  // nome da pessoa com no máximo N nomes de clientes
} queue;

// Métodos a serem implementados
queue *newQueue();  // Inicializando a Fila
void enqueue(queue *q, int priority, char name[]); // Adicionando uma pessoa a fila
int dequeue(queue *q); // Removendo uma pessoa da fila
int isQueueEmpty(queue *q);  // Verificando se a fila está vazia
int isQueueFull(queue *q);  // verificando se a fila está cheia
int showQueue(queue *q);  // Mostrando cada pessoa da fila e sua respectiva prioridade para verificação


// Implementando métodos
queue *newQueue() {
  queue *q = (queue *)malloc(sizeof(queue));
  q->head = 0;
  q->tail = 0;
  return q;
}

// Verifica fila vazia
int isQueueEmpty(queue *q) {
  if (q->head == q->tail) {
    return 1;
  } 
  return 0;
}

// Verifica fila cheia
int isQueueFull(queue *q) {
  if (q->tail == N) {
    return 1;
  }
  return 0;
}


// Exibe fila
int showQueue(queue *q) {

  if(isQueueEmpty(q))  {
    printf("Fila Vazia, Sem Clientes!!");
  } else {
    printf("Clientes na fila de Atendimento de acordo com sua prioridade:\n");
    for (int i = q->head; i < q->tail; i++) {
      printf("Prioridade do cliente:[%d], Nome do cliente:[%s]. \n", q->priority[i], q->name[i]);
    }
  }
}

// Adiciona a fila
void enqueue(queue *q, int priority, char name[]) {
   if (isQueueFull(q)) {
    printf("A fila esta cheia! Sem possibilidade de adicionar mais clientes.\n");
    return;
  }

  int i = q->tail - 1; // Começando do último elemento inserido na fila

   // Encontra a posição para inserir a nova pessoa com base na prioridade
   while (i>=q->head && q->priority[i] > priority) {
    q->priority[i+1] = q->priority[i];
    strcpy(q->name[i+1], q->name[i]);
    i--;
   }
   
   q->priority[i+1] = priority;
   strcpy(q->name[i+1], name);
   q->tail++;
}

// Remove da fila
int dequeue(queue *q) {
  if(isQueueEmpty(q)) {
    printf("Fila vazia!! Nao ha ninguem para remover.\n");
    return -1;
  }

  int removedPriority = q->priority[q->head]; // Guardando a prioridade do cliente a ser removido
  printf("Cliente que saiu da fila: Prioridade:[%d], Nome:[%s]\n", q->priority[q->head], q->name[q->head]);

  q->head++; // Incrementa o head para avançar para o próximo cliente

  return removedPriority;
}


// Testes
int main () {
  queue *fila = newQueue();
  printf("====Prioridades====\n");
  printf("Prioridade 1: Idosos e Pessoas com deficiencia -> [1]\n");
  printf("Prioridade 2: Gestantes com gestao de risco -> [2]\n");
  printf("Prioridade 3: Pessoas com criancas de colo de ate 1 ano de vida -> [3]\n");
  printf("Prioridade 4: Gestantes com mais de 6 meses de gravidez -> [4]\n");
  printf("Prioridade 5: Gestantes com ate 6 meses de gravidez -> [5]\n");
  printf("Prioridade 6: Demais pessoas amparadas pela lei -> [6]\n");
  printf("Prioridade 7: Atendimento normal -> [7]\n");

  printf("\n");

  printf("====Adicionando Clientes a fila e mostrando sua organizacao====\n");
  enqueue(fila, 2, "Maria Clara");
  showQueue(fila);
  enqueue(fila,6, "Pedro Caravlho");
  enqueue(fila, 5, "Ana Julia");
  showQueue(fila);
  enqueue(fila, 7, "Francisco Junior");
  showQueue(fila);
  enqueue(fila, 1, "Seu jao");
  enqueue(fila, 1, "Marco Andre");  
  showQueue(fila);  // Fila cheia

  printf("\n");

  printf("====Tirando Clientes da fila e mostrando sua organizacao====\n");
  dequeue(fila);  // Saindo Seu jao
  showQueue(fila);  
  dequeue(fila);  // Saindo Maria
  showQueue(fila);
  dequeue(fila);   // Saindo Ana 
  showQueue(fila);  
  dequeue(fila);   // Saindo Pedro
  showQueue(fila);
  dequeue(fila);    // Saindo Francisco
  showQueue(fila);
  dequeue(fila);   // Fila Vazia
}