$ gcc -fPIC -c ex_TTYUtil.c -I $JAVA_HOME/include
$ gcc ex_TTYUtil.o -shared -o libttyutil.so -Wl,-soname,ttyutil

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