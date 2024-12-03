# Atividade-Algoritmos-de-Consenso
# Implementação do Algoritmo Raft em C

## Descrição

Este projeto é uma implementação simples e modular do algoritmo **Raft** em C. O Raft é um algoritmo de consenso distribuído usado para garantir que vários nós em um sistema distribuído concordem sobre o estado de uma máquina de estados. O algoritmo é popular por sua simplicidade e eficiência na construção de sistemas tolerantes a falhas, como em sistemas de gerenciamento de log e bancos de dados distribuídos.

Este projeto simula um ambiente distribuído onde múltiplos nós (representados por processos) tomam decisões baseadas no algoritmo Raft. O sistema inclui comunicação entre os nós, simulação de falhas e recuperação, e logs detalhados de cada fase do consenso.

## Estrutura do Projeto

A implementação é dividida em vários módulos para promover a modularidade e boas práticas de programação. A seguir, a descrição dos principais arquivos:

- **main.c**: Arquivo principal que inicializa os nós, executa a simulação e controla os passos do algoritmo Raft.
- **raft.h / raft.c**: Implementação do algoritmo Raft, incluindo a lógica de estados dos nós (FOLLOWER, CANDIDATE, LEADER), eleições, heartbeats e recuperação de falhas.
- **network.h / network.c**: Simula a troca de mensagens entre os nós para comunicação no ambiente distribuído.
- **log.h / log.c**: Implementação de logging para registrar as ações dos nós, incluindo a troca de mensagens, transições de estado e eventos de falha e recuperação.

## Compilação e Execução

### 1. Compilar o código

Você pode compilar o projeto utilizando o comando `gcc` (supondo que o GCC esteja instalado na sua máquina):

```bash
gcc -o raft main.c raft.c network.c log.c
```

### 2. Executar o programa

```bash
./raft
```

### 3. Saída esperada

O programa irá simular 10 etapas do algoritmo Raft, exibindo logs detalhados sobre as ações dos nós (inicialização, falhas, recuperação, eleições, heartbeats, etc.). Cada passo será registrado no console.

Funcionalidades:

- Inicialização dos Nós: Cada nó é inicializado como FOLLOWER com um termo inicial de 0.

- Os nós têm a capacidade de falhar ou se recuperar durante a simulação.

Eleições:

- Um nó é escolhido aleatoriamente para se tornar CANDIDATE e tentar se tornar LEADER.

- O nó candidato envia solicitações de votos e, se receber a maioria dos votos, se torna o LEADER.

- Caso o candidato não receba a maioria dos votos, ele permanece CANDIDATE e tenta novamente.

Heartbeats:

- O LEADER envia periodicamente heartbeats para os outros nós, sinalizando que está ativo e ainda liderando.

- Os FOLLOWERS escutam os heartbeats e voltam para o estado de FOLLOWER se não houver falhas.

Falhas e Recuperação:

- A simulação inclui falhas aleatórias de nós com 25% de chance a cada etapa.

- Nós falhos são marcados como inativos, e os nós podem ser recuperados a qualquer momento durante a simulação, voltando para o estado FOLLOWER.

Logs:

- Todos os eventos importantes (como transições de estado, eleições, falhas e recuperação) são registrados em logs para fins de depuração e rastreamento.

- Logs são gerados a cada etapa para capturar informações como "Node X becomes LEADER" ou "Node Y fails".

### Estrutura dos Arquivos

- raft.h: Define a estrutura do nó e as funções relacionadas ao algoritmo Raft, como inicialização, simulação de eleições, heartbeats, falhas e recuperação.

- raft.c: Implementa as funções definidas em raft.h, com a lógica de estados dos nós, transições de estado e processos de eleição.

- network.h: Define funções para simulação de comunicação entre os nós.

- network.c: Implementa a função broadcast_message para simular o envio de mensagens entre os nós.

- log.h: Define a função para registrar eventos de log.

- log.c: Implementa a função log_event para imprimir os eventos no console.

- main.c: Arquivo principal que inicializa os nós, simula falhas, recuperações e eleições, e executa a simulação do algoritmo Raft.

### Como Funciona

Inicialização:

- O programa começa inicializando todos os nós como FOLLOWERS.

Falhas e Recuperação:

- Durante cada etapa da simulação, há uma chance de 25% de um nó falhar ou se recuperar.

Eleições:

- Um nó aleatório é escolhido para ser candidato e tenta se tornar o líder.

- Se o nó receber mais votos que qualquer outro nó, ele se torna LEADER.

Heartbeats:

- O líder envia heartbeats para os nós seguidores.

Logs:

- Todos os eventos importantes são registrados em logs, para que você possa ver as ações de cada nó na simulação.
