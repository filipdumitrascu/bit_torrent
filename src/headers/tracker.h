#pragma once

#include "utils.h"

#include <unistd.h>
#include <unordered_map>

void tracker(int numtasks, int rank);

void shutdown(int numtasks);

void confirmation(int numtasks);

void update_request(
    int numtasks,
    std::unordered_map<std::string, trackedfile>& database,
    std::unordered_map<std::string, int>& leechersFiles);

void update_databe(
    std::unordered_map<std::string, trackedfile>& database,
    std::unordered_map<std::string, int>& leechersFiles);

void recv_data_from(int numtasks, int& leechersNo, int& filesNo);

void send_data_to(const trackedfile& swarm, int rank);
