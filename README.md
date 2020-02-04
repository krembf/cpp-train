# cpp-train

### Build steps (Ubuntu)
```sh
mkdir build
cd build
cmake ..
cmake --build .
```

### Configuration steps (Windows) TBD
- Install mingw-w64 (http://mingw-w64.org/doku.php/download)
- Download and Install cmake (https://cmake.org/download/)
- Optionally, follow instructions from here (https://vector-of-bool.github.io/docs/vscode-cmake-tools/getting_started.html)


### Build steps (Windows) TBD
uses mingw64
```sh

```

### Troubleshooting mingw-w64 isues on Windows
- Configure using this link: https://code.visualstudio.com/docs/cpp/config-mingw
- For threading and mutexes, posix threading version of mingw-w64 must be selected (see https://stackoverflow.com/questions/14191566/c-mutex-in-namespace-std-does-not-name-a-type)
- To reset the kits collection, delete C:\Users\<username>\AppData\Local\CMakeTools\cmake-tools-kits.json and restart VSCode.