/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.example.android.helloactivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.binder.example.IDemoAPI;
import android.util.Log;
import android.os.IBinder;
import android.os.RemoteException;
import java.util.List;
import java.lang.reflect.*;


/**
 * A minimal "Hello, World!" application.
 */
public class HelloActivity extends Activity {
        private IDemoAPI mService;  
        private static final String TAG = "HelloActivity IDemoAPI";
    /**
     * Called with the activity is first created.
     */
    @Override
        public void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            getDemoAPIService();

            // Set the layout for this activity.  You can find it
            // in res/layout/hello_activity.xml
            View view = getLayoutInflater().inflate(R.layout.hello_activity, null);
            setContentView(view);

            try{
                Log.d(TAG, "1+2="+Integer.toString(mService.sum(1,2)));
                Log.d(TAG, "Name="+mService.getName());
                Log.d(TAG, "FullName="+mService.getFullName("AAABBBCCC"));
            }catch(Exception e){
                Log.d(TAG,e.toString());
            }
        }

    static final String SERVICE_NAME="android.binder.example";

    /*
     * Get binder service
     */
    private void getDemoAPIService()
    {
        IBinder binder=null;
        Log.d(TAG,"getDemoAPIService");
        try{
            //android.os.ServiceManager is hide class, we can not invoke them from SDK. So we have to use reflect to invoke these classes.
            Object object = new Object();
            Method getService = Class.forName("android.os.ServiceManager").getMethod("getService", String.class);
            Object obj = getService.invoke(object, new Object[]{new String(SERVICE_NAME)});
            binder = (IBinder)obj;
        }catch(Exception e){
            Log.d(TAG, e.toString());
        }
        if(binder != null){
            mService = IDemoAPI.Stub.asInterface(binder);
            Log.d(TAG, "Find binder");
        }
        else
            Log.d(TAG,"Service is null.");
    }

}

