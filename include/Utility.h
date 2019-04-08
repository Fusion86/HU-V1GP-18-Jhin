#pragma once

#define xstr(s) str(s)
#define str(s) #s

// Clear specified line
#define clearline(line) \
    move(y, 0);         \
    clrtoeol();

constexpr unsigned int hash(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (hash(str, h + 1) * 33) ^ str[h];
}
