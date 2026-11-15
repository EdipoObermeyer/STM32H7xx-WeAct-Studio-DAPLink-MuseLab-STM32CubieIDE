# STM32H743VIT6 (WeAct Studio) + MuseLab DAPLink — Pure CMSIS Bare-Metal Template

A lightweight, ready-to-use **pure CMSIS (Bare-Metal)** base project for **STM32CubeIDE**, pre-configured to flash and debug the **WeAct Studio STM32H743VIT6** core board using a **MuseLab DAPLink** (CMSIS-DAP) programmer via SWD and OpenOCD.

No HAL drivers, no CubeMX (`.ioc`) overhead—just clean register-level setup ready to go.


<img width="1600" height="739" alt="AdobeExpressPhotos_81e7de7d7e4a41b79e5546ece34b6ef0_CopyEdited" src="https://github.com/user-attachments/assets/adad4c36-ede9-431a-895f-cc6bca10fe6a" />


---

## 📋 Overview

Setting up third-party development boards with CMSIS-DAP debuggers inside STM32CubeIDE often requires custom OpenOCD scripts and target configuration. This repository provides a clean, working bare-metal baseline so you can clone the project and start writing your register-level firmware immediately.

### Key Features
* **100% Pure CMSIS / Bare-Metal:** Lightweight structure with direct register access (no HAL or `.ioc` generated code).
* **Custom OpenOCD Script (`daplink_h7.cfg`):** Properly handles CMSIS-DAP interface initialization and STM32H7 target reset/flashing sequences.
* **Built-in Blink & Debug Test (`PE3`):** Includes a register-level example that blinks the onboard blue LED (`PE3`) and increments a `global_variable` counter so you can test SWD flashing and **Live Expressions** right away.
* **Verified Hardware Pinout:** Tested with the WeAct Studio STM32H743VIT6 and MuseLab DAPLink.

---

## 🛠️ Hardware Requirements

* **Target Board:** WeAct Studio STM32H743VIT6 Core Board
* **Debugger / Programmer:** MuseLab DAPLink (CMSIS-DAP)
* **Wires:** 4x Female-to-Female jumper wires

---

## 🔌 Hardware Wiring (SWD)

Connect the **MuseLab DAPLink** to the SWD header on the **WeAct STM32H743** board as follows:

| MuseLab DAPLink |  WeAct STM32H743  |            Description           |
| :-------------- | :---------------- | :------------------------------- |
| **SWCLK**       | **PA14** (SWCLK)  |        Serial Wire Clock         |
| **SWDIO**       | **PA13** (SWDIO)  |       Serial Wire Data I/O       |
| **GND**         | **GND**           |           Common Ground          |
| **3.3V**        | **3.3V**          | Target Power / Voltage Reference |

> **Note:** Ensure the `BOOT0` pin on the WeAct board is left **LOW** (default state) for normal SWD flashing and execution from Flash memory.

---

## 💡 Included Example (`main.c`)

The project comes with a minimal register-level test running on the default 64 MHz HSI clock:
1. Enables the **GPIOE** clock on the `AHB4` bus (`RCC->AHB4ENR`) with a dummy read for bus synchronization.
2. Configures pin **PE3** (onboard blue LED) as a general-purpose Push-Pull output (`GPIOE->MODER`).
3. Toggles **PE3** inside an infinite loop while incrementing `global_variable`—ideal for verifying real-time variable inspection via SWD in STM32CubeIDE's **Live Expressions** tab.

---
## 🚀 Getting Started

1. **Clone the repository:**
   ```bash
   git clone https://github.com
   ```

2. **Import into STM32CubeIDE:**
   * Open **STM32CubeIDE**.
   * Go to `File` > `Open Projects from File System...`
   * Select the cloned project folder and click **Finish**.

3. **Verify Debug Configuration (`daplink_h7.cfg`):**
   * Right-click the project > `Debug As` > `Debug Configurations...`
   * Under **STM32 C/C++ Application**, select the project debug profile.
   * Go to the **Debugger** tab and confirm that **OpenOCD** is configured to use the local script `daplink_h7.cfg`.

4. **Build and Flash:**
   * Connect the DAPLink to your PC via USB.
   * Click the **Build** icon (hammer) to compile the code.
   * Click the **Debug** icon (bug) or **Run** icon (play) to flash the firmware onto the STM32H743.
   * Watch the onboard blue LED (**PE3**) blink, and add `global_variable` to **Live Expressions** to verify live SWD debugging!

---

## 📁 Repository Structure

```text
├── Chip_Headers/CMSIS/       # ARM CMSIS core and STM32H7xx device header/startup files
├── Src/                      # Bare-metal application source files (main.c, etc.)
├── Inc/                      # Application header files
├── Startup/                  # Startup assembly file (startup_stm32h743vitx.s)
├── STM32H743VITX_FLASH.ld    # Linker script
├── daplink_h7.cfg            # Custom OpenOCD configuration script for DAPLink + STM32H7
└── README.md                 # Project documentation
```
---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the issues page or submit a pull request if you have improvements to the OpenOCD configuration or CMSIS base setup.

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
