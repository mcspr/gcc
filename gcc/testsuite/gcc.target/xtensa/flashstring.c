/* { dg-do compile */
/* { dg-options "-fdata-sections -mflash-string-section=.test.section" } */

const char a[] __attribute__((__section__(".test.section.123"))) = "aaaa123bbbb";

const char b[] __attribute__((__section__(".test"))) = "bbbbccccdddd";

char c[] = "cccc";

/* { dg-final { scan-assembler ".section        .test.section.123,\"aMS\",@progbits" } } */
/* { dg-final { scan-assembler ".section        .test,\"a\"" } } */
/* { dg-final { scan-assembler ".section        .data.c,\"aw\"" } } */
