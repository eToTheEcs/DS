//
// Created by nbenatti on 11/08/20.
//

#include <../Trie_lib/Trie.h>
#include "gtest/gtest.h"

class TrieTestFixture : public ::testing::Test {

protected:
	Trie t0, t1;
	std::vector<std::string> testData;
	//std::vector<std::string> testPrefixes;
	std::map<std::string, std::set<std::string>> expectedAutocompletionResults;

    TrieTestFixture() {}

	~TrieTestFixture() override {}

	void SetUp() override {
        // populate the trie
        testData = {"peter", "pedantic", "paddle", "pandemic", "pad"};
        for(std::string el : testData)
            t1.insert(el);

        //TODO: add testcase file
        expectedAutocompletionResults["pa"] = std::set<std::string>({"paddle", "pandemic", "pad"});
        expectedAutocompletionResults["pad"] = std::set<std::string>({"paddle", "pad"});
        expectedAutocompletionResults["pe"] = std::set<std::string>({"pedantic", "peter"});
        expectedAutocompletionResults["ciao"] = std::set<std::string>();
        expectedAutocompletionResults["paddle"] = std::set<std::string>({"paddle"});
        expectedAutocompletionResults["b"] = std::set<std::string>();
        expectedAutocompletionResults[""] = std::set<std::string>();
    }

	void TearDown() override {

	}
};

TEST_F(TrieTestFixture, sizeDoesWork) {
    EXPECT_EQ(t0.size(), 0);
    EXPECT_EQ(t1.size(), 5);
}

TEST_F(TrieTestFixture, duplicateCheck) {
    for(std::string dupKey : testData)
        EXPECT_EQ(t1.insert(dupKey), false);
}

TEST_F(TrieTestFixture, autocompleteCheck) {
    for(auto el : expectedAutocompletionResults) {
        auto expected = el.second;
        auto actual = t1.prefixSearch(el.first);
        EXPECT_EQ(actual, expected);
    }
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}