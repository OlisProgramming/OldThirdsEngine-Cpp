# ThirdsEngine
A 3D OpenGL Game Engine.

# Building
To build the project (on Linux), use the supplied `makefile`. `*.o` files will be placed in the `build/` directory, with a linked executable in the main directory.

# Utilities
To count the lines of code in the project (or your own fork of the project) run `cloc.sh`. It will output, on a file-by-file basis, the amount of lines of C++ and GLSL code there are in the containing directory, and then finally a total number of lines. It detects these files using an extension filter of `*.cpp`, `*.h` and `*.glsl`, so if you use for example the `*.hpp` extension for header files, `cloc.sh` will not count them as code files. Furthermore, `cloc.sh` does not exclude blank lines or comment lines.

# Credits
Inspired by [TheBennyBox's tutorial series](https://www.youtube.com/watch?v=ss3AnSxJ2X8&list=PLEETnX-uPtBXP_B2yupUKlflXBznWIlL5), with [Github repository here](https://www.github.com/bennyqbd/3dgameengine). Some base code was used from the ["Hello Triangle"](http://antongerdelan.net/opengl/hellotriangle.html) tutorial project.
