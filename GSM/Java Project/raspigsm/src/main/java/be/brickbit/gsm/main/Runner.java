package be.brickbit.gsm.main;

import be.brickbit.gsm.util.GSMUtil;

public class Runner {
    public static void main(String[] args) {
        GSMUtil.initGSM();
        GSMUtil.sendSMS("0470540890", "Welcome back commander...");
        GSMUtil.sendSMS("0470212323", "Welcome back Morena...Systems booting...Ready to take over the world?");
    }
}
