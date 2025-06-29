# PlayStation 2 Hello World Homebrew

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
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
- `simple_main.c` - Console-based Hello World with text output
- `Makefile` - Build configuration for graphics version
- `Makefile.simple` - Build configuration for console version
- `build.sh` - Automated build script for both versions

## Building

### Quick Build (Recommended)
```bash
./build.sh
```

### Manual Build

#### Console Version
```bash
make -f Makefile.simple
```

#### Graphics Version
```bash
make
```

#### Clean Build Files
```bash
make clean
# or for simple version
make -f Makefile.simple clean
```

## Output Files

- `hello_world_simple.elf` - Console version executable (~1.3MB)
- `hello_world.elf` - Graphics version executable (~1.4MB)

## Features

### Console Version (`hello_world_simple.elf`)
- Text-based "Hello World" message
- Heartbeat counter output
- Minimal resource usage
- Compatible with all PS2 systems

### Graphics Version (`hello_world.elf`)
- 2D graphics using gsKit
- Blue rectangle with white border
- Colored corner indicators (red and green squares)
- Animated white rectangle that moves across the screen
- Frame counter with console output

## Running on PS2

1. Copy the `.elf` file to a USB drive or memory card
2. Use a homebrew launcher (like uLaunchELF) to run the file
3. The console version will display text output in the system console
4. The graphics version will show animated graphics on screen

## Running on PCSX2

1. Load the `.elf` file directly in PCSX2
2. The console version output can be viewed in the PCSX2 console window
3. The graphics version will display full-screen graphics
4. Enable console output in PCSX2 to see debug messages

## Troubleshooting

- Ensure PS2SDK is properly installed at `/usr/local/ps2dev/ps2sdk`
- Ensure gsKit is properly installed at `/usr/local/ps2dev/gsKit`
- Check that all PS2SDK environment variables are set
- Verify your PS2 can run homebrew applications
- For graphics issues, try the console version first
- If build fails, run `./build.sh` for detailed error output

## Technical Details

- The console version uses `printf()` for debug output
- The graphics version uses gsKit and dmaKit for 2D graphics
- Both versions run in infinite loops (standard for PS2 homebrew)
- Graphics version renders at ~60fps with vsync
- Press Reset button on PS2 to exit applications

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

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

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
- [Awesome PS2](https://github.com/terremoth/awesome-playstation-2) - Curated list of PS2 resources

## ⭐ Support

If you found this project helpful, please consider giving it a star on GitHub!