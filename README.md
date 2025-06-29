# PlayStation 2 Hello World Homebrew

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![PS2 Homebrew](https://img.shields.io/badge/PS2-Homebrew-blue.svg)](https://github.com/ps2dev)

A simple "Hello World" homebrew application for PlayStation 2 using PS2SDK and gsKit.

## 🎮 Features

- **Graphics Version**: 2D graphics with animated elements using gsKit
- **Console Version**: Text-based output for debugging
- **Cross-platform**: Works on real PS2 hardware and PCSX2 emulator
- **Well-documented**: Comprehensive build and usage instructions

## Prerequisites

- PS2SDK installed at `/usr/local/ps2dev/ps2sdk`
- gsKit installed at `/usr/local/ps2dev/gsKit`
- PlayStation 2 console or PCSX2 emulator
- Method to run homebrew on PS2 (FreeMCBoot, SwapMagic, etc.)

## Project Structure

- `main.c` - Graphics-based Hello World with colored rectangles and animations
- `Makefile` - Build configuration
- `iso_create.sh` - Script to create PS2 ISO from built ELF file

## Building

### Build the ELF
```bash
make
```

### Create ISO (Optional)
```bash
./iso_create.sh
```

### Clean Build Files
```bash
make clean
```

## Output Files

- `hello_world.elf` - Graphics version executable (~1.4MB)
- `PS2_HELLO_WORLD.iso` - Bootable PS2 ISO (created by `iso_create.sh`)

## Features

- 2D graphics using gsKit
- Animated "Hello World" text display
- Colored graphics elements and animations
- Frame counter with console output
- Compatible with both PS2 hardware and PCSX2 emulator

## Running on PS2

1. Copy the `.elf` file to a USB drive or memory card, or burn the `.iso` to a DVD
2. Use a homebrew launcher (like uLaunchELF) to run the ELF file, or boot the ISO directly
3. The application will display animated graphics on screen

## Running on PCSX2

1. Load the `.elf` file or `.iso` directly in PCSX2
2. The application will display full-screen graphics
3. Enable console output in PCSX2 to see debug messages

## Troubleshooting

- Ensure PS2SDK is properly installed at `/usr/local/ps2dev/ps2sdk`
- Ensure gsKit is properly installed at `/usr/local/ps2dev/gsKit`
- Check that all PS2SDK environment variables are set
- Verify your PS2 can run homebrew applications
- If build fails, check that PS2SDK is properly installed and configured

## Technical Details

- Uses gsKit and dmaKit for 2D graphics
- Runs in infinite loop (standard for PS2 homebrew)
- Renders at ~60fps with vsync
- Press Reset button on PS2 to exit application

## Development Notes

- Built with PS2SDK's EE (Emotion Engine) toolchain
- Uses MIPS R5900 assembly optimizations
- Compatible with both fat PS2 and slim PS2 models
- Can be run from memory card, USB, or network

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. When contributing:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- [PS2Dev](https://github.com/ps2dev) community for PS2SDK and tools
- gsKit developers for the graphics library
- PlayStation 2 homebrew community

## 📚 Resources

For more advanced homebrew development, refer to:
- PS2SDK documentation in `/usr/local/ps2dev/ps2sdk/doc/`
- gsKit examples and documentation
- [PS2Dev community forums](https://ps2-home.com/) and resources
- PlayStation 2 Linux development guides

## ⭐ Support

If you found this project helpful, please consider giving it a star on GitHub!
