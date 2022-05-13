#include "optional.hpp"

template <typename T>
Optional<T>::Optional() : hasValue(false) {}

template <typename T>
Optional<T>::Optional(std::nullptr_t value) : Optional<T>() {}

template <typename T>
Optional<T>::Optional(T value) : value(value), hasValue(true) {}

template <typename T>
Optional<T> Optional<T>::operator=(std::nullptr_t value)
{
    hasValue = false;
}

template <typename T>
Optional<T> Optional<T>::operator=(T value)
{
    this->value = value;
    hasValue = true;
}