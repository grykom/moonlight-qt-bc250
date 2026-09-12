# Moonlight Qt for BC-250

An unofficial, experimental fork of [Moonlight Qt](https://github.com/moonlight-stream/moonlight-qt), based on **6.1.0**, for BC-250 systems using CPU video decoding. Includes the upstream FFmpeg compatibility fixes used by Arch Linux's 6.1.0-7 package.

## What changes

- **Advanced Settings → CPU decoder threads (BC-250): Auto / 4 / 8 / 12 / 16.** Auto uses up to 8 logical CPU threads. The effective count controls FFmpeg software decoding and the requested slices per frame.
- Choices are capped at the CPU threads visible to the system. Selecting 16 with 12 available uses 12; using all 16 requires them to be unlocked and available. This setting does not unlock the CPU.
- The choice is saved and takes effect on the **next connection**. English and Polish UI text is included.
- The startup popup about missing hardware decoding is suppressed. Decoder detection, fallback and diagnostic logs remain available.

This fork does not enable BC-250 hardware video decoding. The CPU decodes the stream; GPU rendering remains available.

## Results and tuning

Local BC-250 testing showed improvements after increasing the decoder thread count, but results varied substantially with the game, scene, bitrate and stream settings. **Test your own games and conditions; more threads are not always faster.** There is no universal speedup or guarantee of sustained 4K120.

Start with Auto or 8, then compare 12 and 16 using H.264, the same moving scene and the same bitrate. Reconnect after each change and compare decoding time, delivered FPS and dropped frames. [Test observations and actual log excerpts](BC250.md#validation-and-observations).

## Install

For Arch Linux / CachyOS, use the [build and installation instructions](BC250.md#arch-linux--cachyos-package). The package is named `moonlight-qt-bc250`, replaces the installed `moonlight-qt` package on confirmation, and launches as `moonlight`.

[Fork releases](https://github.com/grykom/moonlight-qt-bc250/releases) · [Technical details](BC250.md) · [Original Moonlight documentation](README.upstream.md)

## Credits and license

BC-250-specific code modifications were implemented by **GPT-6 Astra**, with project direction, hardware testing and measurements by **grykom**. The FFmpeg compatibility fixes were backported from upstream.

Moonlight and its original code belong to the Moonlight contributors; their notices and the [GPL-3.0 license](LICENSE) are retained. This fork is not an official Moonlight release.
