template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;

    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (head == nullptr) throw string ("error: Queue is empty. Nothing to return.");

    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    Node* cur = head;
    Node* temp = cur;

    while (cur != nullptr){
        cur = cur -> next;
        delete temp;
        temp = cur;
    }

    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    clear();
    if (copyObj.head == nullptr) return; //if source is empty, then return

    Node* cur = copyObj.head;

    while(cur != nullptr){
        this->enqueue(cur->value); //enqueue will handle the newNode
        cur = cur -> next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (head == nullptr) throw string ("error: queue is empty. Nothing to dequeue.");

    Node* temp = head;

    head = head -> next;

    if (head == nullptr) last = nullptr; // if there was only 1 node, then head and last will be nullptr

    delete temp;
    --this->length;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* newNode = new Node(elem, nullptr);

    if (head == nullptr) { //if already empty, just assign newNode as head and ++
        head = newNode;
        last = newNode;
    } else{
    last -> next = newNode;
    last = newNode;
    }

    ++this->length;
    /*
    while (cur -> next != nullptr){
        cur = cur -> next;
    } 

    cur -> next = newNode;
    last = newNode;
    ++this->length;
    return;
    */
    }

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (head == nullptr) throw string ("error: Queue is empty. Nothing to return.");

    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
