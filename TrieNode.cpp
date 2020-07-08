#include <iostream>
#include "TrieNode.h"

TrieNode::TrieNode() : endOfWord(false), children() {}

TrieNode::TrieNode(bool eow) : endOfWord(eow), children() {}

bool TrieNode::isEndOfWord() {

    return this->endOfWord;
}

void TrieNode::setEndOfWord(bool eow) {

    this->endOfWord = eow;
}

TrieNode* TrieNode::getChild(char symbol) {
	
	std::map<char, TrieNode*>::iterator it  = this->children.find(symbol);
	TrieNode* res;

	if (it != this->children.end()) {
		res = it->second;
	}
	else {
		res = nullptr;
	}

	return res;
}

TrieNode* TrieNode::addChild(char symbol, bool isEOW) {

	// only insert child if it's not present, otherwise don't do anything
	if (this->children.find(symbol) == this->children.end()) {
	    // get the newly-inserted node from directly from the return value
		TrieNode* res = this->children.insert({symbol, new TrieNode(isEOW)}).first->second;
		return res;
	} else
	    std::cout<< "child already present";

	return nullptr;
}

const std::map<char, TrieNode*>& TrieNode::getChildren() {
	
	return this->children;
}


TrieNode::~TrieNode() {
	
}

bool TrieNode::hasChildren() {
    return this->children.size();
}
