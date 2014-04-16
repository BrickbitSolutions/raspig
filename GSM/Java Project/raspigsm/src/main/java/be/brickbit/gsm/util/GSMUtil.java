package be.brickbit.gsm.util;

import java.io.File;

public class GSMUtil {
    static {
        System.load(new File("gsmutil.so").getAbsolutePath());
    }
    public static native boolean initGSM();
    public static native String readSMS();
    public static native boolean sendSMS(String phoneNumber, String text);
}