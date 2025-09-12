# BNO055_Complementary_Filter
# IMU Orientation Estimation with BNO055

This repository contains Arduino sketches for experimenting with the **Adafruit BNO055 IMU** to estimate roll and pitch orientation.  
The project starts with raw sensor readings and gradually moves toward more stable orientation estimates using a **complementary filter**.

---

## Project Steps

1. **Accelerometer only**  
   - Calculate roll and pitch directly from raw accelerometer values.  
   - Works but sensitive to noise and vibrations.

2. **Gyroscope only**  
   - Integrate angular velocity from the gyroscope to estimate orientation.  
   - Smoother response but suffers from drift over time.

3. **Complementary filter**  
   - Combine accelerometer (long-term stability) and gyroscope (short-term accuracy).  
   - Produces stable roll and pitch values with reduced drift and noise.

---

## Workflow

```mermaid
flowchart LR
    A[Accelerometer] --> C[Complementary Filter]
    B[Gyroscope] --> C[Complementary Filter]
    C --> D[Roll & Pitch Output]
Features
Interfaces with BNO055 using the Adafruit library over I²C.

Demonstrates the difference between accelerometer-only, gyroscope-only, and fused orientation.

Outputs roll and pitch angles in real time via Serial Monitor.

Provides step-by-step learning for sensor fusion basics.

Applications
Understanding IMU sensor fundamentals.

Building orientation estimation for robotics or balance projects.

Educational reference for complementary filter implementation.

Hardware
Adafruit BNO055 IMU

Arduino Uno / Nano (tested)

I²C connection (SDA, SCL)
