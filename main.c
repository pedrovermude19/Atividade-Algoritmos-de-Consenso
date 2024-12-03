#include "raft.h"
#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    Node nodes[MAX_NODES];
    initialize_nodes(nodes, MAX_NODES);

    for (int i = 0; i < 10; i++) {
        printf("\n-- Simulation Step %d --\n", i + 1);

        if (rand() % 4 == 0) { // 25% chance of node failure
            handle_failure(nodes, MAX_NODES, rand() % MAX_NODES);
        }

        if (rand() % 4 == 0) { // 25% chance of node recovery
            recover_node(nodes, rand() % MAX_NODES);
        }

        simulate_election(nodes, MAX_NODES);
        simulate_heartbeat(nodes, MAX_NODES);
    }

    return 0;
}