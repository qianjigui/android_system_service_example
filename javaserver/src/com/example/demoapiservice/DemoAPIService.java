package com.example.demoapiservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

public class DemoAPIService extends Service{
    
    private IBinder binder;
    public static final String SERVICE_NAME = "android.binder.example";

    public DemoAPIService() {
        super();
    }
    
    @Override
    public void onCreate() {
        super.onCreate();
        this.binder = new BnDemoAPI();
    }
    
    @Override
    public IBinder onBind(Intent intent) {
        return this.binder;
    }

}

