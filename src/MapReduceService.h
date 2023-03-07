#pragma once

#include "Shuffler.h"
#include "Types.h"

#include <string>

namespace Homework {

    class MapReduceService {
    public:
        MapReduceService(Shuffler shuffler_,
                         std::string inputFile_,
                         MapFunction mapFunction_,
                         NumberOfPartitions numberOfMappers_,
                         ReduceFunction reduceFunction_);

        /**
         * Start MapReduce tasks.
         *
         * The result will be written into files the current working directory.
         *
         * The names of the files follow the pattern: "out-<a number of partition>.txt".
         */
        void start();
    private:
        Shuffler shuffler;

        std::string inputFile;
        MapFunction mapFunction;
        NumberOfPartitions numberOfMappers;
        ReduceFunction reduceFunction;
    };
}
