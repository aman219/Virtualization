#!/usr/bin/bash
echo "Compiling..."

test -d build/
if [ $? -eq 0 ]; then
    echo "Build directory exists"
else
    echo "Build directory does not exist"
    mkdir build
fi
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
cd ..

./bin/Debug/application