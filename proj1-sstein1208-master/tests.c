#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashmap.h"

void addTestSimple()
{
        struct HashMap* playlist = hm_create('A');
        
        printf("addTestSimple\n-------------\n");
        int retval = hm_put(playlist, "Never Gonna Give You Up", "Rick Astley", 215);
        assert(retval == 0);
        printf("Should print playlist with 1 song\n");
        printHashMap(playlist);
        hm_destroy(playlist);
        printf("\n-------------\n\n");
}

int main()
{
        // Simple add element test
        addTestSimple();

        printf("\n\nALL TESTS PASSED\n");    
        return 0;
}
