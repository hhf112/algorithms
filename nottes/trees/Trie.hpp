#pragma once
#include <string>  // std::std::string
#define CHARS 26

class Node {
 public:
  Node() {
    for (int i = 0; i < CHARS; i++) {
      m_links[i] = nullptr;
    }
  }
  bool containsKey(char ch) { return m_links[ch - 'a'] != nullptr; }
  void put(char ch, Node* node) { m_links[ch - 'a'] = node; }
  Node* get(char ch) { return m_links[ch - 'a']; }
  void setEnd() { m_flag = true; }
  bool isEnd() { return m_flag; }
  void addCount() { m_cnt++; }
  void addPrefix() { m_cntPrefix++; }
  void deleteCount() { m_cnt--; }
  void deletePrefix() { m_cntPrefix--; }
  int getCount() { return m_cnt; }
  int getPrefix() { return m_cntPrefix; }
 private:
  Node* m_links[CHARS];
  bool m_flag = false;
  int m_cnt = 0;
  int m_cntPrefix = 0;
};

class Trie {
 public:
  Trie() { m_root = new Node(); }

  void insert(std::string word) {
    Node* node = m_root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        node->put(word[i], new Node);
      }
      node = node->get(word[i]);
      node->addPrefix();
    }
    node->addCount();
  }

  bool search(std::string word) {
    Node* node = m_root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) return false;
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  int count(std::string prefix) {
    Node* node = m_root;
    for (int i = 0; i < prefix.length(); i++) {
      if (node->containsKey(prefix[i])) {
        node = node->get(prefix[i]);
      } else {
        return 0;
      }
    }
    return node->getCount();
  }

  bool hasPrefix(std::string prefix) {
    Node* node = m_root;
    for (int i = 0; i < prefix.length(); i++) {
      if (!node->containsKey(prefix[i])) return false;
      node = node->get(prefix[i]);
    }
    return true;
  }

  int countPrefix(std::string prefix) {
    Node* node = m_root;
    for (int i = 0; i < prefix.length(); i++) {
      if (node->containsKey(prefix[i])) {
        node = node->get(prefix[i]);
      } else {
        return 0;
      }
    }
    return node->getPrefix();
  }

  void erase(std::string word) {
    Node* node = m_root;
    for (int i = 0; i < word.length(); i++) {
      if (node->containsKey(word[i])) {
        node = node->get(word[i]);
        node->deletePrefix();
      }
      node->deleteCount();
    }
  }

 private:
  Node* m_root;
};

// #include <iostream>
// int main() {
//   cout << "compiled\n";
// }
