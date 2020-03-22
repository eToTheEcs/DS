#pragma once

#include <string>

#include "TrieNode.h"

class Trie {
private:
	TrieNode* root;
	void _print(TrieNode* root);
public:
	Trie();
	~Trie();

	void insert(std::string entry);
	void insert(char entry[]);
	void remove(std::string entry);
	bool search(std::string needle);
	void print();
};

