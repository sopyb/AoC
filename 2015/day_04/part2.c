#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

// solution time: 0:37.02 (mm:ss.ms)
int main() {
    // open input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    char hash[100];

    fscanf(fp, "%99s\n", hash);

    // close input.in
    fclose(fp);

    int i = 0;
    while (1) {
        // create a string with the number
        char str[100];
        sprintf(str, "%d", i);

        // create a string with the hash
        char hash_str[100];
        sprintf(hash_str, "%s%s", hash, str);

        // calculate the hash
        unsigned char reshash[MD5_DIGEST_LENGTH];
        MD5((unsigned char*) hash_str, strlen(hash_str), reshash);

        // copy the first 6 bytes of reshash to a new array as hex
        char reshash_hex[100];
        for (int j = 0; j < 6; j++) {
            sprintf(reshash_hex + (j * 2), "%02x", reshash[j]);
        }

        // check if the first 6 bytes are 0
        int j;
        for (j = 0; j < 6; j++) {
            if (reshash_hex[j] != '0') break;
        }

        // if it does, break
        if (j == 6) break;

        // otherwise, increment i
        i++;
    }

    // print answer
    printf("%d\n", i);

    return 0;
}
