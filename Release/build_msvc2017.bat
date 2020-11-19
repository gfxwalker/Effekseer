mkdir build_msvc2017(x64)
cd build_msvc2017(x64)
cmake -G "Visual Studio 15 2017" -DCMAKE_GENERATOR_PLATFORM=x64 -DCMAKE_INSTALL_PREFIX=../install_msvc2017(x64) -DUSE_LLGI=ON -DBUILD_DX12=ON .. -DCMAKE_DEBUG_POSTFIX=.Debug -DCMAKE_RELEASE_POSTFIX=.Release -DCMAKE_COMPILE_PDB_OUTPUT_DIRECTORY=../../../install_msvc2017(x64) -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ture
cmake --build . --config Release --target INSTALL
cmake --build . --config Debug --target INSTALL

cd ../
mkdir build_msvc2017(x86)
cd build_msvc2017(x86)
cmake -G "Visual Studio 15 2017" -DCMAKE_INSTALL_PREFIX=../install_msvc2017(x86) -DUSE_LLGI=ON -DBUILD_DX12=ON .. -DCMAKE_DEBUG_POSTFIX=.Debug -DCMAKE_RELEASE_POSTFIX=.Release  -DCMAKE_COMPILE_PDB_OUTPUT_DIRECTORY=../../../install_msvc2017(x86) -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ture
cmake --build . --config Release --target INSTALL
cmake --build . --config Debug --target INSTALL

