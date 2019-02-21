unsigned power_helper(unsigned x, unsigned y, unsigned m) {
    if (y == 1) {
        return x;
    } else if (y == 0) {
        return 1;
    } else if (x == 0) {
        return 0;
    }

    power_helper(x * m, y - 1, m);
}

unsigned power(unsigned x, unsigned y) {
    return power_helper(x, y, x);
}

