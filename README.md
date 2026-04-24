# Taif University - Main Street Scene
## Computer Graphics Project | CG Course | Taif University

---

## Project Description

This project recreates the main street scene of Taif University using 2D graphics built with OpenGL and C++. The scene includes a university building, street lights, trees, decorative pots, and an interactive cat walking along the road. The scene supports day and night mode, an animated cat, and an interactive door.

---

## Landmark

**Location:** Main Street — Taif University Campus  
**Style:** Creative (simplified and stylized)

---

## How to Run

1. Open Visual Studio
2. Create a new Empty C++ Project
3. Add `taif_university.cpp` to Source Files
4. Link the following libraries via Project Properties → Linker → Input:
   ```
   opengl32.lib
   glu32.lib
   freeglut.lib
   ```
5. Place `freeglut.dll` in the project folder
6. Press **Ctrl + F5** to run

---

## Controls

| Key | Action |
|-----|--------|
| `D` | Toggle Day / Night mode |
| `← →` Arrow Keys | Move the cat left and right |
| `SPACE` | Open / Close the building door |

---

## Scene Elements

| Element | Description |
|---------|-------------|
| Sky | Changes between day (blue) and night (dark) |
| Sun / Moon | Sun appears in day, crescent moon and stars at night |
| Building | Cream-colored university block with windows, door, columns, and steps |
| Street Lights | Three poles with lamps that glow yellow at night |
| Trees | Two round-canopy trees near the building |
| Plant Pots | Two decorative pots at the building entrance |
| Cat | A small cat that walks along the road |

---

## Team Members & Individual Contributions

| # | Name | Object | File |
|---|------|--------|------|
| 1 | RAGHAD ALBLAHDI | Sky + Interaction System | `student1_sky_interaction.cpp` |
| 2 | Student 2 | Main Building Body & Roof | `student2_building_body.cpp` |
| 3 | Student 3 | Windows (3×2 grid) | `student3_windows.cpp` |
| 4 | Student 4 | Door, Columns & Steps | `student4_door_columns.cpp` |
| 5 | Student 5 | Street Lights | `student5_streetlight.cpp` |
| 6 | Student 6 | Trees & Plant Pots | `student6_trees_pots.cpp` |
| 7 | Student 7 | Ground, Road & Kerb | `student7_ground.cpp` |
| 8 | Student 8 | Cat | `student8_cat.cpp` |

---

## Technologies Used

- Language: **C++**
- Graphics Library: **OpenGL (freeglut)**
- IDE: **Visual Studio**
- Primitives used: `GL_QUADS`, `GL_TRIANGLES`, `GL_TRIANGLE_FAN`, `GL_QUAD_STRIP`

---

## Project Structure

```
TaifUniversity-CG-Project/
│
├── taif_university.cpp          ← Full combined scene
├── student1_sky_interaction.cpp 
├── student2_building_body.cpp
├── student3_windows.cpp
├── student4_door_columns.cpp
├── student5_streetlight.cpp
├── student6_trees_pots.cpp
├── student7_ground.cpp
├── student8_cat.cpp
└── README.md
```

---

## Course Information

- **Course:** Computer Graphics
- **University:** Taif University


---

> *All code is original and written by the team members.*# TaifUniversity-CG-Project
