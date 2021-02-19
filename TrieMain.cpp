#include "Trie_lib/Trie.h"
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char *argv[]) {

	Trie trie;

	trie.insert("peter");
	trie.insert("pedantic");
	trie.insert("pad");
	trie.insert("pandemic");

	cout<< trie <<endl;

	//unique_ptr<Trie> trieptr(new Trie());

	return 0;
}