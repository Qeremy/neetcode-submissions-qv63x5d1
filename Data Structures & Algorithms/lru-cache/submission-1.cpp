


class LRUCache {
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

private:
unordered_map<int, Node*> dict;
Node* head;
Node* tail;
int currSize;
int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        currSize = 0;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void moveToTail(Node* node){
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(dict.find(key) != dict.end()){
            remove(dict[key]);
            moveToTail(dict[key]);
            return dict[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(dict.find(key) != dict.end()){
            remove(dict[key]);
            moveToTail(dict[key]);
            dict[key]->value = value;
        }
        else if(currSize == cap){
            Node* lru = head->next;
            remove(lru);
            dict.erase(lru->key);
            Node* n = new Node(key, value);
            moveToTail(n);
            dict.insert({key, n});
        }
        else{
            currSize++;
            Node* n = new Node(key, value);
            moveToTail(n);
            dict.insert({key, n});
        }
    }
};
