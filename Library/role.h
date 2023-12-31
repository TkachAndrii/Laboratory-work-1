#include <iostream>

enum class role {
    primary,
    secondary,
    tertiary
};

inline
std::ostream &operator<<(std::ostream &out, const role roleToPrint) {
    switch (roleToPrint) {
        case role::primary:
            out << "primary";
            break;
        case role::secondary:
            out << "secondary";
            break;
        case role::tertiary:
            out << "tertiary";
    }
    return out;
}
