cmake_minimum_required(VERSION 3.15)
project(DS)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES TrieMain.cpp)

add_executable(Trie_run ${SOURCE_FILES})

include_directories(Trie_lib)
add_subdirectory(Trie_lib)

add_executable(DS ${SOURCE_FILES})

target_link_libraries(Trie_run Trie_lib)

add_subdirectory(google_tests)