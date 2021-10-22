import numpy as np
import matplotlib.pyplot as plt

pts = 40000

u = np.linspace(0, np.pi, pts)
v = np.linspace(0, 2 * np.pi, pts)

np.random.shuffle(u)
np.random.shuffle(v)

x = np.sin(u) * np.cos(v)
y = np.sin(u) * np.sin(v)
z = np.cos(u)

x_out = -2 * x + y + 2 * z
y_out = 2 * y

plt.plot(x_out, y_out, 'o')
plt.show()


