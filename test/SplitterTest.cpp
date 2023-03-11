#include "Splitter.h"
#include "Resources.h"

#include "gtest/gtest.h"

#include <vector>
#include <string>

using namespace Homework;
using namespace std::string_literals;

const std::string ROOT_DIR = BINARY_DIR + "/test-data/splitter-test/"s;

TEST(splitterTest, singleChar) {
    //given
    Splitter splitter(ROOT_DIR + "single-char.txt", 1);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(1, result[0]->getEndPosition());
}

TEST(splitterTest, moreMappersThanData) {
    //given
    Splitter splitter(ROOT_DIR + "single-char.txt", 2); //it is not possible to split data for two mappers

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(1, result[0]->getEndPosition());
}

TEST(splitterTest, allRecordsAreEqual) {
    //given
    Splitter splitter(ROOT_DIR + "all-records-are-equal.txt", 2);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(12, result[0]->getEndPosition()); //The first section is bigger. It is not a defect, please see Splitter::splitInputData()
    ASSERT_EQ(15, result[1]->getEndPosition());
}

TEST(splitterTest, firstSectionBigger) {
    //given
    Splitter splitter(ROOT_DIR + "first-section-bigger.txt", 2);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(6, result[0]->getEndPosition());
    ASSERT_EQ(8, result[1]->getEndPosition());
}

TEST(splitterTest, secondPartitionBigger) {
    //given
    Splitter splitter(ROOT_DIR + "second-parition-bigger.txt", 2);

    //when
    auto result = splitter.splitInputData(); //the number of mappers is 2 but it is impossible to split the data

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(8, result[0]->getEndPosition());
}

TEST(splitterTest, complexPartitions) {
    //given
    Splitter splitter(ROOT_DIR + "complex-partitions.txt", 3);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(28, result[0]->getEndPosition());
    ASSERT_EQ(56, result[1]->getEndPosition());
    ASSERT_EQ(72, result[2]->getEndPosition());
}
