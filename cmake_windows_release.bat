if not exist "build" mkdir build
cd build && cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release .. && make > windows_release_build.log 2>&1
type windows_release_build.log
cd ..