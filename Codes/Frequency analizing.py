import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq

# Load the CSV file into a DataFrame
data = pd.read_csv('vibration_data.csv')

# Extract the acceleration values for each axis
accel_x = data['Accel_X']
accel_y = data['Accel_Y']
accel_z = data['Accel_Z']

# Calculate the magnitude of the vibration vector at each sample
vibration_magnitude = np.sqrt(np.square(accel_x) + np.square(accel_y) + np.square(accel_z))

# Convert vibration magnitude to a numpy array explicitly
vibration_magnitude = np.array(vibration_magnitude)

# Plot the combined vibration magnitude
plt.figure(figsize=(10, 6))
plt.plot(vibration_magnitude)
plt.title('Combined Vibration Magnitude')
plt.xlabel('Sample Number')
plt.ylabel('Magnitude')
plt.grid(True)
plt.show()

# Frequency Analysis (FFT)
N = len(vibration_magnitude)
T = 0.01  # Sampling interval in seconds (adjust if necessary)
yf = fft(vibration_magnitude)
xf = fftfreq(N, T)[:N//2]

# Plot the frequency spectrum of the combined vibration
plt.figure(figsize=(10, 6))
plt.plot(xf, 2.0 / N * np.abs(yf[:N // 2]))  # Normalized magnitude
plt.title('Frequency Spectrum of Combined Vibration')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude')
plt.grid(True)
plt.show()
