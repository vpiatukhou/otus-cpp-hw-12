#pragma once

#include "Types.h"

#include <cstdint>
#include <vector>
#include <string>

namespace Homework {

    /**
     * Split the given file into partitions.
     * 
     * @param inputFilepath - an absolute path to the input file
     * @result a list of positions in the file. An each position points to the end of the section (a next charachter after '\n')
     */
    std::vector<FilePosition> splitInputData(const std::string& inputFilepath, NumberOfPartitions numberOfSections);
}