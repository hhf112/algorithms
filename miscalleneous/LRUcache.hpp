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

#include <optional>       //std::optional
#include <unordered_map>  // std::unordered_map

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
  LRUcache(C capacity) : m_capacity{capacity} {
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
    detachNode(node);
    insertAfterHead(node);

    return node->value;
  }

  void put(const K& key, const V& value) {
    if (m_cache.contains(key)) {
      Node<K, V>* node = m_cache[key];
      node->value = value;
      detachNode(node);
      insertAfterHead(node);
    } else {
      if (m_cache.size() == m_capacity) {
        Node<K, V>* node = m_tail->prev;
        m_cache.erase(node->key);
        detachNode(node);
        delete node;
      }

      Node<K, V>* node = new Node<K, V>(key, value);
      m_cache.emplace(key, node);
      insertAfterHead(node);
    }
  }

 private:
  void detachNode(Node<K, V>* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->prev = nullptr;
    node->next = nullptr;
  }

  void insertAfterHead(Node<K, V>* node) {
    m_head->next->prev = node;
    node->next = m_head->next;
    node->prev = m_head;
    m_head->next = node;
  }

  Node<K, V>* m_head;
  Node<K, V>* m_tail;
  std::unordered_map<K, Node<K, V>*> m_cache;
  C m_capacity;
};

// #include <iostream>
// int main() { std::cout << "LRUcache compiled.\n"; }
