## Contributors
* Davis Robertson
* Daniel Wong

## Feature Notes
* All required features should function as described in the spec. 
#### Design Choices: 
* We matched the light and camera positions of the reference solution. 
* Our adaptive tesselation was similar to that of the reference solution. We clamped the multiplier to 1 to 4, scaled based on distance to the wave.
* For phong shading, we have terms for ambient, diffuse, and specular shading, as well as phong interpolation of normals.

## Optional Feature Choices
#### Constant Wireframe Width (5 points):
- We achieved this by passing the vertex positions of the triangles to the fragment shader. We use these to calculate the distance of every fragment to the closest side of the triangle and render a green line if the distance is less than a threshhold. 
- This feature is enabled by default, nothing special must be done to observe it.

#### Projected Cube Shadow (5 points):
- We calculate and display a shadow from the Menger Sponge on the ocean and checkboard floors, based on the light position.
- This feature is enabled by default.

#### Skybox (10 points):
- We load in a cubemap from a folder with 6 `.jpg` files, and render a cube around the eye with the loaded textures.
- To display this feature, specify the command line argument `-c "<folder with cubemap .jpgs>/"`. These cubemap `.jpg`s should match the filename `(pos|neg)[xyz].jpg`.
- You can toggle the cubemap on and off with the "z" key.
- The cubemap only moves when the look direction changes, since it is rendered at infinity.

#### Reflection of Skybox (10 points):
- If the skybox is enabled, our ocean floor can reflect the box.
- To toggle this feature, press the "v" key. Reflection can only be seen when the skybox is enabled.

#### Translucency of Skybox (Original Extra credit):
- If the skybox is enabled, our ocean floor can refract and display the surface behind it. We did not render our polygons with a lower alpha value. Rather, we use refracted secondary rays and modify the color of our fragments based on the color found.
This allows us to warp the water using refraction relative to the normals of waves.
- To toggle this feature, press the "x" key. Refraction also can only be seen when the skybox is enabled. 

