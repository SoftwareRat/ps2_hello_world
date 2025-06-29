EE_BIN = hello_world.elf
EE_OBJS = main.o

EE_LIBS = -lgskit -ldmakit -lpatches
EE_INCS = -I$(GSKIT)/include

# PS2SDK and gsKit paths
PS2SDK = /usr/local/ps2dev/ps2sdk
GSKIT = /usr/local/ps2dev/gsKit

# Compiler settings
EE_CFLAGS = -D_EE -O2 -G0 -Wall $(EE_INCS)
EE_CXXFLAGS = -D_EE -O2 -G0 -Wall $(EE_INCS)
EE_LDFLAGS = -L$(GSKIT)/lib

# Include PS2SDK Makefile rules
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal

# Build targets
all: $(EE_BIN)

clean:
	rm -f *.elf *.o *.a

rebuild: clean all

install: $(EE_BIN)
	@echo "Copy $(EE_BIN) to your PS2 memory card or USB device"

.PHONY: all clean rebuild install
