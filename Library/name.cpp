#include "name.h"

name::name(const std::pair<std::string, std::string> &name) {
    name = name.first;
    surname = name.second;
}

name::name() = default;


name::name(std::string &&name, std::string &&surname) {
    this->name = name;
    this->surname = surname;
}

std::string name::getName() const {
    return name;
}

std::string name::getSurname() const {
    return surname;
}

void name::setName(std::string &nameIn) {
    this->name = nameIn;
}

void name::setSurname(std::string &surnameIn) {
    this->surname = surnameIn;
}

bool name::operator==(const name &rhs) const {
    return ((this->name == rhs.name) && (this->surname == rhs.surname));
}

bool name::operator<(const name &rhs) const {
    return this->name < rhs.name && this->surname < rhs.surname;
}

std::ostream &operator<<(std::ostream &out, name &pseudonim) {
    out << pseudonim.getName() << " " << pseudonim.getSurname();
    return out;
}
