/* Least Recently Used Cache.
 *
 * Store := key and node pointer pair => map
 *          current status of usage => doubly linked list.
 *
 *
 *  Empty map data structure := Head [-1,-1]: next -> tail
 *                                    prev -> null
 *
 *                              Tail [-1,-1]: next -> null
 *                                    prev -> head
 *
 *   most recently used will be closest to head.
 *
 *
 *  Store in map -> [key, address of linked-list node]
 * */

#include <iostream>
#include <optional>
#include <unordered_map>

template <typename K, typename V>
struct Node {
  Node* next;
  Node* prev;
  K key;
  V value;

  Node() : next{nullptr}, prev{nullptr}, key{}, value{} {}
  Node(K k, V v) : next{nullptr}, prev{nullptr}, key{k}, value{v} {}
};

template <typename K, typename V, typename C>
class LRUcache {
 public:
  C capacity;

  LRUcache(C capacity) : capacity{capacity} {
    m_head = new Node<K, V>;
    m_tail = new Node<K, V>;
    m_head->next = m_tail;
    m_tail->prev = m_head;
  }

  ~LRUcache() {
    Node<K, V>* curr = m_head;
    while (curr) {
      Node<K, V>* temp = curr;
      curr = curr->next;
      delete temp;
    }
  }

  std::optional<V> get(const K& key) {
    if (!m_cache.contains(key)) return {};
    Node<K, V>* node = m_cache[key];
    m_detachNode(node);
    m_insertAfterHead(node);

    return node->value;
  }

  void put(const K& key, const V& value) {
    if (m_cache.contains(key)) {
      Node<K, V>* node = m_cache[key];
      node->value = value;
      m_detachNode(node);
      m_insertAfterHead(node);
    } else {
      if (m_cache.size() == capacity) {
        Node<K, V>* node = m_tail->prev;
        m_cache.erase(node->key);
        m_detachNode(node);
        delete node;
      }

      Node<K, V>* node = new Node<K, V>(key, value);
      m_cache.emplace(key, node);
      m_insertAfterHead(node);
    }
  }

 private:
  Node<K, V>* m_head;
  Node<K, V>* m_tail;
  std::unordered_map<K, Node<K, V>*> m_cache;

  void m_detachNode(Node<K, V>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
  }

  void m_insertAfterHead(Node<K, V>* node) {
    m_head->next->prev = node;
    node->next = m_head->next;
    node->prev = m_head;
    m_head->next = node;
  }
};

int main() { std::cout << "LRUcache compiled.\n"; }
