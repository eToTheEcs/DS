#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <set>

#include "TrieNode.h"

class Trie {

private:

	TrieNode* root;

	/**
	 * Number of keys
	 */
	int nkeys;

	/**
	 * Performs a recursive print of the keys in the trie.
	 * @param out stream object (to allow chaining while printing).
	 * @param root root of the trie.
	 */
	void _print(std::ostream &out, TrieNode* root) const;

	/**
	 * Performs the search algorithm.
	 * @param needle key to search for.
	 * @param prefixMode if it's true, the algorithm will look for presence of full words <br>
	 *                   if it's false, the algorithm will perform a prefix search, hence returning true
	 *                   in the case a prefix is present, even if it's not a full word.
	 * @return node of the last match.
	 */
	TrieNode* _search(const std::string& needle, bool prefixMode);

	bool _delete(const std::string& key, int needleIndex, TrieNode* root);

	/**
	 * Extracts the full list of autocompletions.
	 * @param needle searched keyword
	 * @param node pointer to the last letter of the keyword
	 * @return ordered list of autocompletions
	 */
	std::set<std::string> extractPrefixes(const std::string& needle, const TrieNode* node) const;

public:
	Trie();

	~Trie();

	/**
	 * Inserts a new key in the trie
	 * @param key new key to insert
	 */
	bool insert(const std::string& key);

	/**
	 * Inserts a new key in the trie
	 * @param key new key to insert (C-style string)
	 */
	bool insert(char key[]);

	/**
	 * Deletes a key from the trie, if it's present,
	 * while does nothing if the key is absent.
	 * @param key key to remove
	 */
	void remove(std::string key);

	/**
	 * Searches for a string in the trie
	 * @param needle key to search for
	 * @return true if the key is in the trie, false otherwise
	 */
	bool search(const std::string& needle);

	/**
	 * Returns the number of keys in the trie.
	 * @return number of keys
	 */
	int size() const;

	/**
	 * Searches for all the keys having a certain prefix
	 * @param prefix the prefix to search for
	 * @return set of keys that have the same prefix, empty sey if no matches found.
	 */
	std::set<std::string> prefixSearch(const std::string& prefix);

	/**
	 * Standard operator overloading
	 * @param os stream object
	 * @param trie trie object to print out
	 * @return the stream object (to allow chaining of << operators)
	 */
    friend std::ostream& operator<<(std::ostream& os, const Trie& trie);
};

