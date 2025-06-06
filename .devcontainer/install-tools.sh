#!/bin/bash
set -e

echo "Starting post-create script..."

echo "Updating package lists and installing curl..."
sudo apt-get update && sudo apt-get install -y curl

echo "Installing arduino-cli v1.2.2 (Latest)..."
curl -L -o /tmp/arduino-cli.tar.gz "https://github.com/arduino/arduino-cli/releases/download/v1.2.2/arduino-cli_1.2.2_Linux_64bit.tar.gz"
sudo tar -xzf /tmp/arduino-cli.tar.gz -C /usr/local/bin arduino-cli
chmod +x /usr/local/bin/arduino-cli
rm /tmp/arduino-cli.tar.gz

echo "Installing arduino-lint v1.3.0 (Latest)..."
curl -L -o /tmp/arduino-lint.tar.gz "https://github.com/arduino/arduino-lint/releases/download/1.3.0/arduino-lint_1.3.0_Linux_64bit.tar.gz"
sudo tar -xzf /tmp/arduino-lint.tar.gz -C /usr/local/bin arduino-lint
chmod +x /usr/local/bin/arduino-lint
rm /tmp/arduino-lint.tar.gz

echo "Cleaning up apt cache..."
sudo apt-get clean && sudo rm -rf /var/lib/apt/lists/*

echo "Post-create script finished successfully."
