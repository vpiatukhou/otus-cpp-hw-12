#pragma once

#include "Types.h"

#include <fstream>
#include <string>

namespace Homework {

    /**
     * Reads the given text file line by line.
     */
    class FileReader {
    public:
        /**
         * A constructor.
         *
         * @param inputFile_     - an absolute path to the file
         * @param startPosition_ - reading starts from this position (inclusive)
         * @param endPosition_   - reading stops until this position (exclusive)
         */
        FileReader(const std::string& inputFile_, FilePosition startPosition_, FilePosition endPosition_);

        /**
         * Reads a line from the file.
         *
         * @param line - the read string
         */
        void readLine(std::string& line);

        /**
         * @result TRUE if there are more lines for reading. FALSE if the end of the file has been reached
         */
        bool hasNext();

        //used by unit tests
        FilePosition getEndPosition() const;
    private:
        std::ifstream file;
        FilePosition endPosition;
    };
}
