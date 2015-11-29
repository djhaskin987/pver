#ifndef __PVER_H__
#define __PVER_H__ 1
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

    namespace character {
        // is a valid buildsep byte (`+`)
        bool is_build_separator(int c);

        // is a valid relsep byte (`-`)
        bool is_release_separator(int c);

        // is a valid epoch separator byte (`:`)
        bool is_epoch_separator(int c);

        // is a valid punctuation byte (`,` `;` `_` `.` `~`)
        bool is_punctuation(int c);

        // is an alphabetic byte (`a` - `z`)
        bool is_alphabetic(int c);

        // is a numeric byte (`0` - `9`)
        bool is_numeric(int c);

        // is an alphanumeric byte
        bool is_alphanumeric(int c);

        // is a valid version byte (it matches spec for one of the above)
        bool is_valid(int c);

    }

    class version {
    private:
        class token
        {
        private:
            typedef enum {
                PUNCTUATION,
                NUMERIC,
                ALHPANUMERIC
            } token_type;
            std::string token;
            token_type tag;
        public:
            token(const std::string & token_string);
            bool is_punct() const;
            bool is_numeric() const;
            bool is_alphanumeric() const;
            const std::string & str() const;
        };
        static token_list_type tokenize(const std::string & ver);
        static int compare_tokens(token_list_type a, token_list_type b);
        typedef std::forward_list<token> token_list_type;

        token_list_type cmp_version_parts;
        std::string line;
        std::string release;
        std::string build;
        int cmp(const version & other);
    public:
        version(const std::string & ver);
        const std::string & str() const;
        const std::string & line() const;
        const std::string & release() const;
        const std::string & build() const;
        bool match(const versiog& other);
        bool operator == (const version & other);
        bool operator != (const version & other);
        bool operator <= (const version & other);
        bool operator >= (const version & other);
        bool operator < (const version & other);
        bool operator > (const version & other);
    };
}

#endif
