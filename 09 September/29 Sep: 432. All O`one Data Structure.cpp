class Node {
public:
    int count;
    unordered_set<string> st;
    Node* next;
    Node* prev;

    Node(int c) {
        count = c;
        next = nullptr;
        prev = nullptr;
    }
};

class AllOne {
    Node* head;
    Node* tail;
    unordered_map<string, int> keyCount;
    unordered_map<int, Node*> addr;

public:
    AllOne() {
        head = nullptr;
        tail = nullptr;
    }

    void inc(string key) {
        if (keyCount.find(key) == keyCount.end()) {
            // First time insertion of the key
            if (!head || head->count > 1) {
                Node* tmp = new Node(1);
                insertNode(tmp);
                addr[1] = tmp;
            }
            head->st.insert(key);
            keyCount[key] = 1;
        } else {
            // Key already exists, update it
            update(key, true);
        }
    }

    void dec(string key) {
        if (keyCount.find(key) == keyCount.end())
            return; // Key doesn't exist
        if (keyCount[key] == 1) {
            // If it's at count 1, we need to remove it
            head->st.erase(key);
            if (head->st.empty()) {
                deleteNode(head);
                addr.erase(1);
            }
            keyCount.erase(key);
        } else {
            // Otherwise, decrease its count
            update(key, false);
        }
    }

    string getMaxKey() {
        if (!tail)
            return ""; // No keys
        return *(tail->st.begin());
    }

    string getMinKey() {
        if (!head)
            return ""; // No keys
        return *(head->st.begin());
    }

    void update(string key, bool inc) {
        int curCount = keyCount[key];
        Node* curAddr = addr[curCount];
        curAddr->st.erase(key);

        // Delete the node if empty
        if (curAddr->st.empty()) {
            deleteNode(curAddr);
            addr.erase(curCount);
        }

        int newCount = curCount + (inc ? 1 : -1);

        if (!inc && curCount == 1) {
            // If decrementing and count is 1, remove the key entirely
            keyCount.erase(key);
            return;
        }

        if (addr.find(newCount) == addr.end()) {
            // Create a new node for the new count
            Node* tmp = new Node(newCount);
            insertNode(tmp);
            addr[newCount] = tmp;
        }
        addr[newCount]->st.insert(key);
        keyCount[key] = newCount;
    }

    void deleteNode(Node* node) {
        if (!node)
            return;
        if (head == tail && node == head) {
            head = nullptr;
            tail = nullptr;
        } else if (node == head) {
            head = head->next;
            if (head)
                head->prev = nullptr;
        } else if (node == tail) {
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
        } else {
            Node* p = node->prev;
            Node* n = node->next;
            p->next = n;
            n->prev = p;
        }
        delete node;
    }

    void insertNode(Node* node) {
        if (!head) {
            head = node;
            tail = node;
            return;
        }

        if (node->count < head->count) {
            // Insert node before head
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }

        Node* tmp = head;
        while (tmp->next && node->count > tmp->next->count) {
            tmp = tmp->next;
        }

        node->next = tmp->next;
        if (tmp->next) {
            tmp->next->prev = node;
        } else {
            tail = node;
        }
        tmp->next = node;
        node->prev = tmp;
    }
};
