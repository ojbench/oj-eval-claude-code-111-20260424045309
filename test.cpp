
#include <iostream>

char *strtok(char *str, const char *delim) {
    static char *last = nullptr;
    if (str != nullptr) {
        last = str;
    }
    if (last == nullptr) {
        return nullptr;
    }

    // Skip leading delimiters
    char *s = last;
    while (*s != '\0') {
        bool is_delim = false;
        const char *d = delim;
        while (*d != '\0') {
            if (*s == *d) {
                is_delim = true;
                break;
            }
            d++;
        }
        if (!is_delim) {
            break;
        }
        s++;
    }

    if (*s == '\0') {
        last = nullptr;
        return nullptr;
    }

    char *token_start = s;

    // Find the end of the token
    while (*s != '\0') {
        bool is_delim = false;
        const char *d = delim;
        while (*d != '\0') {
            if (*s == *d) {
                is_delim = true;
                break;
            }
            d++;
        }
        if (is_delim) {
            *s = '\0';
            last = s + 1;
            return token_start;
        }
        s++;
    }

    last = nullptr;
    return token_start;
}

int main() {
    // Sample 1
    {
        char s1[] = "abcdefaedd";
        const char d1[] = "abd";
        char *token = strtok(s1, d1);
        while (token != nullptr) {
            std::cout << token << std::endl;
            token = strtok(nullptr, d1);
        }
    }
    {
        char s2[] = "textabcwdefwghi";
        const char d2[] = "w";
        char *token = strtok(s2, d2);
        while (token != nullptr) {
            std::cout << token << std::endl;
            token = strtok(nullptr, d2);
        }
    }
    return 0;
}
