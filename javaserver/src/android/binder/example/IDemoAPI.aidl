package android.binder.example;

/**
 * AIDL file for Binder API generating
 *
 */

interface IDemoAPI{
    String getName();
    String getFullName(String part);
    int sum(int a,int b);
}
