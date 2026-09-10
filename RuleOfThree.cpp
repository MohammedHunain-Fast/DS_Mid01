class DynamicArray {
private:
    int* data;
    int size;

public:
    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Copy Constructor (Deep Copy)
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

    // Copy Assignment Operator (Deep Copy)
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) { // 1. Prevent self-assignment (obj = obj)
            delete[] data;    // 2. Free existing memory

            size = other.size; // 3. Allocate new memory & copy
            data = new int[size];
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
        return *this; // 4. Return current object reference
    }
};
