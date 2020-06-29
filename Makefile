ergodox_ez_neo-oberien.hex: build/qmk_firmware/.build/ergodox_ez_neo-oberien.hex
	mv build/qmk_firmware/.build/ergodox_ez_neo-oberien.hex .

build/qmk_firmware/.build/ergodox_ez_neo-oberien.hex: build/qmk_firmware/keyboards/ergodox_ez/keymaps/neo-oberien
	make -C build/qmk_firmware ergodox_ez:neo-oberien

build/qmk_firmware/keyboards/ergodox_ez/keymaps/neo-oberien: build/qmk_firmware $(shell find src -type f)
	cp -Tr src build/qmk_firmware/keyboards/ergodox_ez/keymaps/neo-oberien

build/qmk_firmware: build
	git clone --recurse-submodules --depth 1 https://github.com/oberien/qmk_firmware/ build/qmk_firmware
	# not needed on own fork
	#cd build/qmk_firmware && git apply ../../2710.diff
	sudo pacman -S --needed base-devel gcc unzip wget zip avr-gcc avr-binutils avr-libc dfu-util arm-none-eabi-gcc arm-none-eabi-binutils arm-none-eabi-newlib git dfu-programmer dfu-util
	pikaur -S --needed zsa-wally
	sh build/qmk_firmware/util/qmk_install.sh

build:
	mkdir build

clean:
	rm -rf .build build ergodox_ez_neo-oberien.hex
