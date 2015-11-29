#ifndef PVER_TOKEN_H
#define PVER_TOKEN_H 1

#include <string>
#include <forward_list>

namespace pver {
    class token {
    private:
        typedef enum {
            PUNCTUATION,
            NUMERIC,
            ALHPANUMERIC
        } tag_type;
        std::string token;
        tag_type tag;
    public:
        token(const std::string & token_string);
        bool is_punct() const;
        bool is_numeric() const;
        bool is_alphanumeric() const;
        const std::string & str() const;
    };
    typedef std::forward_list<token> token_list_type;
    token_list_type tokenize(const std::string & ver);
    int compare_tokens(token_list_type a, token_list_type b);
    bool matches(token_list_type a, token_list_type b);
}

#endif
