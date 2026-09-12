# Moonlight Qt 6.1.0 — BC-250 edition 1 (experimental)

First experimental release of this unofficial BC-250 fork.

- Adds **Auto / 4 / 8 / 12 / 16 CPU decoder threads** in Advanced Settings, with English and Polish text. Auto uses up to 8; all choices are capped at the logical CPUs visible to the system. Reconnect to apply a change.
- Uses the effective count for FFmpeg CPU decoding and the requested slices per frame. Selecting 16 with 12 available uses 12; the setting does not unlock the CPU.
- Suppresses the startup popup about missing hardware decoding while retaining detection, fallback and diagnostic logs.
- Includes the upstream FFmpeg compatibility fixes used by Arch's Moonlight 6.1.0-7 package.

BC-250 testing showed improvements, but results depended substantially on the game, scene, bitrate and stream settings. **Test under your own conditions. More threads are not always faster, and sustained 4K120 is not guaranteed.** No controlled percentage speedup is claimed.

Actual tester log excerpt:

```text
Requesting 16 slices per frame for software decoding
BC-250: configuring 16 CPU decoder threads for h264
```

This confirms the client configuration, not the slice count actually emitted by the host. The CPU still decodes video; this release does not enable BC-250 hardware decoding.

Application source: [`f128a1136d4cbad6bc6b47366b5ca9acf77d9de2`](https://github.com/grykom/moonlight-qt-bc250/commit/f128a1136d4cbad6bc6b47366b5ca9acf77d9de2). Packaging and documentation are included with this release.

The `moonlight-qt-bc250` Arch/CachyOS package replaces `moonlight-qt` on confirmation and keeps the `moonlight` command. It depends on system libraries and is not a portable AppImage. See [build, installation and rollback instructions](https://github.com/grykom/moonlight-qt-bc250/blob/bc250/BC250.md#arch-linux--cachyos-package).

BC-250-specific code modifications were implemented by **GPT-6 Astra**. Project direction, hardware testing and measurements: **grykom**. Original Moonlight code and licensing remain credited to the **Moonlight contributors**; FFmpeg fixes are upstream backports.
