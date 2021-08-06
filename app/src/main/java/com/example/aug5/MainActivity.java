package com.example.aug5;

import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothClass;
import android.os.Bundle;
import android.widget.TextView;

import com.example.aug5.databinding.ActivityMainBinding;
// I'm trying to call the NFIQ2 functions from inside the native-cpp file; Therefore not much change here. All the cpp files are stored inside JNILibs folder

public class MainActivity extends AppCompatActivity {

    // Used to load the 'aug5' library on application startup.
    static {
        System.loadLibrary("aug5"); //Importing the native-lib.cpp file
        System.loadLibrary("Nfiq2Api");// Importing the Nfiq2Api.so file
        System.loadLibrary("FRFXLL");   // Importing the FRFXLL.so file
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());

    }

    /**
     * A native method that is implemented by the 'aug5' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

//    NFIQ2::Version::BluetoothClass.Device.Major
//    public native void GetNfiq2Version();       // Try NFIQ2::Version::GetNfiqVersion instead
//    private native void GetNfiq2Version(;
}