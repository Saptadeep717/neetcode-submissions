

class LRUCache {
public:
class Node{
public:
    int key,value;
    Node* prev, *next;

    Node(int key, int val){
        this->key = key;
        this->value = val;
        prev=next=NULL;
    }
};
    int cap;
    unordered_map<int,Node*>mp;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        this->cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode-> next = temp;
        temp->prev = newNode;
        newNode->prev=head;
        head->next=newNode;
    }
    
    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            int res = existing->value;
            mp.erase(key);
            deleteNode(existing);
            addNode(existing);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        else if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* nNode = new Node(key,value);
        addNode(nNode);
        mp[key]=head->next;
    }
};
