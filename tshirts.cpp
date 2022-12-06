#include <iostream>
#include <assert.h>

#define UPPER_BOUNDARY_FOR_SMALL   (38)
#define LOWER_BOUNDARY_FOR_MEDIUM  (39)
#define UPPER_BOUNDARY_FOR_MEDIUM  (41)
#define LOWER_BOUNDARY_FOR_LARGE   (42)
#define SIZE_ZERO                  (0)

void testForSizeZero();
void testForSmall();
void testForMedium();
void testForLarge();

char size(int cms) {
    char sizeName = '\0';
    if((cms != SIZE_ZERO)&&(cms <= UPPER_BOUNDARY_FOR_SMALL)) {
        sizeName = 'S';
    } else if((cms > UPPER_BOUNDARY_FOR_SMALL) && (cms < LOWER_BOUNDARY_FOR_LARGE)) {
        sizeName = 'M';
    } else if(cms >= LOWER_BOUNDARY_FOR_LARGE) {
        sizeName = 'L';
    }
    return sizeName;
}

void testForSizeZero() {
  assert(size(0) == '\0');
}

void testForSmall(){
  assert(size(UPPER_BOUNDARY_FOR_SMALL -1) == 'S');
  assert(size(UPPER_BOUNDARY_FOR_SMALL) == 'S');
  assert(size(UPPER_BOUNDARY_FOR_SMALL+1) == 'M');
}

void testForMedium() {
  assert(size(LOWER_BOUNDARY_FOR_MEDIUM -1) == 'S');
  assert(size(LOWER_BOUNDARY_FOR_MEDIUM) == 'M');
  assert(size(UPPER_BOUNDARY_FOR_MEDIUM) == 'M');
  assert(size(UPPER_BOUNDARY_FOR_MEDIUM +1) == 'L');
}

void testForLarge() {
  assert(size(LOWER_BOUNDARY_FOR_LARGE -1) == 'L');
  assert(size(LOWER_BOUNDARY_FOR_LARGE) == 'L');
  assert(size(LOWER_BOUNDARY_FOR_LARGE +1) == 'L');
}

int main() {
    testForSizeZero();
    testForSmall();
    testForMedium();
    testForLarge();
    std::cout << "All is well\n";
    return 0;
}
