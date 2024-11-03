cd ~/aws-sdk-cpp && mkdir -p sdk_build

yes | sudo hwclock --hctosys && yes | sudo apt update && yes | sudo apt upgrade && yes | sudo apt install curl && yes | sudo apt-get install libcurl4-openssl-dev

cd ~/aws-sdk-cpp/sdk_build && cmake ../ -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DFORCE_SHARED_CRT=OFF -DCMAKE_PREFIX_PATH=/usr/local/ -DCMAKE_INSTALL_PREFIX=/usr/local/ -DENABLE_TESTING=OFF -DBUILD_ONLY="s3"

cd ~/aws-sdk-cpp/sdk_build && make

cd ~/aws-sdk-cpp/sdk_build && sudo make install
