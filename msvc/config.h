/* config.h. CI/Repo-local config for MSVC. */

#ifndef _MSC_VER
#warning "msvc/config.h shouldn't be included for your development environment."
#error "Please make sure the msvc/ directory is removed from your build path."
#endif

#if defined(_PREFAST_)
#pragma warning(disable:28719)
#endif
#if defined(_MSC_VER)
#pragma warning(disable:6258)
#pragma warning(disable:6387)
#endif

/*
 * CI build policy:
 * - x64 only
 * - libusbK payload only
 * - no WinUSB payload embedding
 * - no libusb0 payload embedding
 *
 * Expected repo-local payload layout:
 *   vendor/libusbK/
 *     sys/amd64/libusbK.sys
 *     sys/amd64/WdfCoInstaller01009.dll
 *     dll/amd64/libusbK.dll
 *     dll/amd64/libusb0.dll
 *     dll/x86/libusbK.dll
 *     dll/x86/libusb0.dll
 */

/* No WinUSB payload in CI build */
/* #define WDK_DIR "..." */

/* No libusb0 payload in CI build */
/* #define LIBUSB0_DIR "..." */

/* libusbK package here contains WdfCoInstaller01009.dll */
#define WDF_VER 01009

#ifndef LIBUSBK_DIR
#define LIBUSBK_DIR "D:/a/libwdi-statis/libwdi-statis/vendor/libusbK"
#endif

/* Optional user payload dir */
#ifndef USER_DIR
/* #define USER_DIR "C:/signed-driver" */
#endif

/* 32 bit support */
/* #define OPT_M32 */

/* 64 bit support */
#define OPT_M64

/* ARM64 support */
/* #define OPT_ARM */

/* Debug message logging */
/* #define ENABLE_DEBUG_LOGGING */

/* Debug message logging (toggable) */
#define INCLUDE_DEBUG_LOGGING

/* Message logging */
#define ENABLE_LOGGING 1
