-include .env

PROJECT_NAME := Blink-KAI

.PHONY: lint
lint:
	arduino-lint $(PROJECT_NAME)/

.PHONY: core/install
core/install:
	arduino-cli core install $(ARDUINO_CORE)

.PHONY: build
build: core/install
	arduino-cli compile --fqbn $(ARDUINO_FQBN) --output-dir bin/ $(PROJECT_NAME)/$(PROJECT_NAME).ino

.PHONY: upload
upload:
	arduino-cli upload -p $(ARDUINO_PORT) --fqbn $(ARDUINO_FQBN) --input-dir bin/ $(PROJECT_NAME)/$(PROJECT_NAME).ino
