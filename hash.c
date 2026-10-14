#include "hash.h"
#include <stdlib.h>
#include <stddef.h>


unsigned char* SSHA(const unsigned char* msg, size_t length) {
    unsigned char A = 56;
    unsigned char B = 99;
    unsigned char C = 102;
    unsigned char D = 67;
    unsigned char E = 76;

    for (size_t i = 0; i < length; i++) {
        for (int round = 0; round < 8; round++) {

            unsigned char oldA = A;
            unsigned char oldB = B;
            unsigned char oldC = C;
            unsigned char oldD = D;
            unsigned char oldE = E;

            A = oldE;
            B = oldA;
            C = (unsigned char)(oldE + (oldA >> 2));
            D = (unsigned char)((oldA >> 2) ^ (oldB >> 1));
            E = (unsigned char)(
                ((oldB & oldC) | (oldC & oldD)) + msg[i]
                );
        }
    }

    unsigned char* digest =
        (unsigned char*)malloc(DIGEST_SIZE * sizeof(unsigned char));

    if (digest == NULL) {
        return NULL;
    }

    digest[0] = A;
    digest[1] = B;
    digest[2] = C;
    digest[3] = D;
    digest[4] = E;

    return digest;
}

int digest_equal(struct Digest digest1, struct Digest digest2) {
    return ((digest1.hash0 == digest2.hash0) &&
        (digest1.hash1 == digest2.hash1) &&
        (digest1.hash2 == digest2.hash2) &&
        (digest1.hash3 == digest2.hash3) &&
        (digest1.hash4 == digest2.hash4));
}

void printDigest(struct Digest digest) {
    printf("%d %d %d %d %d\n", digest.hash0, digest.hash1, digest.hash2, digest.hash3, digest.hash4);
}

unsigned char* SSHA2(const unsigned char* msg, size_t length)
{
    unsigned char A = 56, B = 99, C = 102, D = 67, E = 76;
    unsigned char nA, nB, nC, nD, nE;
    size_t i;
    int round;

    unsigned char* digest = (unsigned char*)malloc(5);
    if (digest == NULL) {
        return NULL;
    }

    for (i = 0; i < length; i++) {
        for (round = 0; round < 8; round++) {
            unsigned char shA2 = (unsigned char)(A >> 2);   /* ">>2" box */
            unsigned char shB1 = (unsigned char)(B >> 1);   /* ">>1" box */
            unsigned char andBC = (unsigned char)(B & C);   /* left "&"  */
            unsigned char andDC = (unsigned char)(D & C);   /* right "&" */
            unsigned char orBox = (unsigned char)(andBC | andDC); /* "|" box */

            nA = E;
            nB = A;
            nC = (unsigned char)(shA2 + E);
            nD = (unsigned char)(shA2 ^ shB1);
            nE = (unsigned char)(msg[i] + shB1 + orBox);

            A = nA;
            B = nB;
            C = nC;
            D = nD;
            E = nE;
        }
    }

    digest[0] = A;
    digest[1] = B;
    digest[2] = C;
    digest[3] = D;
    digest[4] = E;

    return digest;
}