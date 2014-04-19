Tuts: 

http://jonisalonen.com/2012/calling-c-from-java-is-easy/
http://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html
http://www.cooking-hacks.com/documentation/tutorials/raspberry-pi-to-arduino-shields-connection-bridge#step4 

https://github.com/lurch/rpi-serial-console

g++ -fPIC be_brickbit_gsm_GSMUtil.cpp arduPi.cpp -I /usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/ -I /usr/lib/jvm/jdk-8-oracle-arm-vfp-hflt/include/linux -shared -o gsmutil.so -Wl,-soname,gsmutil

import ex.TTYUtil;
public class Test {
    public static void main(String[] args) {
        if (TTYUtil.isTTY()) {
            System.out.println("TTY: "+TTYUtil.getTTYName());
        } else {
            System.out.println("Not a TTY");
        }
    }
}