#include "role.h"
#include "name.h"

class character {
    std::pair<name, role> pairNameParticipation;
public:
    character();

    character(name &&pseudonim, role &&participation);

    bool operator==(const character &rhs) const;

    bool operator<(const character &rhs) const {
        return this->getPseudonim() < rhs.getPseudonim();
    }

    friend std::ostream& operator<<(std::ostream& out, character& characterToPrint);

    std::string getStringFormname() const;

    name getPseudonim() const;

    role getRole() const;
};
