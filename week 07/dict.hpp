#ifndef __DICT_H__
#define __DICT_H__
#include "date.hpp"
#include "event.hpp"

struct DictElement {
    Date key;
    Event value;
};

class Dict {
    DictElement* arr;
    size_t size;

    void copy(const Dict& other);
    size_t find(const Date& key) const;

    public:
    Dict();
    Dict(const Dict& other);
    Dict& operator=(const Dict& other);
    ~Dict();

    Event&  operator[](const Date& key);
    const Event&  operator[](const Date& key) const;
};

void Dict::copy(const Dict& other){
    size = other.size;

    arr = new DictElement[size];

    for (size_t i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

size_t Dict::find(const Date& key) const{
    for (size_t i = 0; i < size; ++i) {
        if (arr[i].key == key) return i;
    }

    return size;
}


Dict::Dict() {
    arr = nullptr;
    size = 0;
}

Dict::Dict(const Dict& other){
    copy(other);
}

Dict& Dict::operator=(const Dict& other){
    if (this != &other) {
        delete[] arr;
        copy(other);
    }

    return *this;
}

Dict::~Dict(){
    delete[] arr;
}

Event& Dict::operator[](const Date& key) {
    size_t index = find(key);

    if (index == size) {
        DictElement* tmp = new DictElement[size + 1];

        for (size_t i = 0; i < size; ++i) {
            tmp[i] = arr[i];
        }

        delete[] arr;
        
        arr = tmp;
        ++size;
    } 

    return arr[index].value;
}


const Event& Dict::operator[](const Date& key) const {
    size_t index = find(key);

    if (index == size) {
        throw std::out_of_range("Index out of range");
    } 

    return arr[index].value;
}



#endif // __DICT_H__