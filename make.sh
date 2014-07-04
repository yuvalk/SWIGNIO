swig -c++ -java -package org.kashyoo.swigexample -outdir java swig.i
g++ -c swig_wrap.cxx impl.cpp -I/usr/lib/jvm/java-7-openjdk-amd64/include -I/tmp/poco/include -fPIC
gcc -shared impl.o swig_wrap.o -o libexample.so -fPIC -L/tmp/poco/lib -lPocoFoundation -lPocoUtil
javac java/Monitor.java java/IFrameCB.java java/example.java java/exampleJNI.java MainExample.java
