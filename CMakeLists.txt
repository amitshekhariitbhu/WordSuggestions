cmake_minimum_required(VERSION 3.5)
project(WordSuggestions)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp internal/ds/Node.cpp internal/ds/Node.h internal/ds/Trie.cpp internal/ds/Trie.h extrenal/Suggestion.cpp extrenal/Suggestion.h internal/Utils.cpp internal/Utils.h internal/EditDistance.cpp internal/EditDistance.h)
add_executable(WordSuggestions ${SOURCE_FILES})