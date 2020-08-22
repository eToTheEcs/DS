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

	/**
	 * performs the search algorithm.
	 * @param needle key to search for.
	 * @param prefixMode if it's true, the algorithm will look for presence of complete keys
	 *                   if it's false, the algorithm will perform a prefix search, hence returning true
	 *                   also in the case a prefix is present, without the full key.
	 * @return node of the last match.
	 */
	TrieNode* _search(std::string needle, bool prefixMode);

	/**
	 * extracts the full list of automopletions.
	 * @param needle searched keyword
	 * @param node pointer to the last letter of the keyword
	 * @return ordered list of autocompletions
	 */
	std::set<std::string> extractPrefixes(std::string needle, const TrieNode *node) const;

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
	 * @return set of keys that have the same prefix, empty sey if no matches found.
	 */
	std::set<std::string> prefixSearch(std::string prefix);

	/**
	 * standard operator overloading
	 * @param os stream object
	 * @param trie trie object to print out
	 * @return the stream object (to allow chaining of << operators)
	 */
    friend std::ostream& operator<<(std::ostream &os, const Trie &trie);
};

