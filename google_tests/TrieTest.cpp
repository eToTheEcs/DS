//
// Created by nbenatti on 11/08/20.
//

#include <Trie_lib/Trie.h>
#include "gtest/gtest.h"
#include "Trie_lib/TrieNode.h"

class TrieTest : public ::testing::Test {

protected:

	Trie t;
	static std::vector<std::string> testData;

	TrieTest() {}

	~TrieTest() override {

	}

	void SetUp() override {

	}

	void TearDown() override {

	}
};


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}