-include .env

.PHONY: lint
lint:
	arduino-lint Blnk-Kai/

.PHONY: core/install
core/install:
	arduino-cli core install $(ARDUINO_CORE)

.PHONY: build
build: core/install
	arduino-cli compile --fqbn $(ARDUINO_FQBN) --output-dir bin/ Blnk-Kai/Blnk-Kai.ino

.PHONY: upload
upload:
	arduino-cli upload -p $(ARDUINO_PORT) --fqbn $(ARDUINO_FQBN) --input-dir bin/ Blnk-Kai/Blnk-Kai.ino
