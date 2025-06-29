#!/bin/bash

echo "Creating PS2 ISO with custom game ID..."

# Configuration
ISO_NAME="PS2_HELLO_WORLD.iso"
ISO_DIR="custom_iso"
CUSTOM_ID="HELO_001.01"  # Your custom PlayStation format ID
# HELO = Hello World (4 chars)
# 001 = Version 1 (3 digits)
# 01 = Region/revision (2 digits)

# Check if ELF exists
if [ ! -f "hello_world.elf" ]; then
    echo "Error: hello_world.elf not found"
    echo "Run 'make' first to build the project"
    exit 1
fi

# Check for genisoimage/mkisofs
if command -v genisoimage &> /dev/null; then
    MKISO_CMD="genisoimage"
elif command -v mkisofs &> /dev/null; then
    MKISO_CMD="mkisofs"
else
    echo "Error: genisoimage or mkisofs required"
    exit 1
fi

# Clean up
rm -rf "$ISO_DIR"
rm -f "$ISO_NAME"
mkdir -p "$ISO_DIR"

echo "Using custom PlayStation game ID: $CUSTOM_ID"

# Copy ELF with your custom PlayStation game ID
cp hello_world.elf "$ISO_DIR/$CUSTOM_ID"

# Create SYSTEM.CNF pointing to your custom ID
cat > "$ISO_DIR/SYSTEM.CNF" << EOF
BOOT2 = cdrom0:\\$CUSTOM_ID;1
VER = 1.00
VMODE = NTSC
EOF

echo "Building ISO.."

# Create ISO with minimal parameters (this format worked!)
$MKISO_CMD \
    -o "$ISO_NAME" \
    -V "PS2HELLO" \
    -iso-level 1 \
    "$ISO_DIR"

# Verify creation
if [ $? -eq 0 ] && [ -f "$ISO_NAME" ]; then
    SIZE=$(stat -f%z "$ISO_NAME" 2>/dev/null || stat -c%s "$ISO_NAME" 2>/dev/null)
    SIZE_KB=$((SIZE / 1024))

    echo "✓ Custom ID PS2 ISO created successfully!"
    echo "========================================"
    echo "File: $ISO_NAME"
    echo "Size: ${SIZE_KB}KB"
else
    echo "✗ Failed to create ISO"
    exit 1
fi

# Clean up
rm -rf "$ISO_DIR"

echo ""
echo "Success!"
