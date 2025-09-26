
# BNO055 Complementary Filter (Roll & Pitch)


This Arduino sketch demonstrates how to estimate **roll** and **pitch** angles using a **complementary filter** with the **BNO055 IMU**.  The complementary filter fuses accelerometer and gyroscope data to provide a stable and smooth orientation estimate. Initially, the angles were calculated separately using the accelerometer and gyroscope to validate their readings, and then the complementary filter was applied to combine both sensors for improved accuracy.

---

## 📌 Description
This project demonstrates three approaches for estimating **roll** and **pitch** using the BNO055 IMU:

- **Accelerometer-only** → Uses raw accelerometer values with trigonometry (simple but noisy).  
- **Gyroscope-only** → Integrates angular velocity from the gyroscope (smooth but drifts).  
- **Complementary Filter** → Combines both sensors to balance stability and accuracy.  

The complementary filter leverages:  
- **Gyroscope** for short-term smoothness.  
- **Accelerometer** for long-term reference.  

Final roll and pitch angles are printed in degrees to the Serial Monitor.


---

## 🛠️ Features
- Sensor fusion using a complementary filter.  
- Adjustable filter coefficient `alpha` (default **0.98**).  
- Outputs angles at ~50 Hz refresh rate.  
- More stable than accelerometer-only or gyroscope-only estimates.  

---

## 📊 Applications
- Balancing robots.  
- Drone/flight controllers.  
- IMU orientation demos.  
- Any system needing **roll & pitch** without magnetometer (yaw excluded).  

---

## 🚀 How to Use
1. Connect the **BNO055 IMU** to your Arduino via I²C.  
2. Upload this sketch to your board.  
3. Open the Serial Monitor at **9600 baud**.  
4. Tilt/move the sensor and observe smoother **roll & pitch** angle readings compared to raw-only methods.  

---


