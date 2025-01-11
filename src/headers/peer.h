#pragma once

#include "utils.h"

#include <unordered_map>

void peer(int numtasks, int rank);

void read_client_files(std::unordered_map<std::string, hashes>& files,
    std::vector<std::string>& fileNames, int& filesNo, int rank);

void send_file(const std::unordered_map<std::string, hashes>& files, int rank);
