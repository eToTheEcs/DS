#include "Trie.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

	Trie trie;

	trie.insert("peter");
	trie.insert("pedantic");
	trie.insert("paddle");
	trie.insert("pandemic");

	cout<< trie <<endl;

	cout<< endl << trie.search("paddle") << endl;

	return 0;
}