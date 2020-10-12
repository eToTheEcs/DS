#include "Trie.h"
#include <iostream>
#include <stack>

Trie::Trie() : nkeys(0) {
	this->root = new TrieNode(false);
}

Trie::~Trie() {

}

void Trie::_print(std::ostream &out, TrieNode *root) const {
    const std::map<char, TrieNode*> children = root->getChildren();

    for (auto it = children.begin(); it != children.end(); it++) {
        std::cout << it->first << " ";
        if(it->second->isEndOfWord())
            std::cout<<"\n";
        this->_print(out, it->second);
    }
}

bool Trie::insert(std::string entry) {
	TrieNode *runner, *nextHop;
	int len;

	len = entry.size() - 1;
	runner = this->root;
	for (int i = 0; i < entry.size(); i++) {
        nextHop = runner->getChild(entry[i]);
        // if the symbol is present, just continue traversing
        if (nextHop) {
			runner = nextHop;
		} else {	// create a new path in the tree
			runner = runner->addChild(entry[i], false);
		}
	}

    // mark the last letter as an end-of-word node (if wasn't previously set)
    if(!runner->isEndOfWord()) {
        runner->setEndOfWord(true);

        // update number-of-keys indicator
        this->nkeys++;

        return true;
    }

    // duplicate insertion
    return false;
}

bool Trie::insert(char entry[]) {
	return this->insert(std::string(entry));
}

void Trie::remove(std::string entry) {

}

bool Trie::search(std::string needle) {
    return this->_search(needle, false) != nullptr;
}

std::set<std::string> Trie::prefixSearch(std::string prefix) {
    TrieNode *endOfPrefixNode = this->_search(prefix, true);
    std::set<std::string> keySet;

    if(endOfPrefixNode != nullptr) {
        /*
         * prefix is an existing key
         * (still requires prefix extraction because there may be another key which has this one as a prefix)
         */
        if(endOfPrefixNode->isEndOfWord())
            keySet.insert(prefix);

        keySet = this->extractPrefixes(prefix, endOfPrefixNode);
    }

    return keySet;
}

TrieNode *Trie::_search(std::string needle, bool prefixMode) {
    int i, len;
    bool stop;
    TrieNode *runner, *nextHop = nullptr;

    len = needle.length();
    runner = this->root;
    //stop = false;

    for(i = 0; i < len; i++) {
        nextHop = runner->getChild(needle[i]);
        if(nextHop) {
            runner = nextHop;
        } else
            return nullptr;
    }

    // handle the last letter
    if(!prefixMode && (nextHop == nullptr || !nextHop->isEndOfWord()))
        return nullptr;

    return nextHop;
}

std::set<std::string> Trie::extractPrefixes(std::string needle, const TrieNode *node) const {
    std::set<std::string> res;
    std::map<char, TrieNode*> children = node->getChildren();

    for(auto it = children.begin(); it != children.end(); it++) {
        std::string fullEntry = needle; // deep copy
        TrieNode* root = const_cast<TrieNode *>(node);
        std::pair<TrieNode*, std::string>state;

        // perform a dfs in the portion of trie
        std::stack<std::pair<TrieNode*, std::string>> sck;
        sck.push({root, needle});
        while(!sck.empty()) {
            state = sck.top();
            sck.pop();

            // insert full key into result list
            if(state.first->isEndOfWord())
                res.insert(state.second);

            std::map<char, TrieNode*> children = state.first->getChildren();
            for (auto it = children.begin(); it != children.end(); it++)
                sck.push({it->second, state.second + it->first});
        }
    }

    return res;
}


std::ostream &operator<<(std::ostream &os, const Trie &trie) {
    trie._print(os, trie.root);
    return os;
}

int Trie::size() {
    return this->nkeys;
}
