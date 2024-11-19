#include "Serializer.hpp"

Serializer::Serializer() {

}
Serializer::~Serializer() {

}
Serializer::Serializer(const Serializer &copy) {
    (void)copy;
}
Serializer &Serializer::operator=(const Serializer &copy) {
    (void)copy;
    return *this;
}

uintptr_t Serializer::serialize(t_data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
t_data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<t_data *>(raw);
}