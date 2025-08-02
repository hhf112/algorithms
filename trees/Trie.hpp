#pragma once
#include <string>  // std::std::string
#define CHARS 26

struct Node {
 public:
  Node() {
    for (int i = 0; i < CHARS; i++) {
      m_links[i] = nullptr;
    }
  }
  inline bool containsKey(char ch) { return m_links[ch - 'a'] != nullptr; }
  inline void put(char ch, Node* node) { m_links[ch - 'a'] = node; }
  inline Node* get(char ch) { return m_links[ch - 'a']; }
  inline void setEnd() { m_flag = true; }
  inline bool isEnd() { return m_flag; }
  inline void addCount() { m_cnt++; }
  inline void addPrefix() { m_cntPrefix++; }
  inline void deleteCount() { m_cnt--; }
  inline void deletePrefix() { m_cntPrefix--; }
  inline int getCount() { return m_cnt; }
  inline int getPrefix() { return m_cntPrefix; }

 private:
  Node* m_links[CHARS];
  bool m_flag = false;
  int m_cnt = 0;
  int m_cntPrefix = 0;
};

class Trie {
 public:
  Trie() { m_root = new Node(); }

  inline void insert(std::string word) {
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

  inline bool search(std::string word) {
    Node* node = m_root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) return false;
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  inline int count(std::string prefix) {
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

  inline bool hasPrefix(std::string prefix) {
    Node* node = m_root;
    for (int i = 0; i < prefix.length(); i++) {
      if (!node->containsKey(prefix[i])) return false;
      node = node->get(prefix[i]);
    }
    return true;
  }

  inline int countPrefix(std::string prefix) {
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

  inline void erase(std::string word) {
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
//   std::cout << "compiled\n";
// }
