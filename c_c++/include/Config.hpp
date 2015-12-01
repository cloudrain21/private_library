#ifndef __CRCR_CONFIG_HPP__
#define __CRCR_CONFIG_HPP__

/**
 * \brief namespace : cr(CloudRain21) (my private library)
 *
 * Define portable fixed-size types
 */
namespace cr
{
	/**
	 * All "common" platforms use the same size for char, short and int
	 * (basically there are 3 types for 3 sizes, so no other match is possible),
	 * we can use them without doing any kind of check
	 */

	/*
	 * 8 bits integer types
	 */
    typedef signed   char Int8;
    typedef unsigned char Uint8;

    /*
     * 16 bits integer types
     */
    typedef signed   short Int16;
    typedef unsigned short Uint16;

    /*
     * 32 bits integer types
     */
    typedef signed   int Int32;
    typedef unsigned int Uint32;

    /*
     * 64 bits integer types
     */
    #if defined(_MSC_VER)
        typedef signed   __int64 Int64;
        typedef unsigned __int64 Uint64;
    #else
        typedef signed   long long Int64;
        typedef unsigned long long Uint64;
    #endif

} // namespace cr

#endif // __CRCR_CONFIG_HPP__
