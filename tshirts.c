#include <stdio.h>
#include <assert.h>

#define UPPER_SIZE_SMALL 38
#define LOWER_SIZE_LARGE 42
#define UPPER_SIZE_LARGE 50

char size(int cms) {
    char sizeName = '\0';
    if(cms <= UPPER_SIZE_SMALL) {
        sizeName = 'S';
    } else if(cms > UPPER_SIZE_SMALL && cms < LOWER_SIZE_LARGE) {
        sizeName = 'M';
    } else if(cms >= LOWER_SIZE_LARGE && cms <=UPPER_SIZE_LARGE) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(38) == 'S');
    assert(size(40) == 'M');
    assert(size(42) == 'L');
    assert(size(50) == 'L');
    assert(size(55) == '\0');
    printf("All is well (maybe!)\n");
    return 0;
}
