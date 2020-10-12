project(Trie)

set(HEADER_FILES
        TrieNode.h
        Trie.h
        )

set(SOURCE_FILES
        TrieNode.cpp
        Trie.cpp
        )

add_library(Trie_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})