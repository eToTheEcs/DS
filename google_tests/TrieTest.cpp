//
// Created by nbenatti on 11/08/20.
//

#include <../Trie_lib/Trie.h>
#include <fstream>
#include "gtest/gtest.h"

class TrieTestFixture : public ::testing::Test {

protected:
    const std::string SEARCH_TESTCASES_FILENAME = "searchTestcases.txt";
    const std::string PREFIX_SEARCH_TESTCASES_FILENAME = "prefixSearchTestcases.txt";

	Trie t0, t1, cloned;

	std::vector<std::string> testData;
	std::map<std::string, std::set<std::string>> expectedAutocompletionResults;
	std::vector<std::pair<std::string, bool>> keywords;

    TrieTestFixture() {}

	~TrieTestFixture() override {}

	void SetUp() override {
        // populate the trie
        testData = {"peter", "pedantic", "pedantico", "paddle", "pandemic", "pad", "ciao", "catena", "catenaria"};
        for(const std::string& el : testData)
            t1.insert(el);

        // clone the trie (the copy constructor gets called)
        cloned = t1;

        //TODO: add testcase file
        expectedAutocompletionResults["pa"] = std::set<std::string>({"paddle", "pandemic", "pad"});
        expectedAutocompletionResults["pad"] = std::set<std::string>({"paddle", "pad"});
        expectedAutocompletionResults["pe"] = std::set<std::string>({"pedantic", "pedantico", "peter"});
        expectedAutocompletionResults["ciao"] = std::set<std::string>({"ciao"});
        expectedAutocompletionResults["pedantic"] = std::set<std::string>({"pedantic", "pedantico"});
        expectedAutocompletionResults["catena"] = std::set<std::string>({"catena", "catenaria"});
        expectedAutocompletionResults["b"] = std::set<std::string>();
        expectedAutocompletionResults["c"] = std::set<std::string>({"catena", "catenaria", "ciao"});
        expectedAutocompletionResults[""] = std::set<std::string>();

        /*std::ifstream in("searchTestcases.txt");

        std::string runner;
        int esit;
        while(!in.eof()) {
            in>> runner >> esit;
            std::cout<< runner <<", "<< esit <<std::endl;
            //keywords.emplace_back(runner, esit);
        }

        in.close();*/

        keywords = {{"pad", true}, {"pa", false}, {"casaccio", false}, {"catenariao", false},
                    {"catena", true}, {"ebbene", false}};
    }
	void TearDown() override {

	}
};

TEST_F(TrieTestFixture, sizeCheck) {
    EXPECT_EQ(t0.size(), 0);
    EXPECT_EQ(t1.size(), 9);
}

TEST_F(TrieTestFixture, duplicateCheck) {
    for(const std::string& dupKey : testData)
        EXPECT_EQ(t1.insert(dupKey), false);
}

TEST_F(TrieTestFixture, autocompleteCheck) {
    for(auto el : expectedAutocompletionResults) {
        std::set<std::string> expected = el.second;
        std::set<std::string> actual = t1.prefixSearch(el.first);
        ASSERT_EQ(actual, expected);
    }
}

TEST_F(TrieTestFixture, searchCheck) {
    for(auto keyword : keywords) {
        EXPECT_EQ(t1.search(keyword.first), keyword.second);
    }
}


TEST_F(TrieTestFixture, clonedSizeCheck) {
    EXPECT_EQ(t1.size(), cloned.size());
}

TEST_F(TrieTestFixture, clonedAutocompleteCheck) {
    for(auto el : expectedAutocompletionResults) {
        std::set<std::string> originalOutput = t1.prefixSearch(el.first);
        std::set<std::string> clonedOutput = cloned.prefixSearch(el.first);
        ASSERT_EQ(originalOutput, clonedOutput);
    }
}

TEST_F(TrieTestFixture, removalCheck) {
    t1.remove("pa");
    ASSERT_EQ(t1.size(), 9);
    std::cout<< t1 <<std::endl;

    t1.remove("pad");
    ASSERT_EQ(t1.size(), 8);
    std::cout<< t1 <<std::endl;

    t1.remove("catenaria");
    ASSERT_EQ(t1.size(), 7);
    std::cout<< t1 <<std::endl;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
