#include <bits/stdc++.h>
using namespace std;

//Node of trie
struct Node{
  //implementation for words containing only lowercase english letters
private:
  Node* links[26];
  bool flag = false;
  int cntEndWith = 0;
  int cntPrefix = 0;

public:


  Node(){
    for (int i = 0; i<26; i++){
      links[i] = NULL;
    }
  }


  bool containsKey(char ch){
    return links[ch -'a'] != NULL;
  }

  void put(char ch, Node* node){
    links[ch - 'a'] = node;
  }

  Node* get(char ch){
    return links[ch - 'a'];
  }

  void setEnd(){
    flag = true;
  }

  bool isEnd(){
    return flag;
  }

  void increaseEnd(){
    cntEndWith++;
  }

  void increasePrefix(){
    cntPrefix++;
  }

  void deleteEnd(){
    cntEndWith--;
  }

  void reducePrefix(){
    cntPrefix--;
  }

  int getEnd(){
    return cntEndWith;
  }

  int getPrefix(){
    return cntPrefix;
  }
};


class Trie{

private: 
  Node* root;


public:

  /*Initialize trie*/
  Trie(){
    root = new Node();
  }

  // function if not including the counts
  // //Time complexity = O(word.length())
  // void insert(string word){
  //   Node* node = root;
  //
  //   for (int i = 0; i<word.length(); i++){
  //     if (!node->containsKey(word[i])){
  //       node->put(word[i], new Node());
  //     }
  //
  //     //move to the ref trie
  //     node->get(word[i]);
  //   }
  //
  //   //final flag is turned to true
  //   node->setEnd();
  // }
  //

  void insert(string word){
    Node* node = root;

    for (int i = 0; i<word.length(); i++){
      if (!node->containsKey(word[i])){
        node->put(word[i], new Node);
      }

      node->get(word[i]);
      node->increasePrefix();
    }

    node->increaseEnd();

  }
  



  //Time complexity = O(word.length())
  bool search(string word){
    Node* node = root;

    for (int i = 0; i<word.length(); i++){
      if (!node->containsKey(word[i])) 
        return false;

      node = node->get(word[i]);
    }

    //check if final flag is true
    return node->isEnd();
  }

  //
  //Time complexity = O(prefix.length())
  bool startsWith(string prefix){
    Node* node = root;

    for (int i = 0; i<prefix.length(); i++){
      if (!node->containsKey(prefix[i]))
        return false;

      node = node->get(prefix[i]);
    }

    return true;
  } 

  int countWordsEqualTo (string prefix){
    Node* node = root;

    for (int i = 0; i<prefix.length(); i++){
      if (node->containsKey(prefix[i])){
        node->get(prefix[i]);
      }
      else{
        return 0;
      }
    }

    return  node->getEnd();

  }


  int countStartingWith(string prefix){    
    Node* node = root;

    for (int i = 0; i<prefix.length(); i++){
      if (node->containsKey(prefix[i])){
        node->get(prefix[i]);
      }
      else{
        return 0;
      }
    }

    return  node->getPrefix();
  }


  void erase(string word){
    Node* node = root;

    for (int i = 0; i<word.length(); i++){
      if (node->containsKey(word[i])){
        node->get(word[i]);
        node->reducePrefix();
      }

      node->deleteEnd();
    }
  }
};
