#include "Trie.h"
#include <iostream>

/**
 * print the trie in dfs fashion
 */
void Trie::_print(TrieNode * root) {
	const std::map<char, TrieNode*> children = root->getChildren();

	for (auto it = children.begin(); it != children.end(); it++) {
		std::cout << it->first << " ";
		if(it->second->isEndOfWord())
		    std::cout<<"\n";
		this->_print(it->second);
	}
}

Trie::Trie() {
	this->root = new TrieNode(false);
}

void Trie::insert(std::string entry) {

	TrieNode *runner, *nextHop;
	int len;

	len = entry.size() - 1;
	runner = this->root;
	for (int i = 0; i < entry.size(); i++) {
        nextHop = runner->getChild(entry[i]);
        // if the symbol is present, just continue traversing
        if (nextHop) {
			// if the last letter is not a leaf, just mark it as an end-of-word
			/*if (i == len && !nextHop->isEndOfWord())
				nextHop->setEndOfWord(true);*/
			runner = nextHop;
		} else {	// create a new path in the tree
			runner = runner->addChild(entry[i], false);
		}
	}

    // mark the last letter as an end-of-word node
    runner->setEndOfWord(true);
}

void Trie::insert(char entry[]) {

	this->insert(std::string(entry));
}

void Trie::print() {
	this->_print(this->root);
}


Trie::~Trie() {

}

void Trie::remove(std::string entry) {

}

bool Trie::search(std::string needle) {

    int i, len;
    bool stop;
    TrieNode *runner, *nextHop = nullptr;

    len = needle.length();
    runner = this->root;
    stop = false;

    for(i = 0; i < needle.size() && !stop; i++) {
        nextHop = runner->getChild(needle[i]);
        if(nextHop) {
            runner = nextHop;
        } else
            return false;
    }

    // handle the last letter
    if(nextHop == nullptr || !nextHop->isEndOfWord())
        return false;
    return true;
}
