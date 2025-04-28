/* { dg-do compile */
/* { dg-do compile { target { c || c++11 } } } */
/* { dg-options "-fdata-sections -mflash-string-section-prefix=.test.one -mflash-string-section-prefix=.test.two" } */

const char a[] __attribute__((__section__(".test.one.123"))) = "aaaa123bbbb";
const char b[] __attribute__((__section__(".test.one"))) = "123123123123";
const char c[] __attribute__((__section__(".test.two.123"))) = "oaisjd912j";
const char d[] __attribute__((__section__(".test.two"))) = "aosjdasje";
const char e[] __attribute__((__section__(".test"))) = "bbbbccccdddd";

#ifdef __cplusplus
template <typename T>
struct Foo {
  [[gnu::section(".test.one.template")]]
  const char data[];
};

template <typename T>
const char Foo<T>::data[] = "kad9aue";
#endif

char f[] = "cccc";

/* { dg-final { scan-assembler "\.test\.one*,\"aMS\",@progbits,1" } } */
/* { dg-final { scan-assembler "\.test\.two*,\"aMS\",@progbits,1" } } */
/* { dg-final { scan-assembler "\.test,\"a\"" } } */
/* { dg-final { scan-assembler "\.data\.f,\"aw\"" } } */
