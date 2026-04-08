#include <stdio.h>
#include <kv.h>
#include <assert.h>

int main() {
    kv_t *table = kv_init(1024);
    printf("%p\n", table);
    printf("%ld\n", table->capacity);

    // Testing
    kv_t *db = kv_init(16);
    assert(db != NULL);
    assert(db->capacity == 16);
    assert(db->count == 0);

    kv_put(table, "hehe", "haha");
    kv_put(table, "hehe", "hoho");
    kv_put(table, "lala", "hoho");

    for (int i = 0; i < table->capacity; i++) {
        if (table->entries[i].key){
            printf("[%d] %s: %s\n", i, table->entries[i].key, table->entries[i].value);
        }
    }

    char *val = kv_get(table, "hehe");
    char *val2 = kv_get(table, "lala");
    char *val3 = kv_get(table, "this doesn't exist");

    printf("%s %s %s\n", val, val2, val3);
}
