cmake_minimum_required(VERSION 3.15)
project(DS)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DS
        Trie.cpp
        Trie.h
        TrieMain.cpp
        TrieNode.cpp
        TrieNode.h)
