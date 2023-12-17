import random

file = open("data.csv", "w")
for i in range(10000):
    file.write(str(random.randint(100,999)) + "," + str(i) + "\n")
file.close()
