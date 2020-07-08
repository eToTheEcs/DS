#pragma once

#include <string>
#include <map>

class TrieNode {

private:
	//char value;
	bool endOfWord;
	std::map<char, TrieNode*> children;
public:
    TrieNode();
	TrieNode(bool eow);
	~TrieNode();
	
	//char getValue();
	bool isEndOfWord();
	void setEndOfWord(bool eow);
	bool hasChildren();
	TrieNode* getChild(char symbol);
	TrieNode* addChild(char symbol, bool isEOW);
	const std::map<char, TrieNode*>& getChildren();
};

