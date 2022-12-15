#!/bin/bash

echo "creating build directory"
if [ -d build ]; then
	echo "build directory exists cleaning the contents"
else
	mkdir build
fi
	
echo "Running franca Generator"
cd build
../cgen/commonapi_core_generator/commonapi-core-generator-linux-x86_64 -sk ../fidl/HelloWorld.fidl
../cgen/commonapi_someip_generator/commonapi-someip-generator-linux-x86_64 ../fidl/HelloWorld.fdepl

echo "interface generation done"

cmake ..

make install

echo "done"
