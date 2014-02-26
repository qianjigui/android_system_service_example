package com.example.demoapiservice;

import android.binder.example.IDemoAPI;
import android.os.RemoteException;

public class BnDemoAPI extends IDemoAPI.Stub {
    
    @Override
    public String getName() throws RemoteException {
        return "DemoAPI";
    }
    
    @Override
    public String getFullName(String part) throws RemoteException {
        StringBuilder builder = new StringBuilder("DemoAPI+");
        builder.append(part);
        return builder.toString();
    }
    
    @Override
    public int sum(int a, int b) throws RemoteException {
        return a + b;
    }
    
}
