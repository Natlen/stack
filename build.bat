rmdir /S /q "build"
mkdir "build"
cd build
cmake ..
cmake --build .