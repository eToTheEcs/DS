#include "Trie.h"
#include <iostream>
#include <stack>

Trie::Trie() : numberOfKeys(0) {
	this->root = new TrieNode(false);
}

void Trie::clone(TrieNode* root, const TrieNode* toClone) {
    if(toClone != nullptr) {
        root = new TrieNode(*toClone);

        auto children = root->getChildren();
        auto toCloneChildren = toClone->getChildren();

        for(auto it = children.begin(), jt = toCloneChildren.begin(); it != children.end(); ++it, ++jt) {
            this->clone(it->second, jt->second);
        }
    }
}

Trie::Trie(const Trie& toCopy) {
    this->clone(this->root, toCopy.root);
}

Trie::~Trie() {

}

void Trie::_print(std::ostream &out, TrieNode* root) const {
    const std::map<char, TrieNode*> children = root->getChildren();

    for (auto it : children) {
        std::cout << it.first << " ";
        if(it.second->isEndOfWord())
            std::cout<<"\n";
        this->_print(out, it.second);
    }
}

bool Trie::insert(const std::string& key) {
	TrieNode* runner;
	TrieNode* nextHop;

	runner = this->root;
	for (char i : key) {
        nextHop = runner->getChild(i);
        // if the symbol is present, just continue traversing
        if (nextHop) {
			runner = nextHop;
		} else {	// create a new path in the tree
			runner = runner->addChild(i, false);
		}
	}

    // mark the last letter as an end-of-word node (if wasn't previously set)
    if(!runner->isEndOfWord()) {
        runner->setEndOfWord(true);
        // update number-of-keys indicator
        this->numberOfKeys++;

        return true;
    }

    // duplicate insertion
    return false;
}

bool Trie::insert(char key[]) {
	return this->insert(std::string(key));
}

TrieNode* Trie::_delete(const std::string& key, int needleIndex, TrieNode* root) {
    TrieNode* esit;
    TrieNode* next;

    if(root == nullptr) {
        return nullptr;
    }

    if(needleIndex == key.size()) {
        if(root->isEndOfWord()) {
            this->numberOfKeys--;
            next = root->getChild(key[needleIndex - 1]);
            if (next != nullptr) {
                root->setEndOfWord(false);
                return root;
            } else { // the key is not a prefix of another key
                delete root;
                return nullptr;
            }
        }
    }

    esit = _delete(key, needleIndex + 1, root->getChild(key[needleIndex]));

    if(esit == nullptr) {
        // the child node has been deleted, remove it from the list of children
        root->removeChild(key[needleIndex]);
        if(needleIndex > 0 && !root->isEndOfWord() && root->numChildren() == 0) {
            delete root;
            return nullptr;
        } else
            return root;
    }

    return root;
}

void Trie::remove(std::string key) {
    this->_delete(key, 0, this->root);
}

bool Trie::search(const std::string& needle) {
    return this->_search(needle, false) != nullptr;
}

std::set<std::string> Trie::prefixSearch(const std::string& prefix) {
    TrieNode* endOfPrefix = this->_search(prefix, true);
    std::set<std::string> keySet;

    if(endOfPrefix != nullptr) {
        /*
         * prefix is an existing key
         * (still requires prefix extraction because there may be another key which has this one as a prefix)
         */
        if(endOfPrefix->isEndOfWord())
            keySet.insert(prefix);

        std::set<std::string> dummy = this->extractPrefixes(prefix, endOfPrefix);
        keySet.insert(dummy.begin(), dummy.end());
    }

    return keySet;
}

TrieNode* Trie::_search(const std::string& needle, bool prefixMode) {
    int i, len;
    TrieNode* runner;
    TrieNode* nextHop = nullptr;

    len = needle.length();
    runner = this->root;

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

std::set<std::string> Trie::extractPrefixes(const std::string& needle, const TrieNode* node) const {
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
            for (auto & it : children)
                sck.push({it.second, state.second + it.first});
        }
    }

    return res;
}

std::ostream& operator<<(std::ostream& os, const Trie& trie) {
    trie._print(os, trie.root);
    return os;
}

int Trie::size() const {
    return this->numberOfKeys;
}
