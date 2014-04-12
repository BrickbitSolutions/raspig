Tuts: 

http://jonisalonen.com/2012/calling-c-from-java-is-easy/
http://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html

$ g++ -fPIC -c be_brickbit_gsm_GSMUtil.cpp -I $JAVA_HOME/include -I $JAVA_HOME/include/darwin
$ g++ be_brickbit_gsm_GSMUtil.o -shared -o libgsmutil.so -Wl,-soname,gsmutil

g++ -Wl,--add-stdcall-alias -I $JAVA_HOME/include -I $JAVA_HOME/include/darwin -shared -o gsmutil.so be_brickbit_gsm_GSMUtil.cpp

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