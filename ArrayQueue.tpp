template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    frontIndex = 0;
    backIndex = 0;
    maxSize = i;
    buffer = new T[maxSize]; //allocate memory
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (isEmpty()) throw string ("error: queue is empty. Unable to print back data.");

    int lastIndex = (frontIndex +this->length - 1);
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    if (buffer != nullptr){
        delete[] buffer;
        buffer = new T(maxSize);
        buffer = nullptr;
    }

    this->length = 0;
    frontIndex = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    //sync up properties
    this->maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->frontIndex = copyObj.frontIndex;

    this->buffer = new T[this->maxSize]; //allocating memory for new data array

    //iterate and copy paste the data from source buffer to destination buffer
    for (int i = 0; i < maxSize; ++i){
        this->buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (this->length == 0) throw string ("error: cannot dequeue. Queue is already empty.");

    frontIndex = (frontIndex + 1) % maxSize;

    --this->length;
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (this->length == maxSize) throw string ("error: cannot enqueue. Queue is full.");

    int insertIndex = (frontIndex + this->length) % maxSize;

    buffer[insertIndex] = elem;

    ++this->length;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if(isEmpty()) throw string ("error: queue is empty. Unable to print front data.");
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
