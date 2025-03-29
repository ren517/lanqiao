a = 1
b = 0
for i in range(1,41):
    a = 1
    for j in range(1,i+1):
        a *= j
    b += a
print(b)