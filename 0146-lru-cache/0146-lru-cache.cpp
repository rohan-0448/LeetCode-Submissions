class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int x, int y) {
        key = x;
        val = y;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp; // key - value map
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode) { // add a new node to front
        Node* temp = head -> next;
        head -> next = newnode;
        newnode -> prev = head;

        newnode -> next = temp;
        temp -> prev = newnode;
    }

    void delNode(Node* delnode) {
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            int ans = temp -> val;

            mpp.erase(key);
            delNode(temp);
            addNode(temp);

            mpp[key] = head->next;
            return ans;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* temp = mpp[key];
            mpp.erase(key);
            delNode(temp);
        }

        if(mpp.size() == cap) {
            mpp.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }
        
        Node* newnode = new Node(key, value);
        addNode(newnode);
        mpp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */