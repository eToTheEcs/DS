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
            Trie::clone(it->second, jt->second);
        }
    }
}

Trie::Trie(const Trie& toCopy) : numberOfKeys(toCopy.numberOfKeys) {
    this->clone(this->root, toCopy.root);
}

Trie::~Trie() = default;

int Trie::size() const {
    return this->numberOfKeys;
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

Trie::TrieNode* Trie::_delete(const std::string& key, int keyIndex, TrieNode* root) {
    TrieNode* outcome;
    TrieNode* next;

    if(root == nullptr) {
        return nullptr;
    }

    if(keyIndex == key.size()) {
        if(root->isEndOfWord()) {
            this->numberOfKeys--;
            next = root->getChild(key[keyIndex - 1]);
            if (next != nullptr) {
                root->setEndOfWord(false);
                return root;
            } else { // the key is not a prefix of another key
                delete root;
                return nullptr;
            }
        }
    }

    outcome = _delete(key, keyIndex + 1, root->getChild(key[keyIndex]));

    if(outcome == nullptr) {
        // the child node has been deleted, remove it from the list of children
        root->removeChild(key[keyIndex]);
        if(keyIndex > 0 && !root->isEndOfWord() && root->numChildren() == 0) {
            delete root;
            return nullptr;
        } else
            return root;
    }

    return root;
}

bool Trie::remove(const std::string& key) {
    bool isKeyInTrie = this->search(key);
    if(isKeyInTrie)
        this->_delete(key, 0, this->root);

    return isKeyInTrie;
}

Trie::TrieNode* Trie::_search(const std::string& needle) {
    int i, len;
    TrieNode* runner;
    TrieNode* nextHop = nullptr;

    len = needle.length();
    runner = this->root;

    for(i = 0; i < len; i++) {
        nextHop = runner->getChild(needle[i]);
        if(nextHop)
            runner = nextHop;
        else
            return nullptr;
    }

    return nextHop;
}

std::set<std::string> Trie::extractPrefixes(const std::string& needle, const TrieNode* node) {
    std::set<std::string> res;
    std::map<char, TrieNode*> children = node->getChildren();

    for(auto it = children.begin(); it != children.end(); it++) {
        //std::string fullEntry = needle; // deep copy
        TrieNode* root = const_cast<TrieNode *>(node);
        std::pair<TrieNode*, std::string>state;

        // perform a DFS in the portion of trie
        std::stack<std::pair<TrieNode*, std::string>> stk;
        stk.push({root, needle});
        while(!stk.empty()) {
            state = stk.top();
            stk.pop();

            // insert full key into result list
            if(state.first->isEndOfWord())
                res.insert(state.second);

            std::map<char, TrieNode*> children = state.first->getChildren();
            for (auto& child : children)
                stk.push({child.second, state.second + child.first});
        }
    }

    return res;
}

bool Trie::search(const std::string& needle) {
    TrieNode* lastMatch = this->_search(needle);
    return lastMatch != nullptr && lastMatch->isEndOfWord();
}

std::set<std::string> Trie::prefixSearch(const std::string& prefix) {
    TrieNode* endOfPrefix = this->_search(prefix);
    std::set<std::string> keySet;

    if(endOfPrefix != nullptr) {
        /*
         * prefix is an existing key
         * (still requires prefix extraction because there may be another key which has this one as a prefix)
         */
        if(endOfPrefix->isEndOfWord())
            keySet.insert(prefix);

        std::set<std::string> dummy = Trie::extractPrefixes(prefix, endOfPrefix);
        keySet.insert(dummy.begin(), dummy.end());
    }

    return keySet;
}

void Trie::_print(std::ostream &out, TrieNode* root) const {
    const std::map<char, TrieNode*>& children = root->getChildren();

    for (auto it : children) {
        std::cout << it.first << " ";
        if(it.second->isEndOfWord())
            std::cout<<"\n";
        this->_print(out, it.second);
    }
}

std::ostream& operator<<(std::ostream& os, const Trie& trie) {
    trie._print(os, trie.root);
    return os;
}
