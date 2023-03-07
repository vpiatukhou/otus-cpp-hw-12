#include "Splitter.h"
#include "Types.h"

#include <cmath>
#include <filesystem>
#include <fstream>

namespace Homework {

    namespace {
        const char LINE_DELIMITER = '\n';
    }

    std::vector<FilePosition> splitInputData(const std::string& inputFilepath, NumberOfPartitions numberOfPartitions) {
        std::vector<FilePosition> result;
        result.reserve(numberOfPartitions);

        FilePosition fileSize = std::filesystem::file_size(inputFilepath);
        if (fileSize == 0) {
            return result;
        }

        if (numberOfPartitions == 1) {
            result.push_back(fileSize);
            return result;
        }

        //we substract 1 from the partition size because a position is counted from 0.
        auto partitionSizeAsDouble = std::ceil(static_cast<double>(fileSize) / numberOfPartitions - 1);
        FilePosition partitionSize = static_cast<FilePosition>(partitionSizeAsDouble);

        FilePosition sectionBegin = 0;

        std::ifstream file(inputFilepath);

        FilePosition partitionEnd = 0;
        while (partitionEnd < fileSize) {
            partitionEnd += partitionSize;
            if (partitionEnd > fileSize) {
                partitionEnd = fileSize;
            }

            //set the cursor to the estimated end of the section
            file.seekg(partitionEnd);

            auto remainedSize = fileSize - file.tellg();

            //move the cursor to the actual end of the section
            file.ignore(remainedSize, LINE_DELIMITER);

            partitionEnd = file.tellg();

            result.push_back(partitionEnd);
        }

        return result;
    }
}
