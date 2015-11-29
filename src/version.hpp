#ifndef PVER_VERSION_H
#define PVER_VERSION_H 1

#include "token.hpp"
#include <string>

namespace pver {
    class version {
    private:
        pver::token::token_list_type cmp_version_parts;
        std::string line;
        std::string release;
        std::string build;
        int cmp(const version & other);
    public:
        version(const std::string & ver);

        const std::string & line() const;
        const std::string & release() const;
        const std::string & build() const;
        bool match(const version & other);
        bool operator == (const version & other);
        bool operator != (const version & other);
        bool operator <= (const version & other);
        bool operator >= (const version & other);
        bool operator < (const version & other);
        bool operator > (const version & other);
        std::string to_string() const;
    };
}

#endif
