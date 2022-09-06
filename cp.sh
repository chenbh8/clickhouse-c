cd build
# export CXX=/opt/rh/devtoolset-8/root/usr/bin/g++
# export CC=/opt/rh/devtoolset-8/root/usr/bin/gcc
# export CC=/usr/bin/gcc
make
make install
cp  ./clickhouse/libclickhouse-cpp-lib.so /usr/lib64/libclickhouse-cpp-lib.so