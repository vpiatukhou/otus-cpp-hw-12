#include "MapReduceService.h"
#include "Mapper.h"
#include "Reducer.h"
#include "Splitter.h"

#include <memory>
#include <utility>

namespace Homework {

    MapReduceService::MapReduceService(Shuffler shuffler_, std::string inputFile_, MapFunction mapFunction_,
        NumberOfPartitions numberOfMappers_, ReduceFunction reduceFunction_)
        : shuffler(shuffler_),
          inputFile(inputFile_),
          mapFunction(mapFunction_),
          numberOfMappers(numberOfMappers_),
          reduceFunction(reduceFunction_) {
    }

    void MapReduceService::start() {
        //split the given file on sections
        auto partitionEnds = splitInputData(inputFile, numberOfMappers);

        //create and start mappers
        std::vector<std::unique_ptr<Mapper>> mappers;
        mappers.reserve(partitionEnds.size());

        FilePosition previousPartitionEnd = 0;
        for (auto partitionEnd : partitionEnds) {
            mappers.push_back(std::make_unique<Mapper>(inputFile, previousPartitionEnd, partitionEnd, mapFunction));
            previousPartitionEnd = partitionEnd;
        }

        //wait until the mappers do their work
        for (auto& mapper : mappers) {
            mapper->join();
        }

        //shuffle
        std::vector<MappedData> shuffleInput;
        for (auto& mapper : mappers) {
            MappedData output;
            mapper->extractOutput(output);
            shuffleInput.push_back(std::move(output));
        }

        std::vector<MappedData> shuffleOutput;
        shuffler.shuffle(shuffleInput, shuffleOutput);

        //create and start reducers
        std::vector<std::unique_ptr<Reducer>> reducers;
        reducers.reserve(shuffleOutput.size());
        std::size_t reducerNumber = 1;
        for (auto& reducerInput : shuffleOutput) {
            reducers.push_back(std::make_unique<Reducer>(std::to_string(reducerNumber), reducerInput, reduceFunction));
            ++reducerNumber;
        }

        //wait for the result
        for (auto& reducer : reducers) {
            reducer->join();
        }
    }
}