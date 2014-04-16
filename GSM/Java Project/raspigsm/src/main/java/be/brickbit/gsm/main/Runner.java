package be.brickbit.gsm.main;

import be.brickbit.gsm.util.GSMUtil;

public class Runner {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("-----INIT GSM MODULE-----");
        //System.out.println("Init Status: " + GSMUtil.initGSM());
        Thread.sleep(50000);
        System.out.println("-----SENDING TEXT MSG-----");
        System.out.println("Message Send Status: " + GSMUtil.sendSMS("0470540890", "Welcome back commander..."));
        System.out.println("-----DONE-----");
        //GSMUtil.sendSMS("0470212323", "Welcome, Morena...Systems booting...Ready to take over the world?");
    }
}
