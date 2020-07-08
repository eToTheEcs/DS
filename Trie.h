#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <set>

#include "TrieNode.h"

class Trie {
private:
	TrieNode* root;

	void _print(std::ostream &out, TrieNode* root) const;
	TrieNode* _search(std::string needle);
public:
	Trie();
	~Trie();

	/**
	 * insert a new key in the trie
	 * @param entry new key to insert
	 */
	void insert(std::string entry);

	/**
	 * insert a new key in the trie
	 * @param entry new key to insert (C-style string)
	 */
	void insert(char entry[]);

	/**
	 * remove a key from the trie
	 * @param entry key to remove
	 */
	void remove(std::string entry);

	/**
	 * search for a string in the trie
	 * @param needle key to search for
	 * @return true if the key is in the trie, false otherwise
	 */
	bool search(std::string needle);

	/**
	 * search for all the keys having a certain prefix
	 * @param prefix the prefix to search for
	 * @return set of keys that have the same prefix
	 */
	std::set<std::string> prefixSearch(std::string prefix);

    friend std::ostream& operator<<(std::ostream &os, const Trie &trie);
};

