# Fila de Atendimento com Prioridades

Este repositório contém a implementação de um sistema de fila de atendimento com prioridades em **C**, desenvolvido durante os estudos sobre **Estruturas de Dados** em meu segundo período de ADS. O exercício foi proposto pelo professor para simular o funcionamento de uma fila de atendimento em cenários reais, como hospitais ou bancos, priorizando grupos específicos.

## ✨ Funcionalidades

O sistema implementa as seguintes funcionalidades principais:

1. **Adicionar pessoa à fila**: Insere uma pessoa na fila com base em sua prioridade.
2. **Remover pessoa da fila**: Remove a pessoa com maior prioridade (mais urgente) da fila.
3. **Mostrar a fila atual**: Exibe a lista de pessoas na fila e suas respectivas prioridades.
4. **Verificar fila vazia**: Confirma se não há ninguém na fila.
5. **Verificar fila cheia**: Indica se a fila atingiu a capacidade máxima.

## 🛠️ Regras de Prioridade

As prioridades são definidas como segue:

| **Prioridade** | **Descrição**                                    |
| -------------- | ------------------------------------------------ |
| **1**          | Idosos e Pessoas com deficiência                 |
| **2**          | Gestantes com gestão de risco                    |
| **3**          | Pessoas com crianças de colo (até 1 ano de vida) |
| **4**          | Gestantes com mais de 6 meses de gravidez        |
| **5**          | Gestantes com até 6 meses de gravidez            |
| **6**          | Demais pessoas amparadas pela lei                |
| **7**          | Atendimento normal                               |

## 📂 Estrutura do Código

### Estrutura de Dados

A estrutura da fila foi definida utilizando uma struct em C, que inclui:

```c
typedef struct {
  int head, tail;         // Posições da cabeça e final da fila
  int priority[N];        // Prioridades dos clientes
  char name[N][40];       // Nomes dos clientes
} queue;
```

### Funções Implementadas

- **newQueue**: Inicializa uma nova fila.
- **enqueue**: Adiciona uma pessoa à fila, posicionando-a corretamente de acordo com sua prioridade.
- **dequeue**: Remove a pessoa com maior prioridade da fila.
- **isQueueEmpty**: Verifica se a fila está vazia.
- **isQueueFull**: Verifica se a fila está cheia.
- **showQueue**: Exibe todas as pessoas na fila e suas respectivas prioridades.

## 🚀 Execução do Programa

Para rodar o programa:

1. Salve o código em um arquivo chamado, por exemplo, `fila_atendimento.c`.
2. Compile o código usando GCC:
   ```bash
   gcc fila_atendimento.c -o fila_atendimento
   ```
3. Execute o programa:
   ```bash
   ./fila_atendimento
   ```

Durante a execução, o programa exibirá as operações da fila, como adicionar e remover clientes, com mensagens detalhadas.

## 🖊️ Exemplo de Saída

```text
====Prioridades====
Prioridade 1: Idosos e Pessoas com deficiencia -> [1]
Prioridade 2: Gestantes com gestao de risco -> [2]
Prioridade 3: Pessoas com criancas de colo de ate 1 ano de vida -> [3]
Prioridade 4: Gestantes com mais de 6 meses de gravidez -> [4]
Prioridade 5: Gestantes com ate 6 meses de gravidez -> [5]
Prioridade 6: Demais pessoas amparadas pela lei -> [6]
Prioridade 7: Atendimento normal -> [7]

====Adicionando Clientes a fila e mostrando sua organizacao====
Clientes na fila de Atendimento de acordo com sua prioridade:
Prioridade do cliente:[2], Nome do cliente:[Maria Clara].

Clientes na fila de Atendimento de acordo com sua prioridade:
Prioridade do cliente:[2], Nome do cliente:[Maria Clara].
Prioridade do cliente:[6], Nome do cliente:[Pedro Caravlho].

...

====Tirando Clientes da fila e mostrando sua organizacao====
Cliente que saiu da fila: Prioridade:[1], Nome:[Seu jao]
Clientes na fila de Atendimento de acordo com sua prioridade:
Prioridade do cliente:[2], Nome do cliente:[Maria Clara].

...
```

## 🙏 Considerações Finais

Este exercício foi uma ótima oportunidade para aprender e implementar o conceito de **filas com prioridade** em C, consolidando os seguintes conceitos:

- Estruturas de dados básicas (fila);
- Manipulação de arrays e ponteiros;
- Algoritmos de ordenação dentro de filas.

Sinta-se à vontade para explorar e adaptar o código para outros cenários ou melhorar a implementação. 🚀

