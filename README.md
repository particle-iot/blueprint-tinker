# Tinker App

## Introduction

The **Tinker App** provides basic functionality to interact with a Particle device's digital and analog pins. Users can read and write to pins, control LEDs, and monitor sensors through Particle Cloud functions. It includes functions for digital and analog read/write capabilities, making it an ideal starting point for learning how to interact with Particle hardware.

## Hardware Dependencies

*   **Particle Device (e.g., Photon, Argon, Boron):** [Particle Development Boards](https://store.particle.io/collections/all-products?filter.p.product_type=Development%20Boards)

## Functionality

### Available Functions

The Tinker app exposes the following functions for use through the Particle Cloud:

*   **digitalread**: Reads the digital state (HIGH or LOW) of a specified pin.

*   **Parameters:** `pin` - _String_, the name of the pin to read from.
*   **Returns:** Integer, the pin state (0 or 1) or -1 on failure.

*   **digitalwrite**: Sets the specified pin to HIGH or LOW.

*   **Parameters:** `command` - _String_, pin name and state (e.g., "D0, HIGH").
*   **Returns:** Integer, 1 on success or a negative number on failure.

*   **analogread**: Reads the analog value of a specified pin.

*   **Parameters:** `pin` - _String_, the name of the pin to read from.
*   **Returns:** Integer, the analog value (0-4095) or -1 on failure.

*   **analogwrite**: Sets the analog value (PWM) of a specified pin.

*   **Parameters:** `command` - _String_, pin name and PWM value (e.g., "D0, 128").
*   **Returns:** Integer, 1 on success or a negative number on failure.

## Configuration

The following settings are used for this application:

*   **System Thread:** ENABLED
*   **System Mode:** AUTOMATIC

## Contributors

*   **Particle Industries, Inc.**: Original Author [GitHub](https://github.com/particle-iot)

