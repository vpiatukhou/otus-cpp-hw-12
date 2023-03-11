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
    Splitter splitter(ROOT_DIR + "single-char.txt", 2);

    //when
    auto result = splitter.splitInputData(); //the number of mappers is 2 but there is not enough data

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(1, result[0]->getEndPosition());
}

TEST(splitterTest, twoEqualSections) {
    //given
    Splitter splitter(ROOT_DIR + "two-equal-sections.txt", 2);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(4, result[0]->getEndPosition());
    ASSERT_EQ(7, result[1]->getEndPosition());
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

TEST(splitterTest, secondSectionBigger) {
    //given
    Splitter splitter(ROOT_DIR + "second-section-bigger.txt", 2);

    //when
    auto result = splitter.splitInputData(); //the number of mappers is 2 but it is impossible to split the data

    //then
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(8, result[0]->getEndPosition());
}

TEST(splitterTest, twoSectionsComplex) {
    //given
    Splitter splitter(ROOT_DIR + "two-sections-complex.txt", 2);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(21, result[0]->getEndPosition());
    ASSERT_EQ(41, result[1]->getEndPosition());
}

TEST(splitterTest, threeSectionComplex) {
    //given
    Splitter splitter(ROOT_DIR + "three-sections-complex.txt", 3);

    //when
    auto result = splitter.splitInputData();

    //then
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(28, result[0]->getEndPosition());
    ASSERT_EQ(56, result[1]->getEndPosition());
    ASSERT_EQ(72, result[2]->getEndPosition());
}
