num_rows = int(input("Enter the number of rows"));
for i in range(0, num_rows):
for j in range(0, num_rows-(i-1)):
print(end=" ")
for j in  range(0, i+1):
print("*", end=" ")
print()
