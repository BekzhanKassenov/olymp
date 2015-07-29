#!/bin/bash
JDK_DIR=/home/sv/wso/jdk1.6.0_27
JRE_DIR=$JDK_DIR/jre

g++ -g -m32 *.cpp -I $JDK_DIR/include/ -I$JDK_DIR/include/linux -I ../../ -L $JRE_DIR/lib/i386/server -ljvm 
$JDK_DIR/bin/javac -XDignore.symbol.file *.java
