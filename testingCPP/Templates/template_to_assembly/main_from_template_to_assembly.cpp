#include "from_template_to_assembly.hpp"
#include <iostream>

int main(void)
{
    ::print<const char *>("hello");
    ::print<int>(5);
    return (0);
}