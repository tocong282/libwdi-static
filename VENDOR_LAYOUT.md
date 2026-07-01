# libwdi CI vendor layout

This repo-local `libwdi` build is configured for:
- x64 only
- libusbK payload only
- no WinUSB payload embedding
- no libusb0 payload embedding

## Required files

Place these files in repo before running GitHub Actions:

```text
vendor/libusbK/sys/amd64/libusbK.sys
vendor/libusbK/dll/amd64/libusbK.dll
vendor/libusbK/dll/amd64/libusb0.dll
vendor/libusbK/dll/x86/libusbK.dll
vendor/libusbK/dll/x86/libusb0.dll
```

## Notes

- `msvc/config.h` already points `LIBUSBK_DIR` to the GitHub Actions workspace path.
- Workflow `build-libwdi.yml` fails early if any payload file is missing.
- `embedder` is built as Win32.
- `installer_x64` and `libwdi_static` are built as x64.
- `installer_x86` and `installer_arm64` are intentionally removed from the CI build path.

## Artifact output

Expected artifact name:
- `libwdi-x64-static`

Expected files inside artifact:

```text
include/libwdi.h
lib/x64/libwdi.lib
installer_x64.exe   (optional but expected)
embedded.h          (optional diagnostic)
```

## After download
Put artifact files in app repo like:

```text
production/third_party/libwdi-prebuilt/include/libwdi.h
production/third_party/libwdi-prebuilt/lib/x64/libwdi.lib
```

Then patch app build with:
- include path to `libwdi-prebuilt/include`
- link `libwdi-prebuilt/lib/x64/libwdi.lib`
- compile define `HAVE_LIBWDI`
