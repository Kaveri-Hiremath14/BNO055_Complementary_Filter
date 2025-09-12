# BNO055_Complementary_Filter
# BNO055 Roll & Pitch Calculation

This project shows how to calculate **roll** and **pitch** angles using raw accelerometer data from the BNO055 sensor.  
The code reads x, y, z acceleration values and applies simple trigonometric formulas to estimate tilt in degrees.  
Results are sent to the Serial Monitor in real time, without using the BNO055’s built-in fusion algorithm.

## Features
- Reads raw accelerometer values from the BNO055  
- Calculates roll (X-axis tilt) and pitch (Y-axis tilt)  
- Updates at ~20 Hz and prints values in degrees  

## Requirements
- Arduino board (e.g., Uno, Mega)  
- Adafruit BNO055 sensor  
- Adafruit BNO055 Arduino library  

## How to Use
1. Clone or download this repository  
2. Open the sketch in Arduino IDE  
3. Install the **Adafruit BNO055** library from Library Manager  
4. Upload the code and open Serial Monitor at 9600 baud  

## Applications
- Quick orientation measurement  
- Learning IMU basics  
- Simple tilt-based projects  
