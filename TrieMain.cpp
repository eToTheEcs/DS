#include "Trie_lib/Trie.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	Trie trie;

	trie.insert("peter");
	trie.insert("pedantic");
	trie.insert("paddle");
	trie.insert("pandemic");

	cout<< trie <<endl;

	cout<< endl << trie.search("peter") << endl;

	trie.prefixSearch("pe");
	trie.prefixSearch("pa");

	cout<< "PREFIX SEARCH:" << endl;

	set<string> results = trie.prefixSearch("p");

	if(!results.size()) {
	    cout<< "NO RESULTS FOUND\n";
	} else {
        for (auto it = results.begin(); it != results.end(); it++)
            cout << *it << "\n";
    }

	return 0;
}