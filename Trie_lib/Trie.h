#pragma once

#include <string>
#include <vector>
#include <ostream>
#include <set>

#include "TrieNode.h"

class Trie {

private:

	TrieNode* root;

	int numberOfKeys;

	/*
	 * Performs a recursive print of the keys in the trie.
	 */
	void _print(std::ostream &out, TrieNode* root) const;

	/*
	 * Performs the search algorithm.
	 * Returns the last-match-node if the key is present, null otherwise
	 */
    TrieNode *_search(const std::string &needle);

	/*
	 * Performs recursive deletion algorithm (if the key is present).
	 * Returns the root of the modified trie.
	 */
	TrieNode* _delete(const std::string& key, int keyIndex, TrieNode* root);

	/*
	 * Clones an existing trie into a new one, from it's roots
	 */
	void clone(TrieNode* root, const TrieNode* toClone);

	/*
	 * Extracts the full autocompletion list.
	 * Takes the key and the pointer to it's last letter in the trie
	 */
	std::set<std::string> extractPrefixes(const std::string& needle, const TrieNode* node) const;

public:
	Trie();

	Trie(const Trie& toCopy);

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
	 * @param key to search for
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
	 * @return set of keys that have the same prefix, empty sey if no matches are found.
	 */
	std::set<std::string> prefixSearch(const std::string& prefix);

    friend std::ostream& operator<<(std::ostream& os, const Trie& trie);
};

