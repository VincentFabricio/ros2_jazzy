import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import StateSpace, lsim, place_poles

# Physical parameters
m = 0.3      # kg
L = 0.3      # m
b = 0.1      # damping
g = 9.81     # gravity
I = m * L**2 # moment of inertia

# State-space matrices
A = np.array([[0, 1],
              [-m * g * L / I, -b / I]])
B = np.array([[0],
              [1 / I]])
C = np.array([[1, 0]])
D = np.array([[0]])

# Create system
system = StateSpace(A, B, C, D)

# Time vector
t = np.linspace(0, 10, 500)

# Input torque (step input)
u = np.ones_like(t) * 1.0  # constant torque

# Initial state [theta, theta_dot]
x0 = [0.0, 0.0]

# Simulate
t_out, y_out, x_out = lsim(system, U=u, T=t, X0=x0)

# Plot
plt.figure()
plt.plot(t_out, y_out)
plt.xlabel('Time [s]')
plt.ylabel('Angle θ [rad]')
plt.title('1-DOF Arm Response to Step Torque')
plt.grid()
plt.show(block=False)
plt.savefig("plot1.png")


# Desired poles (stable and fast enough)
desired_poles = [-2.0, -18.5]

# Compute K
place_obj = place_poles(A, B, desired_poles)
K = place_obj.gain_matrix

print("K1 =", K[0, 0])
print("K2 =", K[0, 1])

# Closed-loop system
A_cl = A- B*K

# Create closed-loop system
system_cl = StateSpace(A_cl, B * 0, C, D)  # No external input

# Time vector
t = np.linspace(0, 10, 500)

# Initial state [theta, theta_dot]
x0 = [0.0, 0.0]  # small initial angle

# Reference gain (assume full-state feedback, no observer)
N = np.array([[1]])  # You can tune this later

# Modified input matrix for reference tracking
B_ref = B @ N

# New system with reference input
system_cl = StateSpace(A_cl, B_ref, C, D)

#References
r = np.ones_like(t) * (np.pi / 2)  # step to π/2 radians

#Simulate close-loop
t_out, y_out, x_out = lsim(system_cl, U=r, T=t, X0=x0)

#Plot2
plt.figure()
plt.plot(t_out, y_out, label='θ(t)')
plt.axhline(np.pi/2, color='r', linestyle='--', label='Reference π/2')
plt.xlabel('Time [s]')
plt.ylabel('Angle θ [rad]')
plt.title('Closed-Loop SS Response to Step Reference π/2')
plt.legend()
plt.grid()
plt.show(block=False)
plt.savefig("plot2.png")

A_aug = np.block([
    [A,           np.zeros((2,1))],
    [-C,          np.zeros((1,1))]
])

B_aug = np.vstack([B, [[0]]])

desired_poles = [-2.0, -5.0, -10.0]  # Add one more pole for integral

place_obj = place_poles(A_aug, B_aug, desired_poles)
K_aug = place_obj.gain_matrix
print("Ks aug =", K_aug)
print("K1 aug =", K_aug[0, 0])
print("K2 aug =", K_aug[0, 1])
print("KC aug =", K_aug[0, 2])
# Closed-loop system
A_cl = A- B*K

# Time vector
t = np.linspace(0, 10, 500)

# Initial state [theta, theta_dot]
x0 = [0.0, 0.0]  # small initial angle

# Reference gain (assume full-state feedback, no observer)
N = np.array([[1]])  # You can tune this later

# Modified input matrix for reference tracking
B_ref = B @ N

# New system with reference input
system_cl = StateSpace(A_cl, B_ref, C, D)

#References
r = np.ones_like(t) * (np.pi / 2)  # step to π/2 radians

#Simulate close-loop
t_out, y_out, x_out = lsim(system_cl, U=r, T=t, X0=x0)

#Plot2
plt.figure()
plt.plot(t_out, y_out, label='θ(t)')
plt.axhline(np.pi/2, color='r', linestyle='--', label='Reference π/2')
plt.xlabel('Time [s]')
plt.ylabel('Angle θ [rad]')
plt.title('Closed-Loop SS with Integral Response to Step Reference π/2')
plt.legend()
plt.grid()
plt.show(block=False)
plt.savefig("plot3.png")
