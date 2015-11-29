#ifndef PVER_EXCEPTION_H
#define PVER_EXCEPTION_H 1
#include <exception>

namespace pver {
    namespace exception {
        // It is an error to have a version string start with a
        // non-alphanumeric character
        // It is an error to have a version string end with a
        // non-alphanumeric character
        // It is an error to have a version string be empty
        // It is an error to have a version string have an
        // invalid character
        class generic : public std::exception
        {
        public:
            const char * what() throw() {
                return "Generic pver versioning exception";
            }
        };

        class invalid_start : public generic
        {
        public:
            const char * what() throw() {
                return "Version string must start with an alphanumeric character.";
            }
        };

        class invalid_end : public generic
        {
        public:
            const char * what() throw() {
                return "Version string much end with an alphanumeric character.";
            }
        };

        class invalid_character : public generic
        {
        public:
            const char * what() throw() {
                return "Invalid character in version string.";
            }
        };
    }
}

#endif // PVER_EXCEPTION_H
