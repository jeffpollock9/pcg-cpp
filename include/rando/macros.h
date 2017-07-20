#ifndef RANDO_MACROS_H
#define RANDO_MACROS_H

// clang-format off

#ifdef __GNUC__
    #define RANDO_NOINLINE __attribute__((noinline))
    #define RANDO_ALWAYS_INLINE __attribute__((always_inline))
#else
    #define RANDO_NOINLINE
    #define RANDO_ALWAYS_INLINE
#endif

#ifndef RANDO_LITTLE_ENDIAN
    #if defined(__BYTE_ORDER__)
        #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            #define RANDO_LITTLE_ENDIAN 1
        #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
            #define RANDO_LITTLE_ENDIAN 0
        #else
            #error __BYTE_ORDER__ does not match a standard endian, pick a side
        #endif
    #elif __LITTLE_ENDIAN__ || _LITTLE_ENDIAN
        #define RANDO_LITTLE_ENDIAN 1
    #elif __BIG_ENDIAN__ || _BIG_ENDIAN
        #define RANDO_LITTLE_ENDIAN 0
    #elif __x86_64 || __x86_64__ || __i386 || __i386__
        #define RANDO_LITTLE_ENDIAN 1
    #elif __powerpc__ || __POWERPC__ || __ppc__ || __PPC__ \
          || __m68k__ || __mc68000__
        #define RANDO_LITTLE_ENDIAN 0
    #else
        #error Unable to determine target endianness
    #endif
#endif

// clang-format on

#endif /* RANDO_MACROS_H */
