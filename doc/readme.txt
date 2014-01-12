环境
1．python 版本2.7.6
安装：
./configure --enable-shared -enable-unicode=ucs4 --prefix=/usr/local/python2.7
make && make install

cp?/usr/local/python27/lib/libpython2.7.so.1.0?/usr/local/lib
?cd?/usr/local/lib
?ln -s?libpython2.7.so.1.0?libpython2.7.so

#define PYTHON_API_VERSION 1013
#define PYTHON_API_STRING "1013"

http://blog.csdn.net/huzhenwei/article/details/7339548
https://www.rosettacommons.org/node/1901

boost 1.42.0

./bootstrap.sh --prefix=/usr/local --with-icu --with-libraries=python
./bjam install
mv /usr/include/boost/ /usr/include/boost1.33.1
cp -r /usr/local/include/boost/ /usr/include/boost
cp /usr/local/lib/libboost_python.* /usr/lib/
/sbin/ldconfig

http://www.open-abc.com/ccode-206.html
http://blog.csdn.net/marising/article/details/3482719
