#ifndef PVER_CHARACTER_H
#define PVER_CHARACTER_H 1

namespace pver {
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
}

#endif // PVER_CHARACTER_H
