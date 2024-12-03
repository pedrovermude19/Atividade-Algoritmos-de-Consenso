#include "network.h"
#include "log.h"
#include <stdio.h>

void broadcast_message(Node nodes[], int count, const char *message) {
    for (int i = 0; i < count; i++) {
        if (nodes[i].active) {
            log_event("Node %d receives message: %s", nodes[i].id, message);
        }
    }
}