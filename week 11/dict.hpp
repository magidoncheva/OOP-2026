#ifndef __DICT_H__
#define __DICT_H__

template <typename T, typename S>
struct DictElement {
    T key;
    S value;
};

template <typename T, typename S>
class Dict {
    DictElement<T, S>* arr;
    size_t size;

    void copy(const Dict<T, S>& other) {
        size = other.size;
        arr = new DictElement<T, S>[size];

        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }

    void swap(Dict<T, S>& other);
    size_t find(const T& key) const;

    public:
    Dict();
    Dict(const Dict<T, S>& other);
    Dict& operator=(const Dict<T, S>& other);
    ~Dict();

    void add(const T& key, const S& value);
    S&  operator[](const T& key);
    const S&  operator[](const T& key) const;
};

template <typename T, typename S>
void Dict<T, S>::swap(Dict<T, S>& other) {
    std::swap(arr, other.arr);
    std::swap(size, other.size);
}

template <typename T, typename S>
size_t Dict<T, S>::find(const T& key) const{
    for (size_t i = 0; i < size; ++i) {
        if (arr[i].key == key) {
            return i;
        }
    }

    return size;
}

template <typename T, typename S>
Dict<T, S>::Dict(): arr(nullptr), size(0) {}

template <typename T, typename S>
Dict<T, S>::Dict(const Dict<T, S>& other): arr(nullptr), size(0) {
    copy(other);
}

template <typename T, typename S>
Dict<T, S>& Dict<T, S>::operator=(const Dict<T, S>& other){
    if (this != &other) {
        Dict copyOfOther(other);
        swap(copyOfOther);
    }

    return *this;
}

template <typename T, typename S>
Dict<T, S>::~Dict(){
    delete[] arr;
}

template <typename T, typename S>
void Dict<T, S>::add(const T& key, const S& value) {
    size_t index = find(key);
    if (index != size) {
        arr[index].value = value;
        return;
    }

    DictElement<T, S>* tmp = new DictElement<T, S>[size + 1];
    for (size_t i = 0; i < size; ++i) {
        tmp[i] = arr[i];
    }

    tmp[size].key = key;
    tmp[size].value = value;

    delete[] arr;
    arr = tmp;
    ++size;
}

template <typename T, typename S>
S& Dict<T, S>::operator[](const T& key) {
    size_t index = find(key);

    if (index == size) {
        throw std::out_of_range("Index out of range");
    }

    return arr[index].value;
}

template <typename T, typename S>
const S& Dict<T, S>::operator[](const T& key) const {
    size_t index = find(key);

    if (index == size) {
        throw std::out_of_range("Index out of range");
    } 

    return arr[index].value;
}

#endif // __DICT_H__