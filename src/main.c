#include <stdio.h>
#include <kv.h>
#include <assert.h>

int main() {
    kv_t *table = kv_init(3);
    printf("%p\n", table);
    printf("%ld\n", table->capacity);

    // Testing
    kv_t *db = kv_init(16);
    assert(db != NULL);
    assert(db->capacity == 16);
    assert(db->count == 0);
}