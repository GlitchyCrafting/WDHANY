# WDHANY

## Build
Unix Systems with Clang and CMake installed are officially supported
``` bash
chmod +x build.sh
./build.sh
```
Run `./WDHANY` in the `build` directory.
You can also build and run at the same time:
```bash
chmod +x run.sh
./run.sh
```
If ace.js returns 404, copy `src/static/ace` to `build/static/ace`

## The Platform
I created the platform to have the verbosity of W3Schools in the lessons, but in the format of FreeCodeCamp. The UI is built to be minimal using readable fonts, no more "Is this an l, or an I?", and a color scheme that's easy on the eyes. It has an online editor so nothing needs to be installed on the user's computer. It also has a live preview to allow for better learning, visualization is very helpful in design to know what code does what. No account creation is needed as everything is stored in a single cookie, though this may change in the future to allow more options for anyone using the platform.

## Technical Information
The server is written in C++ using the Crow Framework to send web pages and the SqliteModernCPP Library to communicate with the database. The online editor is the Ace Library written in Javascript. The UI uses the Dracula Color Scheme. There is a live preview that uses Javascript Blobs to get code from the editor and display it in an IFrame. It is built with the CMake Build System and the Clang Compiler, both are fully cross-platform to Windows, Mac, and Linux. Only Linux binaries will be included.
