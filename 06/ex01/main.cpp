#include "Serializer.hpp"

int main() {
    t_data tmp1;

    tmp1.number = 255;
    tmp1.str = "Med Sarda";
    uintptr_t res = Serializer::serialize(&tmp1);
    t_data *tmp2 = Serializer::deserialize(res);
    if (&tmp1 == tmp2)
    {
        std::cout << "the two addresses are equal" << std::endl;
        std::cout << "tmp1 : " << &tmp1 << std::endl;
        std::cout << "tmp2 : " << tmp2 << std::endl;
        return 0;
    }
    else
    {
        std::cout << "They are not equal" << std::endl;
        return 1;
    }
}
