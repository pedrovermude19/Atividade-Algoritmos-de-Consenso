#ifndef RAFT_H
#define RAFT_H

#include <stdbool.h>

#define MAX_NODES 5
#define TIMEOUT 5

typedef enum {
    FOLLOWER,
    CANDIDATE,
    LEADER
} NodeState;

typedef struct {
    int id;
    NodeState state;
    int term;
    int voted_for;
    bool active; // Simula falha ou recuperação do nó
} Node;

void initialize_nodes(Node nodes[], int count);
void simulate_election(Node nodes[], int count);
void simulate_heartbeat(Node nodes[], int count);
void handle_failure(Node nodes[], int count, int failed_node_id);
void recover_node(Node nodes[], int node_id);

#endif