mkdir -p build
cd build
if [ "$1" == "DEBUG" ] 
then
    cmake ../src/ -DPROJ_BUILD_TYPE=DEBUG
elif [ "$1" == "RELEASE" ]
then
    cmake ../src/ -DPROJ_BUILD_TYPE=RELEASE
else
    echo "@ Building emulator in debug mode... @"
    cmake ../src/ -DPROJ_BUILD_TYPE=DEBUG
fi

make -j16
