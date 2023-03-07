#include "FileReader.h"
#include "Resources.h"

#include "gtest/gtest.h"

#include <string>

using namespace Homework;
using namespace std::string_literals;

const std::string ROOT_DIR = BINARY_DIR + "/test-data/file-reader-test/"s;

TEST(fileReaderTest, readInMiddleOfFile) {
    //when
    FileReader reader(ROOT_DIR + "data.txt", 5, 16);

    //then
    std::string line;
    reader.readLine(line);
    ASSERT_EQ("BBB", line);
    ASSERT_TRUE(reader.hasNext());

    reader.readLine(line);
    ASSERT_EQ("CCCCCC", line);
    ASSERT_FALSE(reader.hasNext());
}

TEST(fileReaderTest, readUntilEndOfFile) {
    //when
    FileReader reader(ROOT_DIR + "data.txt", 5, 20);

    //then
    std::string line;
    reader.readLine(line);
    ASSERT_EQ("BBB", line);
    ASSERT_TRUE(reader.hasNext());

    reader.readLine(line);
    ASSERT_EQ("CCCCCC", line);
    ASSERT_TRUE(reader.hasNext());

    reader.readLine(line);
    ASSERT_EQ("DDDD", line);
    ASSERT_FALSE(reader.hasNext());
}
