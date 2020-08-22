cmake_minimum_required(VERSION 3.15)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DS
        Trie_lib/Trie.cpp
        Trie_lib/Trie.h
        TrieMain.cpp
        Trie_lib/TrieNode.cpp
        Trie_lib/TrieNode.h)

add_subdirectory(google_tests)