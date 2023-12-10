#include "character.h"

character::character(name &&pseudonim, role &&participation) {
    pairNameParticipation.first = pseudonim;
    pairNameParticipation.second = participation;
}

bool character::operator==(const character &rhs) const {
    return this->pairNameParticipation.first == rhs.pairNameParticipation.first;
}

bool operator<(const character &lhs, const character &rhs) {
    return lhs.getPseudonim() < rhs.getPseudonim();
}

character::character() = default;

name character::getPseudonim() const {
    return pairNameParticipation.first;
}

role character::getRole() const {
    return pairNameParticipation.second;
}

std::string character::getStringFormname() const {
    return this->getPseudonim().getName() + " " + this->getPseudonim().getSurname();
}

std::ostream &operator<<(std::ostream &out, character &characterToPrint) {
    out << characterToPrint.pairNameParticipation.first << " (" << characterToPrint.pairNameParticipation.second
        << ")";
    return out;
}
