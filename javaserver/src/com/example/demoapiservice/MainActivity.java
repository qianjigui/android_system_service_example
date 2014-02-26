package com.example.demoapiservice;

import java.lang.reflect.Method;

import android.os.Bundle;
import android.os.IBinder;
import android.app.Activity;
import android.app.Service;
import android.binder.example.IDemoAPI;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.util.Log;
import android.view.Menu;

public class MainActivity extends Activity {
     static final String SERVICE_NAME="android.binder.example";
    @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_main);
            Object object = new Object();
            Method addService;
            try {
                addService = Class.forName("android.os.ServiceManager").getMethod("addService", String.class, IBinder.class);
                addService.invoke(object, new Object[]{SERVICE_NAME, new BnDemoAPI()});
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    @Override
        public boolean onCreateOptionsMenu(Menu menu) {
            getMenuInflater().inflate(R.menu.main, menu);
            return true;
        }

    @Override
        protected void onDestroy() {
            //this.unbindService(serviceConnection);
            super.onDestroy();
        }

}
