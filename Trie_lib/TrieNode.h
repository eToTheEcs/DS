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
    TrieNode(const TrieNode& toCopy);
	~TrieNode();
	
	//char getValue();
	bool isEndOfWord() const;
	void setEndOfWord(bool eow);
	int numChildren();
	TrieNode* getChild(char symbol);
	TrieNode* addChild(char symbol, bool isEOW);
	void removeChild(char symbol);
	const std::map<char, TrieNode*>& getChildren() const;

	friend std::ostream& operator<<(std::ostream& out, const TrieNode& node);
};

