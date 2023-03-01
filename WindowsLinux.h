#pragma once
#include <cstdlib>
#include <ctime>

// Clear terminal screen
void clear_screen() {
    const char* cmd =
#ifdef _WIN32
    "cls";
#else
    "clear";
#endif
    system(cmd);
}

// Linux sleep function
int nanosleep(const struct timespec* req, struct timespec* rem);

int sleep_ms(long ms) {
    struct timespec ts;

    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;

    return nanosleep(&ts, NULL);
}