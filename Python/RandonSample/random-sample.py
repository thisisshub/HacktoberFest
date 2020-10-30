import random

objects = []
for count in range(0, 100):
    objects.append(
            {
                "id": count,
                "description": ("number: " + str(count)),
            }
        )
print(random.sample(objects, 4))