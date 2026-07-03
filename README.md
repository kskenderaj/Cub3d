*This project has been created as part of the 42 curriculum by klejdi*

## Description

cub3D is a 3D graphical representation of a maze viewed from a first-person perspective, learned using ray-casting principles with the miniLibX library. The project demonstrates fundamental computer graphics concepts including ray-sphere intersection, 3D projection, and texture mapping.

The program creates an immersive maze exploration experience where players can navigate through walls with different textures for each cardinal direction (North, South, East, West) and customizable floor and ceiling colors.

## Instructions

### Compilation

```bash
make
```

The Makefile includes the following targets:
- `make all` - Builds the executable
- `make clean` - Removes object files
- `make fclean` - Removes object files and executable
- `make re` - Rebuilds the project

### Execution

```bash
./cub3D maps/your_map.cub
```

### Map Format

Maps must be provided in `.cub` format with the following structure:

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
100N000001
1111111111
```

- **NO/SO/WE/EA**: Texture paths for each wall direction
- **F**: Floor color (R,G,B format, 0-255 each)
- **C**: Ceiling color (R,G,B format, 0-255 each)
- **Map**: Composed of `1` (walls), `0` (empty space), and one spawn position (N/S/E/W)

### Controls

- **W/A/S/D** - Move forward/left/backward/right
- **LEFT/RIGHT ARROW** - Look left/right
- **ESC** - Exit game
- **Window Close Button** - Exit game

## Resources

### Ray-Casting Fundamentals
- [DDA Algorithm](https://en.wikipedia.org/wiki/Digital_differential_analyzer) - Line rasterization technique
- [Raycasting Overview](https://en.wikipedia.org/wiki/Ray_casting) - Core rendering technique
- [Wolfenstein 3D Engine](https://fabiensanglard.net/gebbwolf3d/) - Historical ray-casting implementation

### miniLibX Documentation
- [miniLibX Official](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [MLX Events and Hooks](https://harm-smits.github.io/42docs/libs/minilibx/events.html)

### Graphics & Math
- [3D Rotation Matrices](https://en.wikipedia.org/wiki/Rotation_matrix) - Player rotation implementation
- [Perspective Correction](https://en.wikipedia.org/wiki/Texture_mapping) - Texture coordinate calculation

## AI Usage

AI (Claude) was used for the following:
1. **Raycasting Algorithm** - Helped us learn the complete DDA-based ray-casting engine in `src/render/raycasting.c` including ray-wall intersection detection, perpendicular distance calculation, and wall side determination (North/South/East/West)
2. **Rendering Pipeline** - Helped us build the frame rendering system in `src/render/render.c` with floor/ceiling color drawing, wall height calculation, and texture mapping
3. **Keyboard Controls** - Helped us learn player movement and rotation in `src/render/hooks.c` with collision detection and smooth camera manipulation
4. **Player Initialization** - Helped us set up player state initialization in `src/parsing/player.c` with proper direction vectors and camera plane setup
5. **Graphics Utilities** - Helped us create pixel operations and color handling in `src/render/graphics.c`
6. **Code Structure** - Helped us organize a modular function architecture while adhering to 42 norm standards

The AI focused on supporting our learning of the mathematically intensive rendering systems while maintaining code quality!
