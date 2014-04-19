package be.brickbit.gsm.main;

import be.brickbit.gsm.util.GSMUtil;

import java.util.Scanner;

public class Runner {
    public static void main(String[] args) throws InterruptedException {
        Scanner in = new Scanner(System.in);

        while(true){
            switch (in.next()){
                case "init":
                    init();
                    break;
                case "send":
                    send();
                    break;
                case "read":
                    read();
                    break;
                case "quit":
                    return;
                default:
                    System.out.println("-----COMMAND INVALID-----");
            }
        }
    }

    private static void send() {
        System.out.println("-----SENDING TEXT MSG-----");
        System.out.println("Message Send Status: " + GSMUtil.sendSMS("0470540890", "Welcome back commander..."));
        System.out.println("-----SENDING DONE-----");
    }

    private static void init() {
        System.out.println("-----INIT GSM MODULE-----");
        System.out.println("Init Status: " + GSMUtil.initGSM());
        System.out.println("-----INIT DONE-----");
    }

    private static void read() {
        System.out.println("-----READING-----");
        System.out.println("Result: "+GSMUtil.readSMS());
        System.out.println("-----READING DONE-----");
    }
}
