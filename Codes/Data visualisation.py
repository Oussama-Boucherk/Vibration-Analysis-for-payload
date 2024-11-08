import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file into a DataFrame
data = pd.read_csv('vibration_data.csv')

# Extract the acceleration values for each axis
accel_x = data['Accel_X']
accel_y = data['Accel_Y']
accel_z = data['Accel_Z']

# Plot the data
plt.figure(figsize=(10, 6))

plt.subplot(3, 1, 1)
plt.plot(accel_x)
plt.title('X-axis Vibration')
plt.ylabel('Acceleration')

plt.subplot(3, 1, 2)
plt.plot(accel_y)
plt.title('Y-axis Vibration')
plt.ylabel('Acceleration')

plt.subplot(3, 1, 3)
plt.plot(accel_z)
plt.title('Z-axis Vibration')
plt.ylabel('Acceleration')

plt.xlabel('Sample Number')
plt.tight_layout()
plt.show()
