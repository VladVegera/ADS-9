// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;
  std::string words = "";
  char lowcase = 'a' - 'A';
  std::ifstream file(filename);
  
  if (!file) {
    std::cout << "Error!" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char char = file.get();
    if ((char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z')) {
      if (char >= 'A' && char <= 'Z')
        char += lowercase;
      words += char;
    } else if (words != "") {
      tree.add(words);
      words = "";
    }
  }
  file.close();
  return tree;
}
