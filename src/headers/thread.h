#pragma once

#include "utils.h"

#include <unordered_map>

void shutdown_upload(void);

void segment_request_response(void);

void upload_thread(
    std::unordered_map<std::string, hashes> files, int rank);

void download_thread(int rank, int fileNo, void* fileNames);

trackedfile receive_file_swarm(int& segmentsNo, int rank);

void send_file_swarm(int fileNo, std::string* files, int rank);

void process_file_segments(
    std::string* files, int rank,
    int& segmentLast, int fIdx,
    trackedfile& swarm, int segmentsNo);

void finalize_file_save(
    std::string* files, int rank,
    int& segmentLast, int fIdx,
    trackedfile& swarm);
