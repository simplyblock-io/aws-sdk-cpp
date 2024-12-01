cd ~/aws-sdk-cpp && mkdir -p sdk_build

yes | sudo yum update && yes | sudo yum upgrade && yes | sudo yum install curl && yes | sudo yum install libcurl-devel openssl-devel libuuid-devel pulseaudio-libs-devel

cd ~/aws-sdk-cpp/sdk_build && cmake ../ -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=OFF -DFORCE_SHARED_CRT=OFF -DUSE_CRT_HTTP_CLIENT=ON -DCMAKE_PREFIX_PATH=/usr/local/ -DCMAKE_INSTALL_PREFIX=/usr/local/ -DENABLE_TESTING=OFF -DBUILD_ONLY="s3"

cd ~/aws-sdk-cpp/sdk_build && make

cd ~/aws-sdk-cpp/sdk_build && sudo make install
