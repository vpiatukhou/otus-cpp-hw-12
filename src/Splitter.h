#pragma once

#include "Types.h"
#include "FileReader.h"

#include <vector>
#include <string>
#include <memory>

namespace Homework {

    class Splitter {
    public:
        Splitter(const std::string& inputFilepath_, NumberOfPartitions numberOfPartitions_);

        std::vector<std::unique_ptr<FileReader>> splitInputData();

    private:
        std::string inputFilepath;
        NumberOfPartitions numberOfPartitions;
    };

}
