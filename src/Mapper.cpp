#include "Mapper.h"

namespace Homework {

    Mapper::Mapper(const std::string& inputFile_, std::size_t startPosition_, std::size_t endPosition_, MapFunction map_)
        : fileReader(inputFile_, startPosition_, endPosition_), map(map_) {

        mapThread = std::make_unique<std::thread>([this]() { run(); });
    }

    void Mapper::join() {
        mapThread->join();
    }

    void Mapper::run() {
        std::string line;
        while (fileReader.hasNext()) {
            fileReader.readLine(line);
            map(line, output);
        }
    }

    void Mapper::extractOutput(MappedData& output) {
        output = std::move(this->output);
    }
}
