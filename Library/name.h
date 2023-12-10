#include <iostream>

class name : public std::error_code {
    std::string name{};
    std::string surname{};
public:
    explicit name(const std::pair<std::string, std::string> &name);

    name();

    name(std::string &&name, std::string &&surname);

    std::string getName() const;

    std::string getSurname() const;

    void setName(std::string &nameIn);

    void setSurname(std::string &surnameIn);

    friend std::ostream& operator<<(std::ostream& out, name& pseudonim);

    bool operator==(const name& rhs) const;

    bool operator<(const name& rhs) const;
};
