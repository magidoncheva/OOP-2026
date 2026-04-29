#ifndef __VECTOR_H__
#define __VECTOR_H__

template <typename T>
class Vector {
    T* arr;
    size_t size;
    size_t capacity;

    void copy(const Vector<T>& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->arr = new T[this->capacity];

        for (size_t i = 0; i < this->size; ++i) {
            this->arr[i] = other.arr[i];
        }
    }

    void move(Vector<T>&& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->arr = other.arr;

        other.arr = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    void resize(const size_t& size) {
        if (size >= this->capacity) {
            this->capacity = 2*size + 1;
            T* tmp = new T[this->capacity];

            for (size_t i = 0; i < this->size; ++i) {
                tmp[i] = this->arr[i];
            }

            delete[] this->arr;
            this->arr = tmp;
        }

        this->size = size;
    }

    public:
    Vector(){
        arr = nullptr;
        size = 0;
        capacity = 0;
    }

    Vector(const size_t& size) {
        this->capacity = 0;
        this->size = 0;
        arr = nullptr;
        resize(size);
    }

    Vector(const Vector<T>& other) {
        copy(other);
    }

    Vector(Vector<T>&& other) {
        move(std::move(other));
    }

    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            delete[] arr;
            copy(other);
        }

        return *this;
    }

    Vector<T>& operator=(Vector<T>&& other) {
        if (this != &other) {
            delete[] arr;
            move(std::move(other));
        }

        return *this;
    }

    ~Vector() {
        delete[] arr;
    }

    size_t lenght() const {
        return size;
    }

    T& operator[](const size_t& index) {
        if (index >= this->size) {
            throw std::out_of_range("Index out of range");
        }

        return arr[index];
    }

    void append(const T& value) {
        if (this->size == this->capacity) {
            resize(this->size);
        }

        this->arr[this->size] = value;
        this->size++;
    }
};

#endif // __VECTOR_H__