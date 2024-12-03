#include "raft.h"
#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_nodes(Node nodes[], int count) {
    for (int i = 0; i < count; i++) {
        nodes[i].id = i;
        nodes[i].state = FOLLOWER;
        nodes[i].term = 0;
        nodes[i].voted_for = -1;
        nodes[i].active = true;
        log_event("Node %d initialized as FOLLOWER", nodes[i].id);
    }
}

void simulate_election(Node nodes[], int count) {
    int candidate_id = rand() % count;
    while (!nodes[candidate_id].active) {
        candidate_id = rand() % count;
    }

    nodes[candidate_id].state = CANDIDATE;
    nodes[candidate_id].term++;
    nodes[candidate_id].voted_for = candidate_id;

    log_event("Node %d becomes CANDIDATE for term %d", candidate_id, nodes[candidate_id].term);

    int votes = 1; // Vote for itself
    for (int i = 0; i < count; i++) {
        if (i != candidate_id && nodes[i].active && rand() % 2 == 0) {
            votes++;
            log_event("Node %d votes for Node %d", nodes[i].id, candidate_id);
        }
    }

    if (votes > count / 2) {
        nodes[candidate_id].state = LEADER;
        log_event("Node %d becomes LEADER for term %d", candidate_id, nodes[candidate_id].term);
    } else {
        log_event("Node %d fails to win majority, remains CANDIDATE", candidate_id);
    }
}

void simulate_heartbeat(Node nodes[], int count) {
    for (int i = 0; i < count; i++) {
        if (nodes[i].state == LEADER && nodes[i].active) {
            log_event("Node %d sends heartbeat to all nodes", nodes[i].id);
        }
    }
}

void handle_failure(Node nodes[], int count, int failed_node_id) {
    if (failed_node_id >= 0 && failed_node_id < count) {
        nodes[failed_node_id].active = false;
        log_event("Node %d fails", failed_node_id);
    }
}

void recover_node(Node nodes[], int node_id) {
    if (node_id >= 0 && node_id < MAX_NODES) {
        nodes[node_id].active = true;
        nodes[node_id].state = FOLLOWER;
        log_event("Node %d recovers as FOLLOWER", node_id);
    }
}