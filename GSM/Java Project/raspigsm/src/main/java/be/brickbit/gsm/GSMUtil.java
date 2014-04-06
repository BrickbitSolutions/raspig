package be.brickbit.gsm;

public class GSMUtil {
    static { System.loadLibrary("gsmutil"); }
    public static native boolean initGSM();
    public static native String readSMS();
    public static native boolean sendSMS(String phoneNumber, String text);
}