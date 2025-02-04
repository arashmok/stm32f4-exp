# Setting Up OpenOCD and GDB Server on Ubuntu for STM32F4

This guide walks through setting up OpenOCD on an Ubuntu-based system, such as a Raspberry Pi running Ubuntu, and configuring it to act as a GDB server for debugging an STM32F4 microcontroller.

## Table of Contents
- [Step 1: Prepare the Ubuntu System](#step-1-prepare-the-ubuntu-system)
- [Step 2: Install OpenOCD](#step-2-install-openocd)
- [Step 3: Configure OpenOCD for the STM32F4](#step-3-configure-openocd-for-the-stm32f4)
- [Step 4: Set Up the GDB Server](#step-4-set-up-the-gdb-server)
- [Step 5: Create a Systemd Service for OpenOCD](#step-5-create-a-systemd-service-for-openocd)
- [Conclusion](#conclusion)

## Step 1: Prepare the Ubuntu System

### Update and Upgrade the System
To ensure your system has the latest software updates, run the following commands:

```bash
sudo apt update && sudo apt upgrade -y
```

### Install Required Dependencies
Install essential tools and libraries needed for OpenOCD and GDB:

```bash
sudo apt install build-essential cmake libusb-1.0-0-dev libncurses5-dev -y
```

## Step 2: Install OpenOCD

### Install OpenOCD
OpenOCD is an open-source tool used for debugging embedded systems. Install it with:

```bash
sudo apt install openocd -y
```

### Verify OpenOCD Installation
To check the installed version:

```bash
openocd --version
```

### Check ST-LINK USB Connection
Ensure your STM32F4 board is connected to the system via USB, then verify with:

```bash
lsusb
```

You should see an entry for ST-LINK in the output.

## Step 3: Configure OpenOCD for the STM32F4

### Locate the OpenOCD Configuration File
OpenOCD provides a pre-configured script for the STM32F4 Discovery board, found at:

```plaintext
/usr/share/openocd/scripts/board/stm32f4discovery.cfg
```

### Test OpenOCD Connection
To check if OpenOCD can communicate with your board, run:

```bash
openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg
```

If successful, OpenOCD will display messages confirming the connection.

## Step 4: Set Up the GDB Server

### Start OpenOCD as a GDB Server
Run OpenOCD to act as a GDB server:

```bash
openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg
```

By default, OpenOCD starts a GDB server on port **3333**. The output should confirm:

```plaintext
Info : Listening on port 3333 for gdb connections
```

## Step 5: Create a Systemd Service for OpenOCD

To ensure OpenOCD starts automatically at boot, set up a systemd service.

### Create a Systemd Service File
Create and open a new service file:

```bash
sudo nano /etc/systemd/system/openocd.service
```

### Add the Following Content:

```ini
[Unit]
Description=OpenOCD Debug Server
After=network.target

[Service]
ExecStart=/usr/bin/openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg -c "bindto 0.0.0.0"
Restart=always
User=root
WorkingDirectory=/usr/share/openocd
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
```

### Enable and Start the Service
Run the following commands to apply the changes:

```bash
# Reload systemd to recognize the new service
sudo systemctl daemon-reload

# Enable the service to start on boot
sudo systemctl enable openocd.service

# Start the service immediately
sudo systemctl start openocd.service

# Check the service status
sudo systemctl status openocd.service
```

If everything is set up correctly, OpenOCD will automatically start at boot.

### (Optional) Adjust Firewall Settings
If you need to access OpenOCD remotely, allow incoming connections:

```bash
sudo ufw allow 3333/tcp
sudo ufw allow 4444/tcp
sudo ufw allow 6666/tcp
```

## Conclusion
By following these steps, you will have a fully functional debugging environment for the STM32F4 on an Ubuntu system, with OpenOCD running as a systemd service for automatic startup.

## License
This guide is open-source and distributed under the MIT License.

## Contributing
If you'd like to improve this guide, feel free to submit a pull request!

---

**Maintainer:** armok

For any questions or feedback, open an issue in the GitHub repository.