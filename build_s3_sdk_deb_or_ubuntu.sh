cd ~/aws-sdk-cpp && mkdir -p sdk_build

yes | sudo hwclock --hctosys && yes | sudo apt update && yes | sudo apt upgrade && yes | sudo apt install curl && yes | sudo apt-get install libcurl4-openssl-dev libssl-dev uuid-dev zlib1g-dev libpulse-dev

cd ~/aws-sdk-cpp/sdk_build && cmake ../ -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DFORCE_SHARED_CRT=OFF -DUSE_CRT_HTTP_CLIENT=ON -DCMAKE_PREFIX_PATH=/usr/local/ -DCMAKE_INSTALL_PREFIX=/usr/local/ -DENABLE_TESTING=OFF -DBUILD_ONLY="s3"

cd ~/aws-sdk-cpp/sdk_build && make

cd ~/aws-sdk-cpp/sdk_build && sudo make install
