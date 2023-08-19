#ifndef EIGEN_STORAGE_BASE_H
#define EIGEN_STORAGE_BASE_H

#include <memory>
#include "forward_declaration.h"

template<typename T, int Size, bool IsArray>
class StorageBase
{
public:
    StorageBase() {}
    StorageBase(int size)
        : size_(size)
    {
        array_ = std::make_unique<T[]>(size_);
    }
    StorageBase(const StorageBase& other)
        :size_(other.size_)
    {
        array_ = std::make_unique<T[]>(size_);
        std::copy(other.array_.get(), &other.array_.get()[size_], array_.get());
    }
    StorageBase& operator=(const StorageBase& other) {
        if (this == &other) {
            return *this;
        }
        if (size_ != other.size_) {
            size_ = other.size_;
            array_ = std::make_unique<T[]>(size_);
        }
        std::copy(other.array_.get(), &other.array_.get()[size_], array_.get());
        return *this;
    }
    StorageBase(StorageBase&& other)
        :size_(other.size_)
    {
        array_ = std::move(other.array_);
    }
    StorageBase& operator=(StorageBase&& other) {
        if (this == &other) {
            return *this;
        }
        size_ = other.size_;
        array_ = std::move(other.array_);
        return *this;
    }

    T* data() {
        return array_.get();
    }
private:
    std::unique_ptr<T[]> array_ { nullptr };
    int size_ { 0 };
};

template<typename T, int Size>
class StorageBase<T, Size, true>
{
public:
    StorageBase() {}
    StorageBase(int size) {}
    StorageBase(const StorageBase& other) {
        if (Size != other.size_) {
            return;
        }
        std::copy(other.array_, &other.array_[size_], array_);
    }
    StorageBase& operator=(const StorageBase& other) {
        if (this == &other) {
            return *this;
        }
        if (Size != other.size_) {
            return *this;
        }
        std::copy(other.array_, &other.array_[size_], array_);
        return *this;
    }
    StorageBase(StorageBase&& other) {
        if (Size != other.size_) {
            return;
        }
        std::copy(other.array_, &other.array_[size_], array_);
    }
    StorageBase operator=(StorageBase&& other) {
        if (this == &other) {
            return *this;
        }
        if (Size != other.size_) {
            return *this;
        }
        std::copy(other.array_, &other.array_[size_], array_);
        return *this;
    }

    T* data() {
        return array_;
    }
private:
    T array_[Size];
    int size_ { Size };
};

#endif