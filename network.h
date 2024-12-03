#ifndef NETWORK_H
#define NETWORK_H

#include "raft.h"

void broadcast_message(Node nodes[], int count, const char *message);

#endif