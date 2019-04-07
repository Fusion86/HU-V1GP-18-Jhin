#pragma once

#define xstr(s) str(s)
#define str(s) #s

// Clear specified line
#define clearline(line) \
    move(y, 0);         \
    clrtoeol();
