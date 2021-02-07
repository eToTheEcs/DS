#include <iostream>
#include "TrieNode.h"

TrieNode::TrieNode() : endOfWord(false), children() {}

TrieNode::TrieNode(bool eow) : endOfWord(eow), children() {}

TrieNode::TrieNode(const TrieNode& toCopy) {
    this->endOfWord = toCopy.endOfWord;
    this->children = toCopy.children;
}

bool TrieNode::isEndOfWord() const {

    return this->endOfWord;
}

void TrieNode::setEndOfWord(bool eow) {

    this->endOfWord = eow;
}

TrieNode* TrieNode::getChild(char symbol) {

	auto it  = this->children.find(symbol);
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
	}

	return nullptr;
}


const std::map<char, TrieNode*>& TrieNode::getChildren() const {

	return this->children;
}

TrieNode::~TrieNode() {

}

int TrieNode::numChildren() {
    return this->children.size();
}

std::ostream& operator<<(std::ostream& out, const TrieNode& node) {

    out<< "EOW: " << node.endOfWord << std::endl;
    out<< "NODE HAS " << node.children.size() << " CHILDREN" << std::endl;
    out<< "{ ";

    auto it = node.children.begin();
    auto secondLast = std::prev(node.children.end(), 1);
    for(; it != secondLast; it++)
        out<< it->first << ", ";
    out<< it->first << " } "<< std::endl;

    return out;
}

void TrieNode::removeChild(char symbol) {
	this->children.erase(symbol);
}

void TrieNode::setChildren(const std::map<char, TrieNode*> childrenList) {
    this->children = childrenList;  // copy ctor gets called
}
