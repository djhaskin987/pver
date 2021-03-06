#include "character.hpp"
#include <string>

using namespace std;

// A version string is just a string of bytes.
//
// These functions are reimplemented (instead of using things in cctype)
// because those functions return values are locale-specific. We need
// to have functions that only respond to specific byte values.
//
// That is why I do not use, e.g., '-' here instead of 0x2D; I want to make
// it clear that I am going after specific byte values.
//
// To make it possible to allow semver-2.0-compliant version strings, `-` is
// used to add release strings and `+` may be used to add build information.
// The epoch character (`:`) is also used so that version formats may be
// migrated from if needed. Build information (Everything including the `+`
// character and after it) is ignored in version comparison.  - Release
// information (Everything including the `-` character and after it) causes
// version strings with it to compare earlier to equivalent version strings
// without it.  The epoch information (everything before the `:`, including
// it), causes version strings to compare later than other equivalent strings.
// It should be rarely used, except to change version string formats across
// releases.
//
// ASCII values:
//
// 0x30 - 0x39 : numeric
// 0x61 - 0x7A : (lowercase) alphabetic
// special characters:
//   release separator:    2D : `-`
//   build info separator: 2B : `+`
//   epoch separator:      3A : `:`
// puncuation characters:
//   2E : `.`
//   5E : `^`
//   7E : `~`
//   5F : `_`

bool pver::character::is_release_separator(int c) {
    // ASCII `-`
    return (c == 0x2D);
}

bool pver::character::is_build_separator(int c) {
    // ASCII `+`
    return (c == 0x2B);
}

bool pver::character::is_epoch_separator(int c) {
    // ASCII `:`
    return (c == 0x3A);
}

bool pver::character::is_punctuation(int c) {
    // ASCII `.`,`^`, `~`, or `_`
    return (c == 0x2E ||
        c == 0x5E ||
        c == 0x7E ||
        c == 0x5F);
}

bool pver::character::is_alphabetic(int c) {
    // ASCII `a-z`
    return (c >= 0x61 && c <= 0x7A);
}

bool pver::character::is_numeric(int c) {
    // ASCII `0-9`
    return (c >= 0x30 && c <= 0x39);
}

bool pver::character::is_alphanumeric(int c) {
    return (pver::character::is_numeric(c) ||
        pver::character::is_alphabetic(c));
}
