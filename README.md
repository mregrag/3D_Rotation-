# 🧊 Cube3D Rotation

A 3D cube rotation project using the **MLX42** graphics library, 3D-to-2D projection.

---

## 📌 **Table of Contents**
1. [Features](#features)  
2. [Technologies Used](#technologies-used)    
3. [3D Rotation Matrices](#3d-rotation-matrices)  

---

## 🚀 **Features**
- Real-time 3D cube rotation.  
- Rotation around **X**, **Y**, and **Z** axes.  
- Accurate **3D-to-2D projection**.  
- Continuous animation with **MLX42 loop**.  

---

## 🛠️ **Technologies Used**
- **C Programming Language**  
- **MLX42 Graphics Library**  
- **Math Library (`math.h`)**  

---
# 📐 **3D Rotation Matrices**

This section explains the mathematics behind **3D rotation matrices** and how they are applied to rotate points in 3D space around the **X**, **Y**, and **Z** axes. Rotation matrices are fundamental for performing 3D transformations in computer graphics.

---

## 🧠 **What is a Rotation Matrix?**

A **rotation matrix** is a matrix used to perform a **rotation** in Euclidean space. In 3D graphics, it transforms a point in 3D space by rotating it around one of the three principal axes (**X**, **Y**, or **Z**). The rotation is parameterized by an angle of rotation (θ), and each axis has its own corresponding rotation matrix.

### **General Rotation Matrix Formula:**
file:///home/mregrag/Pictures/Screenshots/Screenshot%20from%202024-12-24%2017-56-17.png

For a given 3D point \( P(x, y, z) \), the rotation around a specific axis is represented as a matrix multiplication. The resulting new position of the point after rotation is calculated by multiplying the point by the rotation matrix.

---

## 🧠 **Rotation Around X-Axis:**

When we rotate a point around the **X-axis**, only the **Y** and **Z** coordinates change. The formula for the rotation matrix around the X-axis by an angle \( \theta_x \) is:

\[
R_x(\theta_x) =
\begin{bmatrix}
1 & 0 & 0 \\
0 & \cos(\theta_x) & -\sin(\theta_x) \\
0 & \sin(\theta_x) & \cos(\theta_x)
\end{bmatrix}
\]

### **Rotation Effects:**
- The **X** coordinate remains unchanged.
- The **Y** and **Z** coordinates are adjusted based on the rotation angle.

---

## 🧠 **Rotation Around Y-Axis:**

When we rotate a point around the **Y-axis**, only the **X** and **Z** coordinates change. The rotation matrix for the Y-axis is:

\[
R_y(\theta_y) =
\begin{bmatrix}
\cos(\theta_y) & 0 & \sin(\theta_y) \\
0 & 1 & 0 \\
-\sin(\theta_y) & 0 & \cos(\theta_y)
\end{bmatrix}
\]

### **Rotation Effects:**
- The **Y** coordinate remains unchanged.
- The **X** and **Z** coordinates are modified based on the rotation angle.

---

## 🧠 **Rotation Around Z-Axis:**

When rotating around the **Z-axis**, the **X** and **Y** coordinates are modified, while the **Z** coordinate remains unchanged. The rotation matrix for the Z-axis is:

\[
R_z(\theta_z) =
\begin{bmatrix}
\cos(\theta_z) & -\sin(\theta_z) & 0 \\
\sin(\theta_z) & \cos(\theta_z) & 0 \\
0 & 0 & 1
\end{bmatrix}
\]

### **Rotation Effects:**
- The **Z** coordinate remains unchanged.
- The **X** and **Y** coordinates are adjusted according to the rotation angle.

---

## 🧠 **Combined Rotation (X, Y, Z):**

To perform a rotation around multiple axes, we **combine** the rotation matrices by multiplying them together. The resulting combined rotation matrix \( R \) is the product of the individual rotation matrices for each axis.

\[
R = R_z(\theta_z) \cdot R_y(\theta_y) \cdot R_x(\theta_x)
\]

Where:
- \( R_z(\theta_z) \) is the rotation matrix around the **Z-axis**.
- \( R_y(\theta_y) \) is the rotation matrix around the **Y-axis**.
- \( R_x(\theta_x) \) is the rotation matrix around the **X-axis**.

### **Combining Rotations:**
- The rotation matrices are multiplied in the order of **Z → Y → X**, meaning that we first rotate around the **Z-axis**, then the **Y-axis**, and finally the **X-axis**.
- The combined rotation matrix transforms a point by applying all the rotations in sequence.

---

## 🧠 **Applying Rotation to a 3D Point:**

To rotate a 3D point \( P(x, y, z) \), we apply the rotation matrix to the point as follows:

\[
P' = R \cdot P
\]

Where:
- \( P = (x, y, z) \) is the original point in 3D space.
- \( P' = (x', y', z') \) is the rotated point after applying the rotation matrix.

The result is a new point \( P' \) that has been rotated in 3D space.

---

## 📚 **Example of Combined Rotation:**

If you have a point \( P(1, 2, 3) \) and you want to rotate it by:
- \( 30^\circ \) around the **X-axis**,
- \( 45^\circ \) around the **Y-axis**, and
- \( 60^\circ \) around the **Z-axis**,

you would apply the corresponding rotation matrices \( R_x(30^\circ) \), \( R_y(45^\circ) \), and \( R_z(60^\circ) \) in sequence to the point.

---

## 📝 **Conclusion**

Rotation matrices are essential tools in 3D graphics for rotating objects in 3D space. By combining individual rotations around the **X**, **Y**, and **Z** axes, we can achieve complex 3D transformations and create smooth animations such as the rotating cube in this project.

---

### 📖 **Resources:**
- **Rotation Matrix (Wikipedia):** [Rotation Matrix Documentation](https://en.wikipedia.org/wiki/Rotation_matrix)
- **3D Graphics Basics and Matrix Math:** [Learn OpenGL](https://learnopengl.com)


