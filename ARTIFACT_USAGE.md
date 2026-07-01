# libwdi GitHub Actions artifact usage

## Goal
Build `libwdi` static on GitHub Actions and import only the artifact into app repo.

## Workflow file
- `.github/workflows/build-libwdi.yml`

## Expected artifact
Artifact name:
- `libwdi-x64-static`

Artifact contents:
- `include/libwdi.h`
- `lib/x64/libwdi.lib`
- optional `installer_x64.exe`
- optional `embedded.h`

## After download
Place files in app repo like:

```text
production/third_party/libwdi-prebuilt/
  include/libwdi.h
  lib/x64/libwdi.lib
```

## Then patch app build
- add include path to `libwdi-prebuilt/include`
- add library path/file `libwdi-prebuilt/lib/x64/libwdi.lib`
- add compile define `HAVE_LIBWDI`

## Notes
This workflow patches `embedder.vcxproj` and `libwdi_static.vcxproj` during CI to support x64-only build and drop unneeded x86/arm64 installer references.
