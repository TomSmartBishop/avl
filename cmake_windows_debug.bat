if not exist "build" mkdir build
cd build && cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Debug .. && make > windows_debug_build.log 2>&1
type windows_debug_build.log
cd ..