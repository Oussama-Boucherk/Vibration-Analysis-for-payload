# Read and reformat data
with open("test.txt") as file:
   lines = file.readlines()
print(lines)

# Convert lines to integers
data = [int(line.strip()) for line in lines if line.strip().isdigit()]
print(data)
# Group data in sets of three for Ax, Ay, Az
structured_data = [(data[i], data[i+1], data[i+2]) for i in range(0, len(data), 3)]
print(structured_data)
# Save to CSV
import csv
with open("vibration_data.csv", "w", newline="") as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(["time","Accel_X", "Accel_Y", "Accel_Z"])  # Headers
    writer.writerows(structured_data)
