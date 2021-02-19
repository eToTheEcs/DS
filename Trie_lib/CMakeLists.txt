project(Trie)

set(HEADER_FILES
        Trie.h
        )

set(SOURCE_FILES
        TrieNode.cpp
        Trie.cpp
        AutocompletionHandler.cpp AutocompletionHandler.h)

add_library(Trie_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})