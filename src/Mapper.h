#pragma once

#include "FileReader.h"
#include "Types.h"

#include <memory>
#include <thread>

namespace Homework {

    class Mapper {
    public:
        Mapper(const std::string& inputFile_, std::size_t startPosition_, std::size_t endPosition_, MapFunction map_);
        Mapper(const Mapper&) = delete;
        Mapper(Mapper&&) = delete;
        ~Mapper() = default;

        Mapper& operator=(const Mapper&) = delete;
        Mapper& operator=(Mapper&&) = delete;

        void join();
        void extractOutput(MappedData& output);

    private:
        MappedData output;

        FileReader fileReader;
        MapFunction map;

        std::unique_ptr<std::thread> mapThread;

        void run();
    };
}
