#ifndef SRC_HPP
#define SRC_HPP

/**
 * @brief split STRing by TOKen：以delim为分隔符，分隔字符串str。
 * @param str 源字符串
 * @param delim 一个字符串，其中每一个字符都被当成一种分隔符
 * @return 返回分割得到的第一个字符串。
 */
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

#endif // SRC_HPP
