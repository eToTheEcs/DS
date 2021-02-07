#pragma once

#include <string>
#include <map>

class TrieNode {

private:
    bool endOfWord;
	std::map<char, TrieNode*> children;

public:
    TrieNode();
    TrieNode(bool eow);
    TrieNode(const TrieNode& toCopy);

    ~TrieNode();

    bool isEndOfWord() const;
    void setEndOfWord(bool eow);

    int numChildren();
    TrieNode* getChild(char symbol);
    TrieNode* addChild(char symbol, bool isEOW);
    void removeChild(char symbol);
    const std::map<char, TrieNode*>& getChildren() const;
    void setChildren(const std::map<char, TrieNode*> childrenList);

	friend std::ostream& operator<<(std::ostream& out, const TrieNode& node);
};

